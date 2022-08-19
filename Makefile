# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 13:31:32 by bkristen          #+#    #+#              #
#    Updated: 2022/01/04 17:42:34 by bkristen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIST =		ft_itoa.c \
			ft_printf_utils.c \
			ft_printf.c \
			ft_itoa_d.c \
			ft_itoa_u.c

OBJ = $(LIST:.c=.o)

HEADER = ft_printf.h

RM = rm -rf

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJ)
		ar crs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re


























