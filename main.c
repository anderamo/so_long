/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:30:47 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:18:37 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_send_error(t_map map_values)
{
	printf("Error\n");
	free(map_values.map);
	exit (1);
}

int	main(int a, char **argv)
{
	t_map	map_values;

	if (a == 2)
	{
		map_values = get_map(argv[1]);
		check_map_valid(map_values);
		map_values.mlx_ptr = mlx_init();
		map_values.win_ptr = mlx_new_window(map_values.mlx_ptr, map_values.width
				* 50, map_values.height * 50, "Scape from Dungeon");
		map_values.movements = 0;
		create_map(map_values);
	}
	printf("Error\n");
}
