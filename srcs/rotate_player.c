/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:37:57 by aldubar           #+#    #+#             */
/*   Updated: 2021/02/22 17:01:03 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	speed_regulation(t_data *data)
{
	double size;

	size = data->window.width * data->window.height;
	if (size > 2000000)
	{
		data->player.speed *= 4;
		data->player.rot_speed *= 2;
	}
	else if (size > 1500000)
		data->player.speed *= 3;
	else if (size > 1000000)
		data->player.speed *= 2;
	else if (size > 500000)
		data->player.speed *= 1.5;
	else if (size < 200000)
	{
		data->player.speed /= 2;
		data->player.rot_speed /= 2;
	}
}

void	look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	old_plane_x = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(-data->player.rot_speed)
		- data->player.dir.y * sin(-data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(-data->player.rot_speed)
		+ data->player.dir.y * cos(-data->player.rot_speed);
	data->player.plane.x = data->player.plane.x * cos(-data->player.rot_speed)
		- data->player.plane.y * sin(-data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(-data->player.rot_speed)
		+ data->player.plane.y * cos(-data->player.rot_speed);
}

void	look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir.x;
	old_plane_x = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(data->player.rot_speed)
		- data->player.dir.y * sin(data->player.rot_speed);
	data->player.dir.y = old_dir_x * sin(data->player.rot_speed)
		+ data->player.dir.y * cos(data->player.rot_speed);
	data->player.plane.x = data->player.plane.x * cos(data->player.rot_speed)
		- data->player.plane.y * sin(data->player.rot_speed);
	data->player.plane.y = old_plane_x * sin(data->player.rot_speed)
		+ data->player.plane.y * cos(data->player.rot_speed);
}
