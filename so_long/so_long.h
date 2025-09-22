/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutong <jutong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:11:52 by jutong            #+#    #+#             */
/*   Updated: 2023/09/11 14:33:08 by jutong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# ifndef IMG_SIZE
#  define IMG_SIZE 64
# endif

# ifndef ON_DESTROY
#  define ON_DESTROY 17
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;

	int		map_width;
	int		map_height;
	char	**map;

	void	*player_img;
	void	*floor_img;
	void	*wall_img;
	void	*coin_img;
	void	*exit_img;
	void	*exit_2_img;

	int		coin_count;
	int		exit_count;
	int		player_count;

	int		player_x;
	int		player_y;
	int		coins_collected;
	int		movement_count;
	int		movement_bool;

}				t_data;

//free_exit
void	free_3d_arr(char **arr);
int		free_exit(t_data *data, int code);

//floodfill
int		floodfill(t_data *data);

//prep
void	check_valid(t_data *data, char *file_name);
void	check_valid_2(t_data *data);
int		read_map(t_data *data, char *file_name);
int		get_map(t_data *data, char *file_name);
int		check_chars(t_data *data);
int		check_file_name(char *file_name);
int		check_closed_map(t_data *data);

//images
void	init_image(t_data *data);
void	put_img(t_data *data, int x, int y);
void	put_map_img_to_win(t_data *data);
int		image_loop(t_data *data);

//locate
void	locate_player(t_data *data);
int		count_coins(t_data *data);
int		count_exits(t_data *data);
int		count_players(t_data *data);

//movement
int		movement(int keycode, t_data *data);

//event
void	event(t_data *data);
void	collect_coin(t_data *data);
void	unlock_exit(t_data *data);

//gnl
char	*reallocbuff(char *buff, int rv);
char	*get_next_line(int fd);
char	*ft_readfile(int fd, char *buffer);
char	*ft_getline(char *buffer);
char	*ft_cleanup(char *buffer);
int		ft_strlen(const char *str);
char	*ft_strdup(char *s);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_redeploy(char *s, int len);

//ft_split
char	**ft_split(char const *s, char c);

//utils
char	*ft_strdup(char *s1);
void	ft_putnbr_fd(int n, int fd);

#endif