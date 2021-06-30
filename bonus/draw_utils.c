/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:36:44 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/08 18:47:32 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < data->window.width &&
			y >= 0 && y < data->window.height)
		*(int *)(data->display.addr + (4 * (int)data->window.width *
			(int)y) + ((int)x * 4)) = color;
}

void	draw_rectangle(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < data->window.width)
		draw_pixel(data, x, 0, 0);
	while (++y < data->window.height)
		draw_pixel(data, 0, y, 0);
	x = -1;
	y = -1;
	while (++x < data->window.width)
		draw_pixel(data, x, data->window.height - 1, 0);
	while (++y < data->window.height)
		draw_pixel(data, data->window.width - 1, y, 0);
}
