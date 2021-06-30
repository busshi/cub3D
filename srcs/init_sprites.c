/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:01:15 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 21:44:52 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		count_sprites(t_data *data)
{
	int	w;
	int	h;

	h = 0;
	data->nb_sprites = 0;
	while (h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			if (data->map.map[h][w] == 3)
				data->map.map[h][w] = SPACE;
			else if (data->map.map[h][w] == 4 || data->map.map[h][w] == SPRITE)
			{
				data->map.map[h][w] = SPRITE;
				data->nb_sprites++;
			}
			w++;
		}
		h++;
	}
}

static int	malloc_sprites(t_data *data)
{
	data->sprites = (t_sprite *)malloc(sizeof(t_sprite) * data->nb_sprites);
	if (!data->sprites)
	{
		exit_error("Fail to malloc sprites array\n", data, 0);
		return (0);
	}
	data->sprites_need_free++;
	return (1);
}

int			init_sprites(t_data *data)
{
	int	w;
	int	h;
	int	i;

	if (!malloc_sprites(data))
		return (0);
	i = 0;
	h = 0;
	while (h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			if (data->map.map[h][w] == SPRITE)
			{
				data->sprites[i].texture = data->sprite;
				data->sprites[i].pos.x = w;
				data->sprites[i].pos.y = h;
				i++;
			}
			w++;
		}
		h++;
	}
	return (1);
}
