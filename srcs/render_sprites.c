/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:20:55 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/08 19:17:52 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		draw_rgb(t_data *data, t_color *color, int x, int y)
{
	if (data->display.endian == 1)
	{
		data->display.addr[(x * data->display.bpp >> 3)
			+ y * data->display.line_len] = color->r;
		data->display.addr[(x * data->display.bpp >> 3)
			+ 1 + y * data->display.line_len] = color->g;
		data->display.addr[(x * data->display.bpp >> 3)
			+ 2 + y * data->display.line_len] = color->b;
	}
	else
	{
		data->display.addr[(x * data->display.bpp >> 3)
			+ y * data->display.line_len] = color->b;
		data->display.addr[(x * data->display.bpp >> 3)
			+ 1 + y * data->display.line_len] = color->g;
		data->display.addr[(x * data->display.bpp >> 3)
			+ 2 + y * data->display.line_len] = color->r;
	}
}

static t_color	get_sprite_rgb(t_data *data, int i, int x, int y)
{
	t_color		color;
	t_texture	tex;
	int			start_y;
	int			endian;

	tex = data->sprites[i].texture;
	start_y = data->sprites[i].start_y;
	endian = 0;
	if (!tex.endian)
		endian = 2;
	color.r = tex.addr[(int)((x - data->sprites[i].start_x) * 1.0 /
			(data->sprites[i].end_x - data->sprites[i].start_x) *
			tex.width) * (tex.bpp >> 3) + (int)((y - start_y * 1.0) /
				data->sprites[i].size * tex.height) * tex.line_len + endian];
	color.g = tex.addr[(int)((x - data->sprites[i].start_x) * 1.0 /
			(data->sprites[i].end_x - data->sprites[i].start_x) *
			tex.width) * (tex.bpp >> 3) + (int)((y - start_y * 1.0) /
				data->sprites[i].size * tex.height) * tex.line_len + 1];
	if (!tex.endian)
		endian = 0;
	color.b = tex.addr[(int)((x - data->sprites[i].start_x) * 1.0 /
			(data->sprites[i].end_x - data->sprites[i].start_x) *
			tex.width) * (tex.bpp >> 3) + (int)((y - start_y * 1.0) /
				data->sprites[i].size * tex.height) * tex.line_len + endian];
	return (color);
}

static void		draw_sprites(t_data *data, int i, int x)
{
	int		y;
	int		end_y;
	t_color	color;

	data->sprites[i].start_y = data->window.height / 2 -
		data->sprites[i].size / 2;
	data->sprites[i].end_y = data->window.height / 2 +
		data->sprites[i].size / 2;
	y = 0;
	if (data->sprites[i].start_y >= 0)
		y = data->sprites[i].start_y;
	end_y = data->sprites[i].end_y;
	if (end_y >= data->window.height)
		end_y = data->window.height;
	while (y < end_y)
	{
		color = get_sprite_rgb(data, i, x, y);
		if (color.r != 0 || color.g != 0 || color.b != 0)
		{
			draw_rgb(data, &color, x - 1, y);
			if (x == data->window.width - 1)
				draw_rgb(data, &color, x, y);
		}
		y++;
	}
}

void			render_sprites(t_data *data, int i, t_coord transform)
{
	int		x;
	int		end_x;

	data->sprites[i].start_x = data->sprites[i].screen_x -
		data->sprites[i].size / 2;
	data->sprites[i].end_x = data->sprites[i].screen_x +
		data->sprites[i].size / 2;
	x = 0;
	if (data->sprites[i].start_x >= 0)
		x = data->sprites[i].start_x;
	end_x = data->sprites[i].end_x;
	if (end_x >= data->window.width)
		end_x = data->window.width;
	while (x < end_x)
	{
		if (transform.y > 0 && x > 0 && (transform.y < data->ray.z_buffer[x]))
			draw_sprites(data, i, x);
		x++;
	}
}
