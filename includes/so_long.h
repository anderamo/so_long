/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:25:28 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:41:02 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		p_x;
	int		p_y;
	int		movements;
}				t_map;

typedef struct s_img {
	void	*img_ptr;
	int		i_w;
	int		i_h;
	int		x;
	int		y;
}				t_img;

int		find_chest(t_map map_values);
void	create_map(t_map map_values);
void	create_map_background(t_map map_values, void *mlx_ptr, void	*win_ptr);
void	create_map_wall(t_map map_values, void *mlx_ptr, void	*win_ptr);
void	create_map_scape(t_map map_values, void *mlx_ptr, void	*win_ptr);
void	check_players(t_map map_values);
void	check_scape(t_map map_values);
void	check_chest(t_map map_values);
void	check_map_valid(t_map map_values);
t_map	get_map(char *map_file);
void	free_send_error(t_map map_values);
int		close_win_x(void);
int		close_win(int keycode, t_map *vars);
char	*get_next_line(int fd);
int		move_player(int keycode, t_map *map_values);
void	create_map(t_map map_values);

#endif
