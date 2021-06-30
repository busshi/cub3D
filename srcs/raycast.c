/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:26:23 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/03 21:30:55 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calculate_distance(t_data *data)
{
	if (data->ray.side == EAST || data->ray.side == WEST)
		data->ray.perp_wall_dist = (data->ray.map_x - data->player.pos.x
				+ (1 - data->ray.step_x) / 2) / data->ray.dir.x;
	else
		data->ray.perp_wall_dist = (data->ray.map_y - data->player.pos.y
				+ (1 - data->ray.step_y) / 2) / data->ray.dir.y;
	data->ray.line_height = (int)(data->window.height
			/ data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + data->window.height / 2;
	data->ray.draw_end = data->ray.line_height / 2 + data->window.height / 2;
	if (data->ray.side == EAST || data->ray.side == WEST)
		data->ray.wall_x = data->player.pos.y +
			data->ray.perp_wall_dist * data->ray.dir.y;
	else
		data->ray.wall_x = data->player.pos.x +
			data->ray.perp_wall_dist * data->ray.dir.x;
	data->ray.wall_x -= floor(data->ray.wall_x);
}

static void	perform_dda(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist.x < data->ray.side_dist.y)
		{
			data->ray.side_dist.x += data->ray.delta_dist.x;
			data->ray.map_x += data->ray.step_x;
			if (data->ray.dir.x > 0)
				data->ray.side = EAST;
			else
				data->ray.side = WEST;
		}
		else
		{
			data->ray.side_dist.y += data->ray.delta_dist.y;
			data->ray.map_y += data->ray.step_y;
			if (data->ray.dir.y > 0)
				data->ray.side = SOUTH;
			else
				data->ray.side = NORTH;
		}
		if (data->map.map[data->ray.map_y][data->ray.map_x] == WALL)
			data->ray.hit = 1;
	}
}

static void	calculate_step(t_data *data)
{
	if (data->ray.dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist.x = (data->player.pos.x - data->ray.map_x)
			* data->ray.delta_dist.x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist.x = (data->ray.map_x + 1.0 - data->player.pos.x)
			* data->ray.delta_dist.x;
	}
	if (data->ray.dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist.y = (data->player.pos.y - data->ray.map_y)
			* data->ray.delta_dist.y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist.y = (data->ray.map_y + 1.0 - data->player.pos.y)
			* data->ray.delta_dist.y;
	}
}

static void	display_or_not(t_data *data)
{
	if (!data->save)
		mlx_put_image_to_window(data->mlx.mlx,
			data->mlx.win, data->display.img, 0, 0);
}

void		raycast(t_data *data)
{
	int		x;

	x = 0;
	while (x < data->window.width)
	{
		data->ray.camera_x = 2 * x / (double)data->window.width - 1;
		data->ray.dir.x = data->player.dir.x + data->player.plane.x
			* data->ray.camera_x;
		data->ray.dir.y = data->player.dir.y + data->player.plane.y
			* data->ray.camera_x;
		data->ray.map_x = (int)data->player.pos.x;
		data->ray.map_y = (int)data->player.pos.y;
		data->ray.delta_dist.x = fabs(1 / data->ray.dir.x);
		data->ray.delta_dist.y = fabs(1 / data->ray.dir.y);
		data->ray.hit = 0;
		calculate_step(data);
		perform_dda(data);
		calculate_distance(data);
		render_texture(x, data);
		data->ray.z_buffer[x] = data->ray.perp_wall_dist;
		x++;
	}
	calculate_sprites(data);
	display_or_not(data);
}
