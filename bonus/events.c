/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:09:37 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 19:03:28 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	win_or_loose(t_data *data)
{
	if (data->window.width < 100 || data->window.height < 100)
		return ;
	if (data->play == 1)
		mlx_string_put(data->mlx.mlx, data->mlx.win,
			data->window.width / 2 - 80, data->window.height / 2,
			0x00FF00, "CONGRATULATIONS !!! YOU WIN");
	else if (data->play == -1)
		mlx_string_put(data->mlx.mlx, data->mlx.win,
			data->window.width / 2 - 30, data->window.height / 2,
			0xFF0000, "YOU LOOSE !!!");
}

int		shootgun(t_data *data)
{
	if (data->key.shootgun)
	{
		system("ffplay sounds/shootgun.mp3 -nodisp -loglevel quiet \
			-autoexit > /dev/null 2>&1 &");
		raycast_shootgun(data);
		return (1);
	}
	return (0);
}

int		get_medipack(t_data *data)
{
	int		x;
	int		y;

	x = (int)data->player.pos.x;
	y = (int)data->player.pos.y;
	if (data->map.map[y][x] == MEDIPACK && data->player.life < PLAYER_LIFE)
	{
		if (data->player.life <= PLAYER_LIFE - 20)
			data->player.life += 20;
		else if (data->player.life + 20 > PLAYER_LIFE)
			data->player.life = PLAYER_LIFE;
		if (!data->player.curing)
		{
			data->player.curing = 1;
			//data->effect = MEDIPACK;
			system("ffplay sounds/health.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
		}
		return (1);
	}
	if (data->map.map[y][x] != MEDIPACK)
		data->player.curing = 0;
	return (0);
}

int		get_dollars(t_data *data)
{
	int		x;
	int		y;

	x = (int)data->player.pos.x;
	y = (int)data->player.pos.y;
	if (data->map.map[y][x] == DOLLAR)
	{
		data->map.map[y][x] = SPACE;
		data->nb_dollars--;
		data->nb_sprites--;
		if (data->play == 0)
			system("ffplay sounds/coin.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
		if (!data->nb_dollars)
		{
			system("ffplay sounds/win.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
			data->play = 1;
		}
		return (1);
	}
	return (0);
}

int		check_life(t_data *data)
{
	int		x;
	int		y;

	x = (int)data->player.pos.x;
	y = (int)data->player.pos.y;
	if (data->map.map[y][x] == ENNEMY)
	{
		data->player.life -= DAMAGE;
		if (data->play == 0)
			system("ffplay sounds/scream.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
		if (!data->player.life)
		{
			system("ffplay sounds/loose.wav -nodisp -loglevel quiet \
					-autoexit > /dev/null 2>&1 &");
			data->play = -1;
		}
		return (1);
	}
	return (0);
}
