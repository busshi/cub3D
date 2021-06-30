/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:07:17 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 22:12:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	size_adjustment(t_data *data)
{
	int		size;
	int		w;
	int		h;

	w = data->window.width;
	h = data->window.height;
	size = 1;
	if (w * h < 200000 || data->map.width > 250 || data->map.height > 250)
		size = 2;
	else if (w * h < 500000 ||
			data->map.width > 100 || data->map.height > 100)
		size = 4;
	else if (w * h > 1000000)
		size = 6;
	return (size);
}

static int	choose_color(t_data *data, int x, int y)
{
	if ((int)data->player.pos.x == x && (int)data->player.pos.y == y)
		return (0xFF0000);
	else if (data->map.map[y][x] == WALL)
		return (0x000000);
	else if (data->map.map[y][x] == DOLLAR)
		return (0x00FF00);
	else if (data->map.map[y][x] == ENNEMY)
		return (0xFF8C00);
	else if (data->map.map[y][x] == MEDIPACK)
		return (0x0000FF);
	else if (data->map.map[y][x] == SPACE)
		return (0xFFFFFF);
	else if (data->map.map[y][x] == SPRITE)
		return (0x8B4513);
	return (-1);
}

void		render_minimap(t_data *data)
{
	int		x;
	int		y;
	int		color;
	int		size;

	if (data->window.width < 400 || data->window.height < 400 ||
			data->map.width > 500 || data->map.height > 500)
		return ;
	size = size_adjustment(data);
	y = -1;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < data->map.width)
		{
			color = choose_color(data, x, y);
			if (color != -1)
			{
				draw_pixel(data, 20 + x * size, 20 + y * size, color);
				draw_pixel(data, 20 + x * size + 1, 20 + y * size, color);
				draw_pixel(data, 20 + x * size + 1, 20 + y * size + 1, color);
				draw_pixel(data, 20 + x * size, 20 + y * size + 1, color);
			}
		}
	}
}
