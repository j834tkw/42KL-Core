#include "so_long.h"

void	free_3d_arr(char **arr)
{
	int i;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

void	free_exit(t_data *data, int code)
{
	if (code == 1)
		write(1, "You win!!!\n", 11);
	free_3d_arr(data->map);
	exit(0);
}
