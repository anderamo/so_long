/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:01:25 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:06:20 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_players(t_map map_values)
{
	t_img	img;
	int		players;

	players = 0;
	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'P')
				players++;
			img.x++;
		}
		img.y++;
	}
	if (players == 0 || players > 1)
		free_send_error(map_values);
}

void	check_scape(t_map map_values)
{
	t_img	img;
	int		scape;

	scape = 0;
	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'E')
				scape++;
			img.x++;
		}
		img.y++;
	}
	if (scape == 0)
		free_send_error(map_values);
}

void	check_chest(t_map map_values)
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
			if (map_values.map[img.y][img.x] == 'C')
				chest++;
			img.x++;
		}
		img.y++;
	}
	if (chest == 0)
		free_send_error(map_values);
}
