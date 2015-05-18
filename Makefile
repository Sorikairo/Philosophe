##
## Makefile for phil in /home/fouhet_k/Perso/PSU_2014_philo
## 
## Made by kevin fouhety
## Login   <fouhet_k@epitech.net>
## 
## Started on  Mon Feb 23 11:15:56 2015 kevin fouhety
## Last update Mon Feb 23 15:14:25 2015 kevin fouhety
##

CC		=	cc

RM		=	rm -f

NAME		=	philo

PATH_SRC	=	./src/

CFLAGS		=	-Wextra -Wall -Werror -ansi -pedantic -I./header/

LDFLAGS		=	-lpthread

SRC		=	$(PATH_SRC)main.c \
			$(PATH_SRC)init_list.c \
			$(PATH_SRC)handle_thread.c \
			$(PATH_SRC)philosophes.c

OBJ		=	$(SRC:.c=.o)


all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
