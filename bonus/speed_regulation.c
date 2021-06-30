/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_regulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:23:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/08 15:45:00 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	regul_low_resolution(t_data *data, int size)
{
	if (size < 50000)
	{
		data->player.speed /= 4;
		data->player.rot_speed /= 5;
	}
	else if (size < 100000)
	{
		data->player.speed /= 3;
		data->player.rot_speed /= 3;
	}
	else if (size < 200000)
	{
		data->player.speed /= 2;
		data->player.rot_speed /= 2;
	}
}

void		speed_regulation(t_data *data)
{
	int		size;

	size = data->window.width * data->window.height;
	if (size > 2000000)
	{
		data->player.speed *= 4;
		data->player.rot_speed *= 2;
	}
	else if (size > 1500000)
		data->player.speed *= 3;
	else if (size > 1000000)
		data->player.speed *= 2;
	else if (size > 500000)
		data->player.speed *= 1.5;
	else if (size < 200000)
		regul_low_resolution(data, size);
}
