# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 03:04:00 by abaurens          #+#    #+#              #
#    Updated: 2018/07/25 23:40:43 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq

SRC			=	bsq.c			\
				math.c			\
				main.c			\
				file.c			\
				print.c			\
				errors.c		\
				parsing.c		\
				s_string.c		\
				m_string.c		\
				parsing_utils.c

OBJ			=	$(SRC:.c=.o)

INCLUDE		=	-I./include

CFLAGS		+=	$(INCLUDE) -W -Wall -Wextra -ansi -pedantic -Werror

LDFLAGS		+=	#linkage flag

RM			=	rm -rf

CC			=	gcc

LINKER		=	gcc

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
