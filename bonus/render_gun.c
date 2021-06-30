/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:40:33 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 21:37:27 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"
#include <stdio.h>
static int	get_gun_rgb(t_texture *gun, int x, int y)
{
	int		color;

	color = gun->addr[((x * gun->width) * gun->bpp) + ((y * gun->height) * gun->line_len)];
//	color = gun->addr[x * gun->width + y * gun->height];
	y = 0;
	printf("%d\n", color);
	return (color);
}

void	render_gun(t_data *data, t_texture *gun)
{
	if (data->window.width < 50)
		return ;
/*	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, gun->img,
		data->window.width / 2 - 50, data->window.height - gun->height);*/
	int	x;
	int	y;
	int	w;
	int	h;
	int	color;

	y = 0;
	h = data->window.height - gun->height;
	while (y < gun->height/2)
	{
		x = 0;
		w = data->window.width / 2 - 50;
		while (x < gun->width / 2)
		{
			printf("ok");
			color = get_gun_rgb(gun, x, y);
			if (color)
				//data->display.addr[(x * data->display.bpp) + y * data->display.line_len] = color;
				*(int *)(data->display.addr + (4 * (int)data->window.width * (int)h) + ((int)w * 4)) = color;//*(int *)(gun->addr + (int)(gun->width * y + x * 4));
			x++;
			w++;
		}
		h++;
		y++;
	}
}

void	render_effect(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y <data->window.height)
	{
		x = 0;
		while (x < data->window.width)
		{
			*(int *)(data->display.addr + (4 * (int)data->window.width * (int)y) + ((int)x * 4)) = 0xFF0000;
			x++;
		}
		y++;
	}
//	data->effect = 0;
}
