#include "push_swap.h"

void	radix_sort(t_stack *stack)
{
	int	i;
	int	bitshift;
	int	size;

	bitshift = 0;
	size = stack->size_a;
	while (check_sorted(stack) == 0)
	{
		i = 0;
		while (i < size)
		{
			if (((stack->stack_a[0] >> bitshift) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack, 1);
			i++;
		}
		while (stack->size_b > 0)
			pa(stack, 1);
		bitshift++;
	}
}

/*void	insertion_sort(int *arr, int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	simplify_a(t_stack *stack)
{
	int		i;
	int		j;
	int		size;
	int		*copy;

	i = 0;
	j = 0;
	size = stack ->size_a;
	copy = ft_array_dup(stack ->stack_a, size);
	insertion_sort(copy, size);
	while (i < size)
	{
		while (j < size)
		{
			if (stack ->stack_a[i] == copy[j])
			{
				stack ->stack_a[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	free(copy);
}

static void	push_all_b_to_a(t_stack *stack)
{
	while (stack ->size_b > 0)
		pa(stack, 1);
}

void	radix_sort(t_stack *stack)
{
	int		i;
	int		size;
	int		lsb;
	int		shift;

	i = 0;
	shift = 0;
	size = stack ->size_a;
//	printf("checkpoint 1\n");
	simplify_a(stack);
	while (!check_sorted(stack))
	{
//		printf("checkpoint 2\n");
		while (i < size)
		{
			lsb = stack ->stack_a[0];
			lsb = (lsb >> shift) & 1;
			if (lsb == 0)
			{
//				printf("checkpoint special\n");
				pb(stack, 1);
//				printf("checkpoint special\n");
			}
			else if (lsb == 1)
			{
				ra(stack, 1);
			}
//			printf("checkpoint 3, i = %d\n", i);
			i++;
		}
		i = 0;
		push_all_b_to_a(stack);
		shift++;
	}
}*/