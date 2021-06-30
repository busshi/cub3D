/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:53:17 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/08 15:32:18 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	move_forward(t_data *data)
{
	double	player;

	player = -PLAYER;
	if (data->player.dir.x > 0)
		player = PLAYER;
	if ((data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		+ (data->player.dir.x * data->player.speed) + player)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
		+ (data->player.dir.x * data->player.speed) + player)] != SPRITE))
		data->player.pos.x += data->player.dir.x * data->player.speed;
	if (data->player.dir.y > 0)
		player = PLAYER;
	else if (data->player.dir.x > 0)
		player = -PLAYER;
	if ((data->map.map[(int)(data->player.pos.y + (data->player.dir.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y + (data->player.dir.y *
			data->player.speed + player))][(int)(data->player.pos.x)]
			!= SPRITE))
		data->player.pos.y += data->player.dir.y * data->player.speed;
}

static void	move_back(t_data *data)
{
	double	player;

	player = PLAYER;
	if (data->player.dir.x > 0)
		player = -PLAYER;
	if ((data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
			- (data->player.dir.x * data->player.speed) + player)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x
			- (data->player.dir.x * data->player.speed) + player)] != SPRITE))
		data->player.pos.x -= data->player.dir.x * data->player.speed;
	if (data->player.dir.y > 0)
		player = -PLAYER;
	else if (data->player.dir.x > 0)
		player = PLAYER;
	if ((data->map.map[(int)(data->player.pos.y - (data->player.dir.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != WALL) &&
		(data->map.map[(int)(data->player.pos.y - (data->player.dir.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != SPRITE))
		data->player.pos.y -= data->player.dir.y * data->player.speed;
}

static void	move_right(t_data *data)
{
	double	player;

	player = -PLAYER;
	if (data->player.plane.x > 0)
		player = PLAYER;
	if ((data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x +
			(data->player.plane.x * data->player.speed) + player)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x +
			(data->player.plane.x * data->player.speed) + player)] != SPRITE))
		data->player.pos.x += data->player.plane.x * data->player.speed;
	if (data->player.plane.y > 0)
		player = PLAYER;
	else if (data->player.plane.x > 0)
		player = -PLAYER;
	if ((data->map.map[(int)(data->player.pos.y + (data->player.plane.y *
		data->player.speed) + player)][(int)(data->player.pos.x)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y + (data->player.plane.y
		* data->player.speed) + player)][(int)(data->player.pos.x)] != SPRITE))
		data->player.pos.y += data->player.plane.y * data->player.speed;
}

static void	move_left(t_data *data)
{
	double	player;

	player = PLAYER;
	if (data->player.plane.x > 0)
		player = -PLAYER;
	if ((data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x -
			(data->player.plane.x * data->player.speed) + player)] != WALL) &&
			(data->map.map[(int)(data->player.pos.y)][(int)(data->player.pos.x -
			(data->player.plane.x * data->player.speed) + player)] != SPRITE))
		data->player.pos.x -= data->player.plane.x * data->player.speed;
	if (data->player.plane.y > 0)
		player = -PLAYER;
	else if (data->player.plane.x > 0)
		player = PLAYER;
	if ((data->map.map[(int)(data->player.pos.y - (data->player.plane.y *
			data->player.speed) + player)][(int)(data->player.pos.x)] != WALL)
	&& (data->map.map[(int)(data->player.pos.y - (data->player.plane.y *
	data->player.speed) + player)][(int)(data->player.pos.x)] != SPRITE))
		data->player.pos.y -= data->player.plane.y * data->player.speed;
}

int			move_player(t_data *data)
{
	if (data->key.up)
		move_forward(data);
	else if (data->key.down)
		move_back(data);
	if (data->key.right)
		move_right(data);
	else if (data->key.left)
		move_left(data);
	if (data->key.rot_right)
		look_right(data);
	else if (data->key.rot_left)
		look_left(data);
	if (!data->key.up && !data->key.down && !data->key.right && !data->key.left
			&& !data->key.rot_right && !data->key.rot_left
			&& !data->key.shootgun && !data->key.speed)
		return (0);
	return (1);
}
