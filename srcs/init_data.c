/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:52:10 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 19:59:31 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_ray(t_data *data)
{
	data->ray.side_dist.x = 0;
	data->ray.side_dist.y = 0;
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.map_x = 0;
	data->ray.map_y = 0;
	data->ray.side = 0;
	data->ray.perp_wall_dist = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.wall_x = 0;
}

static void	init_data_next(t_data *data)
{
	data->north.load = 0;
	data->south.load = 0;
	data->east.load = 0;
	data->west.load = 0;
	data->sprite.load = 0;
	data->textures_load = 0;
	data->map.parsing = 0;
	data->map.done = 0;
	data->map.buf = "";
	data->map.need_free = 0;
	data->mlx.mlx_load = 0;
	data->mlx.win_load = 0;
	data->display.load = 0;
	data->sprites_need_free = 0;
	data->z_buffer_need_free = 0;
	data->key.up = 0;
	data->key.down = 0;
	data->key.right = 0;
	data->key.left = 0;
	data->key.rot_right = 0;
	data->key.rot_left = 0;
}

void		init_data(t_data *data, int save)
{
	data->save = save;
	data->window.width = -1;
	data->window.height = -1;
	data->window.done = 0;
	data->floor.r = -1;
	data->floor.g = -1;
	data->floor.b = -1;
	data->floor.rgb = -1;
	data->floor.done = 0;
	data->ceil.r = -1;
	data->ceil.g = -1;
	data->ceil.b = -1;
	data->ceil.rgb = -1;
	data->ceil.done = 0;
	data->north.path = "";
	data->south.path = "";
	data->east.path = "";
	data->west.path = "";
	data->sprite.path = "";
	data->sprite.done = 0;
	data->north.done = 0;
	data->south.done = 0;
	data->east.done = 0;
	data->west.done = 0;
	init_data_next(data);
}
