/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:17:44 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:42:14 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_map *map_values)
{
	if (map_values->map[map_values->p_y][map_values->p_x - 1] == 'E')
	{
		if (find_chest(*map_values))
		{
			mlx_destroy_window(map_values->mlx_ptr, map_values->win_ptr);
			printf("Movements = %d\n", ++map_values->movements);
			printf("Congratulations. You scape from Dungeon\n");
			exit (1);
		}
	}
	if (map_values->map[map_values->p_y][map_values->p_x - 1] != '1' &&
		map_values->map[map_values->p_y][map_values->p_x - 1] != 'E')
	{
		printf("Movements = %d\n", ++map_values->movements);
		map_values->map[map_values->p_y][map_values->p_x] = '0';
		map_values->map[map_values->p_y][map_values->p_x - 1] = 'P';
		create_map(*map_values);
	}
}

void	move_rigth(t_map *map_values)
{
	if (map_values->map[map_values->p_y][map_values->p_x + 1] == 'E')
	{
		if (find_chest(*map_values))
		{
			mlx_destroy_window(map_values->mlx_ptr, map_values->win_ptr);
			printf("Movements = %d\n", ++map_values->movements);
			printf("Congratulations. You scape from Dungeon\n");
			exit (1);
		}
	}
	if (map_values->map[map_values->p_y][map_values->p_x + 1] != '1' &&
		map_values->map[map_values->p_y][map_values->p_x + 1] != 'E')
	{
		printf("Movements = %d\n", ++map_values->movements);
		map_values->map[map_values->p_y][map_values->p_x] = '0';
		map_values->map[map_values->p_y][map_values->p_x + 1] = 'P';
		create_map(*map_values);
	}
}

void	move_up(t_map *map_values)
{
	if (map_values->map[map_values->p_y - 1][map_values->p_x] == 'E')
	{
		if (find_chest(*map_values))
		{
			mlx_destroy_window(map_values->mlx_ptr, map_values->win_ptr);
			printf("Movements = %d\n", ++map_values->movements);
			printf("Congratulations. You scape from Dungeon\n");
			exit (1);
		}
	}
	if (map_values->map[map_values->p_y - 1][map_values->p_x] != '1' &&
		map_values->map[map_values->p_y - 1][map_values->p_x] != 'E')
	{
		printf("Movements = %d\n", ++map_values->movements);
		map_values->map[map_values->p_y][map_values->p_x] = '0';
		map_values->map[map_values->p_y - 1][map_values->p_x] = 'P';
		create_map(*map_values);
	}
}

void	move_down(t_map *map_values)
{
	if (map_values->map[map_values->p_y + 1][map_values->p_x] == 'E')
	{
		if (find_chest(*map_values))
		{
			mlx_destroy_window(map_values->mlx_ptr, map_values->win_ptr);
			printf("Movements = %d\n", ++map_values->movements);
			printf("Congratulations. You scape from Dungeon\n");
			exit (1);
		}
	}
	if (map_values->map[map_values->p_y + 1][map_values->p_x] != '1' &&
		map_values->map[map_values->p_y + 1][map_values->p_x] != 'E')
	{
		printf("Movements = %d\n", ++map_values->movements);
		map_values->map[map_values->p_y][map_values->p_x] = '0';
		map_values->map[map_values->p_y + 1][map_values->p_x] = 'P';
		create_map(*map_values);
	}
}

int	move_player(int keycode, t_map *map_values)
{
	if (keycode == 0)
		move_left(map_values);
	if (keycode == 1)
		move_down(map_values);
	if (keycode == 2)
		move_rigth(map_values);
	if (keycode == 13)
		move_up(map_values);
	return (0);
}
