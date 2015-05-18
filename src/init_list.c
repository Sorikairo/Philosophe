/*
** main.c for philo in /home/fouhet_k/Perso/PSU_2014_philo/src
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Feb 23 11:23:44 2015 kevin fouhety
** Last update Sun Mar  1 08:54:22 2015 kevin fouhety
*/

#include "philo.h"

void		add_elem_list(t_philo **list, int nb)
{
  t_philo	*tmp;
  int		i;

  tmp = *list;
  i = 0;
  while (i < nb)
    {
      tmp = tmp->next;
      i++;
    }
  if (nb != 0)
    {
      tmp->next = *list;
      (*list)->prev = tmp;
    }
  i = 0;
}

void		*print_error(int mut, int cond)
{
  if (mut != 0)
    ERROR("error on pthread_mutex_init\n");
  if (cond != 0)
    ERROR("error on pthread_cond_init\n");
  exit(1);
}

t_philo		*xmalloc(int size)
{
  t_philo	*tmp;

  if ((tmp = malloc(size)) == NULL)
    {
      ERROR("error on malloc int init_philo\n");
      exit(1);
    }
  return (tmp);
}

void		init_elem(t_philo **list, int i)
{
  t_philo	*tmp;
  int		mut;
  int		cond;

  tmp = xmalloc(sizeof (t_philo));
  mut = pthread_mutex_init(&tmp->chopstick, NULL);
  cond = pthread_cond_init(&tmp->cond, NULL);
  if (mut != 0 || cond != 0)
    print_error(mut, cond);
  tmp->nb_riz = NB_RIZ;
  tmp->state = SLEEP;
  tmp->philoNb = i;
  tmp->eaten = 0;
  if (*list != NULL)
    {
      tmp->next = *list;
      tmp->next->prev = tmp;
    }
  else
    tmp->next = NULL;
  tmp->prev = NULL;
  *list = tmp;
}

t_philo		*init_philo()
{
  t_philo	*ret;
  int		i;

  i = 0;
  ret = NULL;
  while (i < NB_PHILO)
    {
      init_elem(&ret, i);
      add_elem_list(&ret, i);
      i++;
    }
  return (ret);
}
