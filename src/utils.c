/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:44:46 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 18:52:19 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_chest(t_map map_values)
{
	t_img	img;

	img.y = 0;
	while (img.y < map_values.height)
	{
		img.x = 0;
		while (img.x < map_values.width)
		{
			if (map_values.map[img.y][img.x] == 'C')
				return (0);
			img.x++;
		}
		img.y++;
	}
	return (1);
}

char	**fill_map(char **map, char *map_file, int heigth, int width)
{
	int		fd;
	char	*line;
	int		i;
	int		k;

	fd = open(map_file, O_RDONLY);
	i = 0;
	while (heigth > i)
	{
		line = get_next_line(fd);
		k = 0;
		while (width > k)
		{
			map[i][k] = line[k];
			k++;
		}
		map[i][k] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	map_height(char *map_file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(map_file, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

int	map_width(char *map)
{
	int		fd;
	int		width;
	int		width_first;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	width_first = strlen(line) - 1;
	while (line != NULL)
	{
		width = strlen(line);
		if (line[width - 1] == '\n')
			width--;
		if (width_first != width)
		{
			printf("map ERROR. Is not rectagular.");
			exit(1);
		}
		line = get_next_line(fd);
	}
	return (width);
}

t_map	get_map(char *map_file)
{
	t_map	map_values;
	int		i;

	map_values.height = map_height(map_file);
	map_values.width = map_width(map_file);
	map_values.map = (char **)malloc(sizeof(char *) * (map_values.height + 1));
	i = 0;
	while (map_values.height > i)
	{
		map_values.map[i] = (char *)malloc(sizeof(char)
				* (map_values.width + 1));
		i++;
	}
	map_values.map = fill_map(map_values.map, map_file, map_values.height,
			 map_values.width);
	return (map_values);
}
