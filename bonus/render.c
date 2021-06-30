/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:36:20 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 11:02:59 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_wall(t_data *data, t_texture *tex, int x, int y)
{
	data->display.addr[(x * data->display.bpp >> 3)
	+ y * data->display.line_len] =
	tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
			+ (int)((y - data->ray.draw_start * 1.0) / data->ray.line_height
			* tex->height) * tex->line_len];
	data->display.addr[(x * data->display.bpp >> 3)
	+ 1 + y * data->display.line_len] =
	tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
			+ 1 + (int)((y - data->ray.draw_start * 1.0)
			/ data->ray.line_height * tex->height) * tex->line_len];
	data->display.addr[(x * data->display.bpp >> 3)
	+ 2 + y * data->display.line_len] =
	tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
			+ 2 + (int)((y - data->ray.draw_start * 1.0)
			/ data->ray.line_height * tex->height) * tex->line_len];
}

static void	choose_tex(t_data *data, int x, int y)
{
	if (data->ray.side == NORTH)
		draw_wall(data, &data->north, x, y);
	else if (data->ray.side == SOUTH)
		draw_wall(data, &data->south, x, y);
	else if (data->ray.side == EAST)
		draw_wall(data, &data->east, x, y);
	else if (data->ray.side == WEST)
		draw_wall(data, &data->west, x, y);
}

static void	draw_sky(t_data *data, t_texture *sky, int x, int y)
{
	data->display.addr[(x * data->display.bpp >> 3) + y *
		data->display.line_len] = sky->addr[(x % sky->width) *
		(sky->bpp >> 3) + (y % sky->height) * sky->line_len];
	data->display.addr[(x * data->display.bpp >> 3) + 1 + y *
		data->display.line_len] = sky->addr[(x % sky->width) *
		(sky->bpp >> 3) + (y % sky->height) * sky->line_len + 1];
	data->display.addr[(x * data->display.bpp >> 3) + 2 + y *
		data->display.line_len] = sky->addr[(x % sky->width) *
		(sky->bpp >> 3) + (y % sky->height) * sky->line_len + 2];
}

void		render_texture(int x, t_data *data)
{
	int		y;

	y = 0;
	while (y < data->ray.draw_start)
	{
		if (data->ray.draw_start < 0)
			data->ray.draw_start = 0;
		draw_sky(data, &data->sky, x, y);
		y++;
	}
	while (y < data->ray.draw_end)
	{
		if (data->ray.draw_end >= data->window.height)
			data->ray.draw_end = data->window.height;
		choose_tex(data, x, y);
		y++;
	}
	while (y < data->window.height)
	{
		*(int *)(data->display.addr + (4 * data->window.width * y) +
				(x * 4)) = data->floor.rgb;
		y++;
	}
}
