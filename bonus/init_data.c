/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:30:22 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:32:50 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		init_ray_shootgun(t_data *data)
{
	data->ray_shoot.dir.x = 0;
	data->ray_shoot.dir.y = 0;
	data->ray_shoot.delta_dist.x = 0;
	data->ray_shoot.delta_dist.y = 0;
	data->ray_shoot.side_dist.x = 0;
	data->ray_shoot.side_dist.y = 0;
	data->ray_shoot.map_x = 0;
	data->ray_shoot.map_y = 0;
	data->ray_shoot.step_x = 0;
	data->ray_shoot.step_y = 0;
//	data->ray_shoot.hit = 0;
//	data->ray_shoot.side = 0;
	data->ray_shoot.camera_x = 0;
}

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

static void	init_more(t_data *data)
{
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
	data->key.shootgun = 0;
	data->key.speed = 0;
	data->play = 0;
	data->hide_ui = 0;
	data->player.curing = 0;
	data->player.shooting = 0;
	//data->effect = 0;
}

static void	init_data_next(t_data *data)
{
	data->north.done = 0;
	data->south.done = 0;
	data->east.done = 0;
	data->west.done = 0;
	data->sprite.done = 0;
	data->dollar.done = 0;
	data->ennemy.done = 0;
	data->medipack.done = 0;
	data->sky.done = 0;
	data->gun.done = 0;
	data->north.load = 0;
	data->south.load = 0;
	data->east.load = 0;
	data->west.load = 0;
	data->sprite.load = 0;
	data->dollar.load = 0;
	data->ennemy.load = 0;
	data->medipack.load = 0;
	data->sky.load = 0;
	data->gun.load = 0;
	data->nb_sprites = 0;
	data->nb_dollars = 0;
	data->nb_ennemy = 0;
	data->textures_load = 0;
	init_more(data);
}

void		init_data(t_data *data, short save)
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
	data->dollar.path = "";
	data->ennemy.path = "";
	data->medipack.path = "";
	data->sky.path = "";
	data->gun.path = "";
	init_data_next(data);
}
