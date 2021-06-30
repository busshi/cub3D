/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:08:44 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:13:21 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	handle_event(t_data *data)
{
	if (data->play != 0)
		return (0);
	if (shootgun(data))
		raycast(data);
	if (get_dollars(data))
		raycast(data);
	if (get_medipack(data))
		raycast(data);
	if (move_player(data))
		raycast(data);
	if (check_life(data))
		raycast(data);
	return (0);
}

static int	resize_request(t_data *data)
{
	raycast(data);
	return (0);
}

void		play(t_data *data)
{
	if (!init_mlx(data))
		return ;
	if (!malloc_z_buffer(data))
		return ;
//	print_config(data);
	if (init_sprites(data))
	{
		system("ffplay -volume 40 sounds/time.mp3 -nodisp \
				-loglevel quiet -autoexit > /dev/null 2>&1 &");
		raycast(data);
		mlx_loop_hook(data->mlx.mlx, handle_event, data);
		mlx_hook(data->mlx.win, 33, 1L << 17, mlx_loop_end, data->mlx.mlx);
		mlx_hook(data->mlx.win, 9, 1L << 21, resize_request, data);
		mlx_hook(data->mlx.win, 2, 1L << 0, press_key, data);
		mlx_hook(data->mlx.win, 3, 1L << 1, release_key, data);
		mlx_loop(data->mlx.mlx);
	}
	exit_game(data);
}
