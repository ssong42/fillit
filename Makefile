# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 19:40:55 by ttran             #+#    #+#              #
#    Updated: 2018/02/19 18:20:17 by ssong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Werror -Wextra
CC = gcc
SRCS = ./
INCLUDE = ./
FILES = main checkfill checkfill2 backtracking parsefill miscfill printgrid mallocgrid

CFILES = $(patsubst %, $(SRCS)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))

all: $(NAME)

$(OFILES):
	$(CC) $(FLAGS) -c -I$(INCLUDE) $(CFILES)

$(NAME): $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

clean:
	@/bin/rm -f $(OFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
