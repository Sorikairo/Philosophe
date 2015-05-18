/*
** philo.h for philo in /home/fouhet_k/Perso/PSU_2014_philo
** 
** Made by kevin fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Feb 23 10:58:02 2015 kevin fouhety
** Last update Sun Mar  1 00:05:45 2015 Thomas CRUVEILHER
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define NB_PHILO 7
# define TIME_THINK 4
# define TIME_EAT 2
# define NB_RIZ	10
# define ERROR(str) {write(2, str, strlen(str));}

enum state {THINK, EAT, SLEEP};

typedef struct s_philo
{
  pthread_t		id;
  pthread_mutex_t	chopstick;
  pthread_cond_t 	cond;
  char			eaten;
  char			thought;
  int			philoNb;
  int			nb_riz;
  enum state		state;
  struct s_philo	*next;
  struct s_philo	*prev;
}			t_philo;

 /* init list philo */

t_philo			*init_philo();
void			init_elem(t_philo **list, int i);
void			add_elem_list(t_philo **list, int nb);

/* create and wait thread */

void			create_thread(t_philo *list);
void			wait_thread(t_philo *list);

/* check if end */

int			is_empty(t_philo *list);

/* Philosophes */

void			*starting_philo(void *arg);
void			*working_philo(void *arg);

#endif
