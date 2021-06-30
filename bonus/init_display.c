/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:36:37 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 21:32:45 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	init_display(t_data *data)
{
	data->display.img = mlx_new_image(data->mlx.mlx, data->window.width,
			data->window.height);
	if (!data->display.img)
	{
		exit_error("Fail to init display\n", data, 0);
		return (0);
	}
	else
	{
		data->display.load++;
		data->display.addr = mlx_get_data_addr(data->display.img,
			&data->display.bpp, &data->display.line_len, &data->display.endian);
		if (!data->display.addr)
		{
			exit_error("Fail to get display pointer\n", data, 0);
			return (0);
		}
		return (1);
	}
}

static void	init_window(t_data *data)
{
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			data->window.width, data->window.height, "cub3D");
	if (data->mlx.win == NULL)
	{
		free(data->mlx.mlx);
		exit_error("Fail to create the window\n", data, 0);
	}
	data->mlx.win_load++;
}

static int	get_screen_size(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(data->mlx.mlx, &width, &height);
	if (width > 0 && height > 0)
	{
		if (data->window.width > width && !data->save)
			data->window.width = width;
		if (data->window.height > height && !data->save)
			data->window.height = height;
		return (1);
	}
	exit_error("Unable to get screen size\n", data, 0);
	return (0);
}

int			init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
	{
		ft_putstr_fd("Error\nFail to init MLX\n", 2);
		return (0);
	}
	data->mlx.mlx_load++;
	if (!get_screen_size(data))
		return (0);
	if (!data->save)
		init_window(data);
	if (data->check != -1)
		init_display(data);
	if (data->display.load)
		init_textures(data);
	init_ray(data);
	speed_regulation(data);
	if (!data->textures_load)
		return (0);
	return (1);
}
