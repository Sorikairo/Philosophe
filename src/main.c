/*
** main.c for philo in /home/fouhet_k/Perso/PSU_2014_philo/src
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Feb 23 11:23:44 2015 kevin fouhety
** Last update Thu Feb 26 08:29:43 2015 Thomas CRUVEILHER
*/

#include "philo.h"

int		main()
{
  t_philo	*philo;

  if ((philo = init_philo()) == NULL)
    return (-1);
  create_thread(philo);
  wait_thread(philo);
  return (0);
}
