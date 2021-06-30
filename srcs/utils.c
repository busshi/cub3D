/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:34:27 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 17:44:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_line(char *line, char *charset)
{
	while (*line != '\0')
	{
		if (!ft_ischarset(charset, *line))
			return (0);
		line++;
	}
	return (1);
}

void	malloc_map(t_data *data)
{
	int		i;

	i = 0;
	data->map.map = (int **)malloc(sizeof(int *) * data->map.height);
	if (!data->map.map)
	{
		exit_error("Fail to malloc the map! (height error)\n", data, 0);
		return ;
	}
	else
	{
		while (i < data->map.height)
		{
			data->map.map[i] = (int *)malloc(sizeof(int) * data->map.width);
			if (!data->map.map[i])
			{
				data->map.need_free = i - 1;
				exit_error("Fail to malloc the map! (width error)\n", data, 0);
				return ;
			}
			i++;
		}
	}
	data->map.need_free = i;
}

int		malloc_z_buffer(t_data *data)
{
	data->ray.z_buffer = (double *)malloc(sizeof(double) * data->window.width);
	if (!data->ray.z_buffer)
	{
		exit_error("Fail to malloc the z_buffer\n", data, 0);
		return (0);
	}
	data->z_buffer_need_free++;
	return (1);
}
