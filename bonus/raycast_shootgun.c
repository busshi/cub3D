/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_shootgun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:02:45 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:03:14 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	perform_dda_rayshoot(t_data *data)
{
//	int		i;

//	i = 0;
//	while (data->ray_shoot.hit == 0)
//	while (i < data->nb_sprites)
	{
		if (data->ray_shoot.side_dist.x < data->ray_shoot.side_dist.y)
		{
			data->ray_shoot.side_dist.x += data->ray_shoot.delta_dist.x;
			data->ray_shoot.map_x += data->ray_shoot.step_x;
		}
		else
		{
			data->ray_shoot.side_dist.y += data->ray_shoot.delta_dist.y;
			data->ray_shoot.map_y += data->ray_shoot.step_y;
		}
//		if ((int)data->map.map[data->ray_shoot.map_y][data->ray_shoot.map_x] == ENNEMY
//		 || (int)data->map.map[data->ray_shoot.map_y][data->ray_shoot.map_x] == SPRITE)
//		{
		//	data->ray_shoot.hit = 1;
//			data->sprites[i].destroyed = 1;
//			data->map.map[data->ray_shoot.map_y][data->ray_shoot.map_x] = SPACE;
//		}
//		i++;
	}
}

static void	rayshoot_hit(t_data *data)
{
	int		i;

//	calculate_rayshoot_hit(data);
	i = 0;
	while (i < data->nb_sprites)
	{
		if (data->ray_shoot.map_x == (int)data->sprites[i].pos.x
			&& data->ray_shoot.map_y == (int)data->sprites[i].pos.y && 
			(data->sprites[i].texture.addr == data->ennemy.addr ||
			 data->sprites[i].texture.addr == data->sprite.addr))// &&
		//	data->ray_shoot.hit)
		{
//			data->ray_shoot.hit = 1;
			data->sprites[i].destroyed = 1;
			data->map.map[data->ray_shoot.map_y][data->ray_shoot.map_x] = SPACE;
			if (data->sprites[i].texture.addr == data->sprite.addr)
				system("ffplay sounds/destroyed.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
			else
				system("ffplay sounds/ennemy_killed.wav -nodisp -loglevel \
					quiet -autoexit > /dev/null 2>&1 &");
		}
		i++;
	}
}

static void	calculate_rayshoot_step(t_data *data)
{
	if (data->ray_shoot.dir.x < 0)
	{
		data->ray_shoot.step_x = -1;
		data->ray_shoot.side_dist.x = (data->player.pos.x -
				data->ray_shoot.map_x) * data->ray_shoot.delta_dist.x;
	}
	else
	{
		data->ray_shoot.step_x = 1;
		data->ray_shoot.side_dist.x = (data->ray_shoot.map_x + 1.0 -
				data->player.pos.x) * data->ray_shoot.delta_dist.x;
	}
	if (data->ray_shoot.dir.y < 0)
	{
		data->ray_shoot.step_y = -1;
		data->ray_shoot.side_dist.y = (data->player.pos.y -
				data->ray_shoot.map_y) * data->ray_shoot.delta_dist.y;
	}
	else
	{
		data->ray_shoot.step_y = 1;
		data->ray_shoot.side_dist.y = (data->ray_shoot.map_y + 1.0 -
				data->player.pos.y) * data->ray_shoot.delta_dist.y;
	}
}

void		raycast_shootgun(t_data *data)
{
	data->ray.camera_x = 2 * data->window.width /
		(double)data->window.width - 1;
	data->ray_shoot.dir.x = data->player.dir.x + data->player.plane.x *
		data->ray.camera_x;
	data->ray_shoot.dir.y = data->player.dir.y + data->player.plane.y *
		data->ray.camera_x;
	data->ray_shoot.map_x = (int)data->player.pos.x;
	data->ray_shoot.map_y = (int)data->player.pos.y;
	data->ray_shoot.delta_dist.x = fabs(1 / data->ray_shoot.dir.x);
	data->ray_shoot.delta_dist.y = fabs(1 / data->ray_shoot.dir.y);
//	data->ray_shoot.hit = 0;
	calculate_rayshoot_step(data);
	perform_dda_rayshoot(data);
	rayshoot_hit(data);
}
