# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 03:04:00 by abaurens          #+#    #+#              #
#    Updated: 2025/01/03 01:55:46 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC  = bsq.c     \
       main.c    \
       print.c   \
       utils.c   \
       loading.c \
       errors.c

OBJ     = $(SRC:.c=.o)

INCLUDE = -I./include

CFLAGS  +=  $(INCLUDE) -W -Wall -Wextra -ansi -pedantic -Werror -O3

LDFLAGS +=  #linkage flag

RM      = rm -rf

CC      = gcc

LINKER  = gcc

$(NAME):	$(OBJ)
	$(LINKER) -o $(NAME) $(LDFLAGS) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME).dSYM

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
