/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:45:37 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/05 17:47:55 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	draw_cross(t_data *data, int i, int color)
{
	int	max;
	int	x;
	int	y;

	max = -i;
	while (i < max)
	{
		if (i < -5 || i > 5 || i == 0)
		{
			x = (data->window.width / 2 + i);
			y = data->window.height / 2;
			draw_pixel(data, x, y, color);
			x = (data->window.width / 2);
			y = data->window.height / 2 + i;
			draw_pixel(data, x, y, color);
		}
		i++;
	}
}

void		render_cross(t_data *data)
{
	if (data->window.width < 200 || data->window.height < 200)
		return ;
	if (data->key.shootgun)
		draw_cross(data, -40, 0xFF0000);
	else if (data->key.speed)
		draw_cross(data, -20, 0xFFFFFF);
	else
		draw_cross(data, -10, 0x00FF00);
}
