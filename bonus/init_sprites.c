/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:01:15 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 09:27:56 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	count_sprites_next(t_data *data, int h, int w)
{
	if (data->map.map[h][w] == 3)
		data->map.map[h][w] = SPACE;
	else if (data->map.map[h][w] == 4 || data->map.map[h][w] == SPRITE)
	{
		data->map.map[h][w] = SPRITE;
		data->nb_sprites++;
	}
	else if (data->map.map[h][w] == -1 || data->map.map[h][w] == DOLLAR)
	{
		data->map.map[h][w] = DOLLAR;
		data->nb_sprites++;
	}
	else if (data->map.map[h][w] == -2 || data->map.map[h][w] == ENNEMY)
	{
		data->map.map[h][w] = ENNEMY;
		data->nb_sprites++;
	}
	else if (data->map.map[h][w] == -3 || data->map.map[h][w] == MEDIPACK)
	{
		data->map.map[h][w] = MEDIPACK;
		data->nb_sprites++;
	}
}

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
			count_sprites_next(data, h, w);
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

static void	init_sprites_next(t_data *data, int i, int h, int w)
{
	if (data->map.map[h][w] == SPRITE)
		data->sprites[i].texture = data->sprite;
	else if (data->map.map[h][w] == DOLLAR)
		data->sprites[i].texture = data->dollar;
	else if (data->map.map[h][w] == ENNEMY)
		data->sprites[i].texture = data->ennemy;
	else if (data->map.map[h][w] == MEDIPACK)
		data->sprites[i].texture = data->medipack;
	data->sprites[i].pos.x = w;
	data->sprites[i].pos.y = h;
	data->sprites[i].destroyed = 0;
}

int			init_sprites(t_data *data)
{
	int	w;
	int	h;
	int	i;

	if (!malloc_sprites(data))
		return (0);
	i = 0;
	h = -1;
	while (++h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			if (data->map.map[h][w] == SPRITE || data->map.map[h][w] == DOLLAR
				|| data->map.map[h][w] == ENNEMY
				|| data->map.map[h][w] == MEDIPACK)
			{
				init_sprites_next(data, i, h, w);
				i++;
			}
			w++;
		}
	}
	init_ray_shootgun(data);
	return (1);
}
