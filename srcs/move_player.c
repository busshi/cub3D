/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:53:17 by aldubar           #+#    #+#             */
/*   Updated: 2021/02/25 23:18:02 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_forward(t_data *data)
{
	double	player;

	player = -PLAYER;
	if (data->player.dir.x > 0)
		player = PLAYER;
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		+ (data->player.dir.x * data->player.speed) + player)] != WALL)
		data->player.pos.x += data->player.dir.x * data->player.speed;
	if (data->player.dir.y > 0)
		player = PLAYER;
	else if (data->player.dir.x > 0)
		player = -PLAYER;
	if (data->map.map[(int)(data->player.pos.y + (data->player.dir.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != WALL)
		data->player.pos.y += data->player.dir.y * data->player.speed;
}

static void	move_back(t_data *data)
{
	double	player;

	player = PLAYER;
	if (data->player.dir.x > 0)
		player = -PLAYER;
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		- (data->player.dir.x * data->player.speed) + player)] != WALL)
		data->player.pos.x -= data->player.dir.x * data->player.speed;
	if (data->player.dir.y > 0)
		player = -PLAYER;
	else if (data->player.dir.x > 0)
		player = PLAYER;
	if (data->map.map[(int)(data->player.pos.y - (data->player.dir.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != WALL)
		data->player.pos.y -= data->player.dir.y * data->player.speed;
}

static void	move_right(t_data *data)
{
	double	player;

	player = -PLAYER;
	if (data->player.plane.x > 0)
		player = PLAYER;
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x +
				(data->player.plane.x * data->player.speed) + player)] != WALL)
		data->player.pos.x += data->player.plane.x * data->player.speed;
	if (data->player.plane.y > 0)
		player = PLAYER;
	else if (data->player.plane.x > 0)
		player = -PLAYER;
	if (data->map.map[(int)(data->player.pos.y + (data->player.plane.y *
					data->player.speed) + player)][(int)(data->player.pos.x)]
			!= WALL)
		data->player.pos.y += data->player.plane.y * data->player.speed;
}

static void	move_left(t_data *data)
{
	double	player;

	player = PLAYER;
	if (data->player.plane.x > 0)
		player = -PLAYER;
	if (data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x -
				(data->player.plane.x * data->player.speed) + player)] != WALL)
		data->player.pos.x -= data->player.plane.x * data->player.speed;
	if (data->player.plane.y > 0)
		player = -PLAYER;
	else if (data->player.plane.x > 0)
		player = PLAYER;
	if (data->map.map[(int)(data->player.pos.y - (data->player.plane.y *
					data->player.speed) + player)][(int)(data->player.pos.x)]
			!= WALL)
		data->player.pos.y -= data->player.plane.y * data->player.speed;
}

int			move_player(t_data *data)
{
	if (data->key.up == 1)
		move_forward(data);
	else if (data->key.down == 1)
		move_back(data);
	if (data->key.right == 1)
		move_right(data);
	else if (data->key.left == 1)
		move_left(data);
	if (data->key.rot_right == 1)
		look_right(data);
	else if (data->key.rot_left == 1)
		look_left(data);
	if (data->key.up || data->key.down || data->key.right || data->key.left
			|| data->key.rot_right || data->key.rot_left)
		return (1);
	return (0);
}
