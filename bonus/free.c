/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:00:36 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:31:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.need_free)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	data->map.need_free = 0;
}

static void	free_texture(t_data *data, t_texture *text)
{
	if (text->load)
	{
		mlx_destroy_image(data->mlx.mlx, text->img);
		text->load = 0;
	}
	free(text->path);
}

void		free_data(t_data *data)
{
	if (!data->need_free)
		return ;
	if (data->sprite.done)
		free_texture(data, &data->sprite);
	if (data->dollar.done)
		free_texture(data, &data->dollar);
	if (data->ennemy.done)
		free_texture(data, &data->ennemy);
	if (data->medipack.done)
		free_texture(data, &data->medipack);
	if (data->north.done)
		free_texture(data, &data->north);
	if (data->south.done)
		free_texture(data, &data->south);
	if (data->east.done)
		free_texture(data, &data->east);
	if (data->west.done)
		free_texture(data, &data->west);
	if (data->sky.done)
		free_texture(data, &data->sky);
	if (data->gun.done)
		free_texture(data, &data->gun);
	if (data->map.parsing)
		free(data->map.buf);
	if (data->map.need_free)
		free_map(data);
	free_more(data);
}
