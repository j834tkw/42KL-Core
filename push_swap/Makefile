SRCS_C = check.c free_exit.c ft_split.c get_args.c initialize.c \
			instructions_push.c instructions_rev_rotate.c instructions_rotate.c instructions_swap.c main.c \
			radix.c solve_small.c utils.c

SRCS_O = $(SRCS_C:.c=.o)

all : $(NAME)

CFLAG = -Wall -Wextra -Werror

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O)

clean :
		@rm -f ${SRCS_O}

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re