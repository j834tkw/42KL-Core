#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	instruction_count;
}	t_stack;

// ft_atoi
int		ft_check_atoi(const char *str, char **to_free, t_stack *to_free_2);

// check
int		check_sorted(t_stack *stack);
int		check_duplicate(t_stack *stack);
int		check_non_number(char **str);

// free_exit
void	free_and_exit(t_stack *stack, int to_print);
void	free_and_exit_both(char **to_free, t_stack *to_free_2);

// ft_split
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_countwords(char const *s, char c);
size_t	ft_delimstrl(char const *s, char c);
char	**ft_split(char const *s, char c);

// get_args
int		count_elements(char **arr);
void	realloc_stack(t_stack *stack, char **to_add);
int		ft_fill_data(t_stack *stack, int ac, char **av);

//initialize
void	ft_initialize_struct(t_stack *stack);
void	insertion_sort(int *arr, int n);
void	index_stack(t_stack *stack);

//instructions
void	ft_pa_move(t_stack *stack);
void	pa(t_stack *stack, int to_print);
void	ft_pb_move(t_stack *stack);
void	pb(t_stack *stack, int to_print);
void	rra(t_stack *stack, int to_print);
void	rrb(t_stack *stack, int to_print);
void	rrr(t_stack *stack, int to_print);
void	ra(t_stack *stack, int to_print);
void	rb(t_stack *stack, int to_print);
void	rr(t_stack *stack, int to_print);
void	sa(t_stack *stack, int to_print);
void	sb(t_stack *stack, int to_print);
void	ss(t_stack *stack, int to_print);

//main
void	ft_push_swap(t_stack *stack);

//sort
void	radix_sort(t_stack *stack);
void	sort_2(t_stack *stack);
void	sort_3(t_stack *stack);
void	sort_4(t_stack *stack);
void	sort_5(t_stack *stack);

//utils
void	ft_swap(int *a, int *b);
int		ft_isspace(char c);
int		*ft_array_dup(int *arr, int size);

#endif