/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:37:57 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/08 15:24:43 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		look_left(t_data *data)
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

void		look_right(t_data *data)
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
