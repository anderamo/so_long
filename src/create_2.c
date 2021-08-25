/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:58:03 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:07:17 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map_background(t_map map_values, void *mlx_ptr, void	*win_ptr)
{
	t_img	img;

	img.y = 0;
	img.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/back.xpm",
			&img.i_w, &img.i_h);
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, img.x * 50,
				img.y * 50);
			img.x++;
		}
		img.y++;
	}
}

void	create_map_wall(t_map map_values, void *mlx_ptr, void	*win_ptr)
{
	t_img	img;

	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == '1')
			{
				img.img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						 "./textures/wall.xpm", &img.i_w, &img.i_h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr,
					img.x * 50, img.y * 50);
			}
			img.x++;
		}
		img.y++;
	}
}

void	create_map_scape(t_map map_values, void *mlx_ptr, void	*win_ptr)
{
	t_img	img;

	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'E')
			{
				if (find_chest(map_values))
					img.img_ptr = mlx_xpm_file_to_image(mlx_ptr,
							 "./textures/o_door.xpm", &img.i_w,
							 	 &img.i_h);
				else
					img.img_ptr = mlx_xpm_file_to_image(mlx_ptr,
							"./textures/c_door.xpm", &img.i_w,
							&img.i_h);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr,
					(img.x * 50), (img.y * 50));
			}
			img.x++;
		}
		img.y++;
	}
}
