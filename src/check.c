/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:13:24 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:02:30 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_wall(t_map map_values)
{
	t_img	img;

	img.y = 0;
	img.x = 0;
	while (img.x < map_values.width)
	{
		if (map_values.map[0][img.x] != '1')
			free_send_error(map_values);
		if (map_values.map[map_values.height - 1][img.x] != '1')
			free_send_error(map_values);
		img.x++;
	}
	while (img.y < map_values.height)
	{
		if (map_values.map[img.y][0] != '1'
			|| map_values.map[img.y][map_values.width - 1] != '1')
			free_send_error(map_values);
		img.y++;
	}
}

void	check_valid_elements(t_map map_values)
{
	t_img	img;
	int		chest;

	chest = 0;
	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] != 'C'
				&& map_values.map[img.y][img.x] != 'E'
				&& map_values.map[img.y][img.x] != 'P'
				&& map_values.map[img.y][img.x] != '0'
				&& map_values.map[img.y][img.x] != '1')
				free_send_error(map_values);
			img.x++;
		}
		img.y++;
	}
}

void	check_map_valid(t_map map_values)
{
	check_valid_elements(map_values);
	check_wall(map_values);
	check_players(map_values);
	check_scape(map_values);
	check_chest(map_values);
}
