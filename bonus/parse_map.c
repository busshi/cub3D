/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:05 by aldubar           #+#    #+#             */
/*   Updated: 2021/02/26 23:20:51 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	read_buf(char *line, t_data *data)
{
	char	*tmp;

	if (!data->map.buf[0])
		tmp = ft_strdup(line);
	else
		tmp = ft_strjoin(data->map.buf, line);
	if (data->map.buf[0])
		free(data->map.buf);
	data->map.buf = ft_strdup_nl(tmp);
	if (tmp[0])
		free(tmp);
}

void		parse_map(char *line, t_data *data)
{
	if (*line != '\0' && data->map.done)
	{
		data->line -= data->map.done;
		exit_error("Empty line found in map\n", data, 1);
	}
	else if (*line == '\0' && data->map.parsing && !data->map.done)
		(data->map.done)++;
/*
**	with empty line at the end, otherwise next 2 else if to remove
**	else if (*line == '\0' && (!data->map.parsing || data->map.done))
**		return ;
*/
	else if (*line == '\0' && !data->map.parsing)
		return ;
	else if (*line == '\0' && data->map.parsing && data->map.done)
		exit_error("Empty line found after the map\n", data, 1);
	else if (*line != '\0' && !ft_ischarset("012 NSEWde", *line))
		exit_error("Bad character found while parsing map\n", data, 1);
	else
	{
		read_buf(line, data);
		(data->map.parsing)++;
	}
}
