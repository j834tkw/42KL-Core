# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:28:04 by jutong            #+#    #+#              #
#    Updated: 2022/12/08 12:41:40 by jutong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printchar.c ft_printhex.c ft_printint.c ft_printptr.c \
			ft_printstr.c ft_printui.c \

OBJS	= $(SRCS:.c=.o)

SRCSH	= ft_printf.h

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) $< -c

clean:
		$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re
