/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:41:11 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 09:29:17 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	calculate_distances(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_sprites)
	{
		data->sprites[i].dist = ((data->player.pos.x - data->sprites[i].pos.x) *
				(data->player.pos.x - data->sprites[i].pos.x))
			+ ((data->player.pos.y - data->sprites[i].pos.y) *
					(data->player.pos.y - data->sprites[i].pos.y));
		i++;
	}
}

static void	sort_sprites(t_data *data)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < data->nb_sprites)
	{
		j = 0;
		while (j < data->nb_sprites - i - 1)
		{
			if (data->sprites[i].dist < data->sprites[i + 1].dist)
			{
				tmp = data->sprites[i];
				data->sprites[i] = data->sprites[i + 1];
				data->sprites[i + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
void		calculate_sprites(t_data *data)
{
	int		i;
	double	inv_det;
	t_coord	pos;
	t_coord	transform;

	i = -1;
	calculate_distances(data);
	sort_sprites(data);
	while (++i < data->nb_sprites)
	{
		pos.x = data->sprites[i].pos.x + 0.5 - data->player.pos.x;
		pos.y = data->sprites[i].pos.y + 0.5 - data->player.pos.y;
		inv_det = 1.0 / ((data->player.dir.y * data->player.plane.x)
				- (data->player.dir.x * data->player.plane.y));
		transform.x = inv_det * ((data->player.dir.y * pos.x)
				- (data->player.dir.x * pos.y));
		transform.y = inv_det * ((-data->player.plane.y * pos.x)
				+ (data->player.plane.x * pos.y));
		data->sprites[i].screen_x = (int)((data->window.width / 2) *
				(1 + transform.x / transform.y));
		data->sprites[i].size = abs((int)(data->window.height / transform.y));
//		if (data->sprites[i].texture.img == data->dollar.img)
//			data->sprites[i].size /= 4;
		if (!data->sprites[i].destroyed)
			render_sprites(data, i, transform);
	}
}
