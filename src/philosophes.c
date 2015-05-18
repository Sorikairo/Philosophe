/*
** philosophes.c for philo in /home/fouhet_k/Perso/PSU_2014_philo/src
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Feb 23 15:12:18 2015 kevin fouhety
** Last update Sun Mar  1 08:53:41 2015 kevin fouhety
*/

#include "philo.h"

void		eat(t_philo *philo)
{
  philo->eaten = 1;
  printf("Je suis le %d, je mange\n", philo->philoNb);
  sleep(TIME_EAT);
  pthread_mutex_unlock(&philo->chopstick);
  pthread_mutex_unlock(&philo->next->chopstick);
  philo->nb_riz--;
}

void		think(t_philo *philo, pthread_mutex_t *mutex)
{
  philo->thought = 1;
  printf("Je suis le %d, je pense\n", philo->philoNb);
  sleep(TIME_THINK);
  pthread_mutex_unlock(mutex);
}

void		dosleep(t_philo *philo)
{
  philo->eaten = 0;
  philo->thought = 0;
  printf("Je suis le %d, je dors\n", philo->philoNb);
  sleep(TIME_EAT);
}

void		*starting_philo(void *arg)
{
  t_philo	*philo;

  philo = arg;
  if (pthread_mutex_trylock(&philo->chopstick) == 0)
    if (pthread_mutex_trylock(&philo->next->chopstick) == 0)
      eat(philo);
    else
      think(philo, &philo->chopstick);
  else 
    think(philo, &philo->next->chopstick);
  return (NULL);
}

void		*working_philo(void *arg)
{
  t_philo       *philo;
  
  philo = arg;
  while(philo->nb_riz != 0)
    if (philo->eaten == 0)
      {
	if (pthread_mutex_trylock(&philo->chopstick) == 0)
	  {
	    if (philo->thought == 1 &&
		pthread_mutex_trylock(&philo->next->chopstick) == 0)
	      eat(philo);
	    else if (philo->thought == 0)
	      think(philo, &philo->chopstick);
	    else
	      pthread_mutex_unlock(&philo->chopstick);
	  }
	else if (philo->thought == 0 &&
		 pthread_mutex_trylock(&philo->next->chopstick) == 0)
	  think(philo, &philo->next->chopstick);
      }
    else
      dosleep(philo);
  printf("Je suis le %d et j'ai fini !!\n", philo->philoNb);
  return (NULL);
}
