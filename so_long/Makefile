SRCS = main.c free_exit.c ft_split.c gnl_utils.c gnl.c \
		images.c prep_map.c locate.c utils.c event.c\
		movement.c floodfill.c prep_check.c

OBJ = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

clean :
		@rm -f ${OBJ}

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re