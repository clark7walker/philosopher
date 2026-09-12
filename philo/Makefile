# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/13 17:13:30 by cltan             #+#    #+#              #
#    Updated: 2026/09/12 18:08:02 by cltan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
COMPILER	=	cc
CFLAGS		=	-Wall -Wextra -Werror -I includes
HEADER		=	includes/philo.h
SRC_FILES	=	src/main.c src/utils.c src/validation.c \
				src/init.c src/simulation.c src/monitor.c \
				src/routine.c
OBJ_FILES	=	$(SRC_FILES:%.c=%.o)

%.o:%.c $(HEADER)
	$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	$(COMPILER) $(CFLAGS) $(OBJ_FILES) -o $(NAME) -lpthread

.PHONY : all clean fclean re

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all