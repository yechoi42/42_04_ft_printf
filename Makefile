# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/29 21:09:13 by yechoi            #+#    #+#              #
#    Updated: 2020/05/02 17:13:25 by yechoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_printf.c parse.c sub_print.c utils.c\
			  print_diu.c print_xp.c print_cspct.c
OBJS		= $(SRCS:.c=.o)
HEADER		= ./
FLAG		= -Wall -Wextra -Werror

.c.o:
	gcc $(FLAG) -c $< -o $(<:.c=.o) -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
