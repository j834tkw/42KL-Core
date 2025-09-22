SRCS = main.c thread_check.c thread_run.c thread_main.c utils.c

SRCS_O = $(SRCS:.c=.o)

NAME = philo

SAN = -g -fsanitize=thread

CFLAG = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -pthread -o $(NAME) $(SRCS_O)

clean :
		@rm -f ${SRCS_O}

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re