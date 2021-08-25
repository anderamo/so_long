/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:42:49 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/24 19:40:47 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(int keycode, t_map *vars)
{
	if (keycode == '5')
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit (1);
	}
	return (0);
}

int	close_win_x(void)
{
	exit (1);
	return (0);
}
