/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:47 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 18:52:46 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_mlx(t_data *data)
{
	if (data->mlx.win_load)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		data->mlx.win_load = 0;
	}
	if (data->mlx.mlx_load)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		data->mlx.mlx_load = 0;
	}
}

static void	free_sprites(t_data *data)
{
	free(data->sprites);
	data->sprites_need_free = 0;
}

static void	free_z_buffer(t_data *data)
{
	free(data->ray.z_buffer);
	data->z_buffer_need_free = 0;
}

void		free_more(t_data *data)
{
	if (data->mlx.mlx_load)
		free_mlx(data);
	if (data->sprites_need_free)
		free_sprites(data);
	if (data->z_buffer_need_free)
		free_z_buffer(data);
}
