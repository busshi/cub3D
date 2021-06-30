/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:50:18 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/04 23:05:41 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	check_area(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || data->check == -1)
		return ;
	if (data->map.map[y][x] == WALL || data->map.map[y][x] == 3
			|| data->map.map[y][x] == 4 || data->map.map[y][x] == -1
			|| data->map.map[y][x] == -2 || data->map.map[y][x] == -3)
		return ;
	if (x == 0 || y == 0 || x == data->map.width ||
			y == data->map.height || data->map.map[y][x] == OUTSIDE)
		return (exit_error("Area is opened around the player\n", data, 0));
	if (data->map.map[y][x] == SPACE)
		data->map.map[y][x] = 3;
	if (data->map.map[y][x] == SPRITE)
		data->map.map[y][x] = 4;
	if (data->map.map[y][x] == DOLLAR)
		data->map.map[y][x] = -1;
	if (data->map.map[y][x] == ENNEMY)
		data->map.map[y][x] = -2;
	if (data->map.map[y][x] == MEDIPACK)
		data->map.map[y][x] = -3;
	check_area(data, x + 1, y);
	check_area(data, x, y + 1);
	check_area(data, x - 1, y);
	check_area(data, x, y - 1);
}

static void	set_player(t_data *data, int dir)
{
	data->player.dir.x = 0;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = 0;
	if (dir == N)
		data->player.dir.y = -1;
	if (dir == N)
		data->player.plane.x = FOV;
	if (dir == S)
		data->player.dir.y = 1;
	if (dir == S)
		data->player.plane.x = -FOV;
	if (dir == E)
		data->player.dir.x = 1;
	if (dir == E)
		data->player.plane.y = FOV;
	if (dir == W)
		data->player.dir.x = -1;
	if (dir == W)
		data->player.plane.y = -FOV;
}

static void	init_player(t_data *data, int w, int h, int dir)
{
	if (data->player.nb == 0)
	{
		data->player.pos.x = w + 0.5;
		data->player.pos.y = h + 0.5;
		set_player(data, dir);
	}
	else
	{
		exit_error("More than 1 player found in the map\n", data, 0);
		return ;
	}
	data->player.speed = MOVE_SPEED;
	data->player.rot_speed = ROTATION_SPEED;
	data->player.life = PLAYER_LIFE;
	data->player.nb++;
	data->map.map[h][w] = SPACE;
}

static void	check_player(t_data *data)
{
	int	current;
	int	w;
	int	h;

	h = 0;
	while (h < data->map.height && data->check != 1)
	{
		w = 0;
		while (w < data->map.width && data->check != -1)
		{
			current = data->map.map[h][w];
			if (current == N || current == S || current == E || current == W)
				init_player(data, w, h, current);
			w++;
		}
		h++;
	}
}

void		check_map(t_data *data)
{
	data->player.nb = 0;
	check_player(data);
	if (data->player.nb == 0)
		exit_error("No player found in the map\n", data, 0);
	else if (data->player.nb == 1)
	{
		check_area(data, data->player.pos.x, data->player.pos.y);
		if (data->check != -1)
		{
			count_sprites(data);
			data->check++;
		}
	}
}
