SRCS = main.c free_exit.c ft_split.c gnl_utils.c gnl.c \
		images.c prep_map.c locate.c utils.c event.c\
		movement.c floodfill.c prep_check.c

OBJ = $(SRCS:.c=.o)

NAME = so_long

CC = gcc

SAN = -g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

clean :
		@rm -f ${OBJ}

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re