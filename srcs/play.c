/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:08:44 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 17:46:08 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	handle_event(t_data *data)
{
	raycast(data);
	move_player(data);
	return (0);
}

static int	press_key(int key, t_data *data)
{
	if (key == MOVE_FORWARD || key == MOVE_FORWARD_ALT)
		data->key.up = 1;
	else if (key == MOVE_BACK || key == MOVE_BACK_ALT)
		data->key.down = 1;
	if (key == MOVE_RIGHT || key == MOVE_RIGHT_ALT)
		data->key.right = 1;
	else if (key == MOVE_LEFT || key == MOVE_LEFT_ALT)
		data->key.left = 1;
	if (key == TURN_RIGHT)
		data->key.rot_right = 1;
	else if (key == TURN_LEFT)
		data->key.rot_left = 1;
	return (0);
}

static int	release_key(int key, t_data *data)
{
	if (key == MOVE_FORWARD || key == MOVE_FORWARD_ALT)
		data->key.up = 0;
	else if (key == MOVE_BACK || key == MOVE_BACK_ALT)
		data->key.down = 0;
	if (key == MOVE_RIGHT || key == MOVE_RIGHT_ALT)
		data->key.right = 0;
	else if (key == MOVE_LEFT || key == MOVE_LEFT_ALT)
		data->key.left = 0;
	if (key == TURN_RIGHT)
		data->key.rot_right = 0;
	else if (key == TURN_LEFT)
		data->key.rot_left = 0;
	if (key == ESCAPE)
		mlx_loop_end(data->mlx.mlx);
	return (0);
}

static int	resize_request(t_data *data)
{
	raycast(data);
	return (0);
}

void		play(t_data *data)
{
	if (!init_mlx(data))
		return ;
	if (!malloc_z_buffer(data))
		return ;
	if (init_sprites(data))
	{
		mlx_loop_hook(data->mlx.mlx, handle_event, data);
		mlx_hook(data->mlx.win, 33, 1L << 17, mlx_loop_end, data->mlx.mlx);
		mlx_hook(data->mlx.win, 9, 1L << 21, resize_request, data);
		mlx_hook(data->mlx.win, 2, 1L << 0, press_key, data);
		mlx_hook(data->mlx.win, 3, 1L << 1, release_key, data);
		mlx_loop(data->mlx.mlx);
	}
}
