/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:24:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 14:52:28 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static size_t	skip_forward(char *line, t_data *data)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if ((line[i] != ',' || ft_isdigit(line[i])) && data->check != -1)
		exit_error("Bad syntax in RGB colors option\n", data, 1);
	else
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

static int		check_rgb(t_data *data, t_color *rgb)
{
	if (rgb->r >= 0 && rgb->g >= 0 && rgb->b >= 0 &&
			rgb->r <= 255 && rgb->g <= 255 && rgb->b <= 255 &&
			data->check != -1)
	{
		if (rgb->done == 0)
		{
			rgb->rgb = rgb->r << 16 | rgb->g << 8 | rgb->b;
			rgb->done++;
			data->check++;
			return (1);
		}
		else
			exit_error("Duplicate RGB colors option\n", data, 1);
	}
	else
		exit_error("Wrong RGB colors option\n", data, 1);
	return (0);
}

static void		parse_b(char *line, t_data *data, t_color *rgb)
{
	size_t	i;

	i = 0;
	if (rgb->g >= 0 && rgb->g <= 255 && data->check != -1)
	{
		i += skip_forward(line + i, data);
		if (ft_isdigit(line[i]) && line[i] != '\0' && data->check != -1)
			rgb->b = ft_atoi(line + i);
		else if (data->check == -1)
			return ;
		else
			return (exit_error("Bad syntax in RGB colors\n", data, 1));
	}
	else
		return (exit_error("Wrong Green value in RGB colors\n", data, 1));
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (!check_line(line + i, " "))
		return (exit_error("Too many values in RGB colors\n", data, 1));
	check_rgb(data, rgb);
}

static void		parse_g(char *line, t_data *data, t_color *rgb)
{
	size_t	i;

	i = 0;
	if (rgb->r >= 0 && rgb->r <= 255 && data->check != -1)
	{
		i += skip_forward(line + i, data);
		if (ft_isdigit(line[i]) && line[i] != '\0' && data->check != -1)
			rgb->g = ft_atoi(line + i);
		else if (data->check == -1)
			return ;
		else
			return (exit_error("Bad syntax in RGB colors\n", data, 1));
	}
	else
		return (exit_error("Wrong Red value in RGB colors\n", data, 1));
	parse_b(line + i, data, rgb);
}

void			parse_rgb(char *line, t_data *data, t_color *rgb)
{
	size_t	i;

	i = 0;
	if (line[i] != ' ')
		return (exit_error("Missing RGB colors option\n", data, 1));
	while (line[i] == ' ')
		i++;
	if (!check_line(line, "0123456789, "))
	{
		exit_error("Wrong character found in RGB colors option\n", data, 1);
		return ;
	}
	if (ft_isdigit(line[i]) && line[i] != '\0' && data->check != -1)
		rgb->r = ft_atoi(line + i);
	else
		return (exit_error("Bad syntax in RGB colors\n", data, 1));
	parse_g(line + i, data, rgb);
}
