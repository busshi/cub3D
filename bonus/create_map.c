/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:02:52 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:07:58 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	fill_directions(t_data *data, int i, int w, int h)
{
	if (data->map.buf[i] == 'N')
		data->map.map[h][w] = N;
	else if (data->map.buf[i] == 'S')
		data->map.map[h][w] = S;
	else if (data->map.buf[i] == 'E')
		data->map.map[h][w] = E;
	else if (data->map.buf[i] == 'W')
		data->map.map[h][w] = W;
}

static void	fill_map(t_data *data, int i, int w, int h)
{
	if (ft_ischarset("012", data->map.buf[i]))
		data->map.map[h][w] = data->map.buf[i] - '0';
	else if (ft_ischarset("NSEW", data->map.buf[i]))
		fill_directions(data, i, w, h);
	else if (data->map.buf[i] == 'd')
	{
		data->nb_dollars++;
		data->map.map[h][w] = DOLLAR;
	}
	else if (data->map.buf[i] == 'e')
	{
		data->nb_ennemy++;
		data->map.map[h][w] = ENNEMY;
	}
	else if (data->map.buf[i] == 'm')
		data->map.map[h][w] = MEDIPACK;
	else if (data->map.buf[i] == ' ')
		data->map.map[h][w] = OUTSIDE;
}

void		create_map(t_data *data)
{
	int	i;
	int	w;
	int	h;

	i = -1;
	w = 1;
	h = 1;
	data->line = data->line - data->map.height + 2;
	surround_map(data);
	while (data->map.buf[++i] && data->check != -1)
	{
		if (ft_ischarset("012NSEWdem \n", data->map.buf[i]))
			fill_map(data, i, w, h);
		else
			return (exit_error("Bad character found in map\n", data, 1));
		if (data->map.buf[i] == '\n')
		{
			w = 0;
			data->line++;
			h++;
		}
		w++;
	}
	if (data->map.buf[i] == '\0')
		data->check = ALMOST_READY;
}

void		find_size_map(t_data *data)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = 0;
	data->map.height = 0;
	data->map.width = 0;
	while (data->map.buf[i])
	{
		while (data->map.buf[i] != '\n' && data->map.buf[i])
		{
			temp++;
			i++;
		}
		if (data->map.buf[i] == '\n' || data->map.buf[i] == '\0')
		{
			data->map.height++;
			if (temp > data->map.width)
				data->map.width = temp;
			temp = 0;
		}
		i++;
	}
	data->map.height += 2;
	data->map.width += 2;
}

int			check_empty_map(char *s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i] && ft_ischarset(" \n", s[i]))
		i++;
	if (s[i] == '\0')
	{
		exit_error("Map description is missing\n", data, 0);
		return (1);
	}
	return (0);
}
