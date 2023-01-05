# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 09:55:21 by jutong            #+#    #+#              #
#    Updated: 2022/11/14 16:00:21 by jutong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_lstadd_front.c ft_memmove.c ft_strlcat.c ft_atoi.c ft_memset.c \
				ft_strlcpy.c ft_bzero.c ft_putchar_fd.c ft_strlen.c ft_calloc.c \
				ft_putendl_fd.c ft_strmapi.c ft_isalnum.c ft_putnbr_fd.c ft_strncmp.c \
				ft_isalpha.c ft_putstr_fd.c ft_strrchr.c ft_isascii.c ft_split.c \
				ft_strtrim.c ft_isdigit.c ft_strchr.c ft_substr.c ft_isprint.c \
				ft_memchr.c ft_strdup.c ft_tolower.c ft_itoa.c ft_memcmp.c \
				ft_striteri.c ft_toupper.c ft_memcpy.c ft_strjoin.c ft_strnstr.c \

OBJS	= $(SRCS:.c=.o)

BONUS	= ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c ft_lstadd_front.c ft_lstiter.c \
				ft_lstnew.c ft_lstclear.c ft_lstlast.c ft_lstsize.c \

BONUSOBJS= $(BONUS:.c=.o)

SRCSH	= libft.h

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) $< -c

clean:
		$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUSOBJS)
			ar rcs $(NAME) $(OBJS) $(BONUSOBJS)

.PHONY: all clean fclean re bonus