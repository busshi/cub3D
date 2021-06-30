/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:31:32 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 19:40:23 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int			press_key(int key, t_data *data)
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
	if (key == SHOOTGUN)
		data->key.shootgun = 1;
	if (key == RUN)
	{
		data->player.speed *= 2;
		data->player.rot_speed *= 2;
		data->key.speed = 1;
	}
	return (0);
}

static void	release_key_next(int key, t_data *data)
{
	if (key == RUN)
	{
		data->player.speed /= 2;
		data->player.rot_speed /= 2;
		data->key.speed = 0;
	}
	if (key == UI)
	{
		if (!data->hide_ui)
			data->hide_ui = 1;
		else if (data->hide_ui)
			data->hide_ui = 0;
		raycast(data);
	}
}

int			release_key(int key, t_data *data)
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
	if (key == SHOOTGUN)
		data->key.shootgun = 0;
	if (key == RUN || key == UI)
		release_key_next(key, data);
	if (key == ESCAPE)
		mlx_loop_end(data->mlx.mlx);
	return (0);
}
