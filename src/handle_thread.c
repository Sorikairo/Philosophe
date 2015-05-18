/*
** main.c for philo in /home/fouhet_k/Perso/PSU_2014_philo/src
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Feb 23 11:23:44 2015 kevin fouhety
** Last update Sun Mar  1 08:48:04 2015 kevin fouhety
*/

#include "philo.h"

int		is_empty(t_philo *philo)
{
  int		i;
  t_philo	*tmp;

  i = 0;
  tmp = philo;
  while (i < NB_PHILO)
    {
      if (tmp->nb_riz != 0)
	return (1);
      i++;
      tmp = tmp->next;
    }
  return (0);
}

void		create_thread(t_philo *list)
{
  t_philo	*tmp;
  int		i;

  tmp = list;
  i = 0;
  while (i < NB_PHILO)
    {
      pthread_create(&tmp->id, NULL, &starting_philo, tmp);
      tmp = tmp->next;
      i++;
    }
  wait_thread(list);
  tmp = list;
  i = 0;
  while (i < NB_PHILO)
    {
      pthread_create(&tmp->id, NULL, &working_philo, tmp);
      tmp = tmp->next;
      i++;
    }
}

void		wait_thread(t_philo *list)
{
  t_philo	*tmp;
  int		i;
  void		*res;

  tmp = list;
  i = 0;
  while (i < NB_PHILO)
    {
      pthread_join(tmp->id, &res);
      tmp = tmp->next;
      i++;
    }
}
