/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lifebar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:08 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 09:11:06 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_background(t_data *data, int shift)
{
	int		x;
	int		y;

	x = 0;
	while (x < PLAYER_LIFE + 2)
	{
		draw_pixel(data, shift + x + 19, 18, 0);
		draw_pixel(data, shift + x + 19, 19, 0xFFFFFF);
		draw_pixel(data, shift + x + 19, 41, 0xFFFFFF);
		draw_pixel(data, shift + x + 19, 42, 0);
		x++;
	}
	y = -2;
	while (y < 20)
	{
		draw_pixel(data, shift + 18, y + 22, 0);
		draw_pixel(data, shift + 19, y + 22, 0xFFFFFF);
		draw_pixel(data, shift + PLAYER_LIFE + 21, y + 22, 0xFFFFFF);
		draw_pixel(data, shift + PLAYER_LIFE + 22, y + 22, 0);
		y++;
	}
}

void		render_lifebar(t_data *data)
{
	int		x;
	int		y;
	int		shift;
	int		color;

	if (data->window.height < 50 || data->window.width < PLAYER_LIFE + 50)
		return ;
	color = 0x008000;
	shift = data->window.width - PLAYER_LIFE - 50;
	if (data->player.life < PLAYER_LIFE / 2)
		color = 0xFF0000;
	y = 0;
	draw_background(data, shift);
	while (y < 20)
	{
		x = 0;
		while (x < data->player.life)
		{
			draw_pixel(data, shift + x + 20, y + 20, color);
			x++;
		}
		y++;
	}
}
