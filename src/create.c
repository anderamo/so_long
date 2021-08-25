/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:18:40 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:18:25 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map_chest(t_map map_values, void *mlx_ptr, void	*win_ptr)
{
	t_img	img;

	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'C')
			{
				img.img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						"./textures/chest_close.xpm", &img.i_w, &img.i_h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr,
					(img.x * 50) + 5, (img.y * 50) + 5);
			}
			img.x++;
		}
		img.y++;
	}
}

t_map	create_map_player(t_map map_values, void *mlx_ptr, void	*win_ptr)
{
	t_img	img;

	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'P')
			{
				img.img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						"./textures/player.xpm", &img.i_w, &img.i_h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr,
					(img.x * 50), (img.y * 50));
				map_values.p_x = img.x;
				map_values.p_y = img.y;
			}
			img.x++;
		}
		img.y++;
	}
	return (map_values);
}

void	create_map(t_map map_values)
{
	mlx_clear_window(map_values.mlx_ptr, map_values.win_ptr);
	create_map_background(map_values, map_values.mlx_ptr, map_values.win_ptr);
	create_map_wall(map_values, map_values.mlx_ptr, map_values.win_ptr);
	create_map_scape(map_values, map_values.mlx_ptr, map_values.win_ptr);
	create_map_chest(map_values, map_values.mlx_ptr, map_values.win_ptr);
	map_values = create_map_player(map_values, map_values.mlx_ptr,
			map_values.win_ptr);
	mlx_hook(map_values.win_ptr, 2, 1L << 0, close_win, &map_values);
	mlx_hook(map_values.win_ptr, 17, 1L << 17, close_win_x, &map_values);
	mlx_key_hook(map_values.win_ptr, move_player, &map_values);
	mlx_loop(map_values.mlx_ptr);
}
