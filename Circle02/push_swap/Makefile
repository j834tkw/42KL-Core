SRCS_C = check.c free_exit.c ft_split.c get_args.c initialize.c \
			instructions_push.c instructions_rev_rotate.c instructions_rotate.c instructions_swap.c main.c \
			radix_sort.c solve_small.c utils.c ft_atoi.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

SRCS_O = $(SRCS_C:.c=.o)

BONUS_C = bonus_main.c check.c free_exit.c ft_split.c get_args.c initialize.c \
			instructions_push.c instructions_rev_rotate.c instructions_rotate.c instructions_swap.c \
			radix_sort.c solve_small.c utils.c ft_atoi.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

BONUS_O = $(BONUS_C:.c=.o)

NAME = push_swap

BONUS_NAME = checker

all : $(NAME)

CFLAG = -Wall -Wextra -Werror

%.o: %.c
		@gcc $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(SRCS_O)
		@gcc $(CFLAG) -o $(NAME) $(SRCS_O)

bonus: $(BONUS_O)
		@gcc $(CFLAG) -o $(BONUS_NAME) $(BONUS_O)

clean :
		@rm -f $(SRCS_O)
		@rm -f $(BONUS_O)

fclean : clean
		@rm -f $(NAME)
		@rm -f $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re