/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:06:28 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 19:34:02 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_texture_pointer(t_data *data, t_texture *text)
{
	char	*s;

	text->addr = mlx_get_data_addr(text->img, &text->bpp,
			&text->line_len, &text->endian);
	if (!text->addr)
	{
		s = ft_strjoin(text->path, ": Couldn't get texture pointer\n");
		exit_error(s, data, 0);
		free(s);
		return ;
	}
	text->load++;
}

static void	load_texture(t_data *data, t_texture *text)
{
	char	*s;

	if (data->check == -1)
		return ;
	text->img = mlx_xpm_file_to_image(data->mlx.mlx,
			text->path, &text->width, &text->height);
	if (!text->img)
	{
		s = ft_strjoin(text->path, ": Couldn't load texture\n");
		exit_error(s, data, 0);
		free(s);
		return ;
	}
	else
		get_texture_pointer(data, text);
}

void		init_textures(t_data *data)
{
	load_texture(data, &data->north);
	if (data->north.load)
		load_texture(data, &data->south);
	if (data->south.load)
		load_texture(data, &data->east);
	if (data->east.load)
		load_texture(data, &data->west);
	if (data->west.load)
		load_texture(data, &data->sprite);
	if (data->sprite.load)
		data->textures_load++;
}
