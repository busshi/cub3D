/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 08:48:48 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:21:01 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	remove_end_spaces(char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] == ' ')
	{
		i--;
	}
	s[i + 1] = '\0';
}

void		parse_path(char *line, t_data *data, t_texture *text)
{
	if (text->done)
		return (exit_error("Texture path already set\n", data, 1));
	if (*line != ' ')
		return (exit_error("Missing texture path\n", data, 1));
	while (*line == ' ')
		line++;
	if (!text->done)
	{
		remove_end_spaces(line);
		text->path = ft_strdup(line);
	}
	if (!text->path[0])
	{
		free(text->path);
		exit_error("Wrong texture path\n", data, 1);
	}
	else
	{
		data->check++;
		text->done++;
	}
}

static void	check_resolution(t_data *data)
{
	if (data->window.width > 0 && data->window.width <= MAX_INT
			&& data->window.height > 0 && data->window.height <= MAX_INT)
	{
		if (data->window.done == 0)
		{
			data->check++;
			data->window.done++;
		}
		else
			exit_error("Duplicate resolution option\n", data, 1);
	}
	else
		exit_error("Wrong value in resolution option\n", data, 1);
}

void		parse_resolution(char *line, t_data *data)
{
	size_t	i;

	i = 0;
	if (line[i] != ' ' || !check_line(line, "0123456789 "))
		return (exit_error("Wrong resolution option\n", data, 1));
	while (line[i] == ' ')
		i++;
	data->window.width = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	data->window.height = ft_atoi(line + i);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (!check_line(line + i, " "))
		return (exit_error("Bad syntax in resolution option\n", data, 1));
	check_resolution(data);
}

void		parse(int fd, t_data *data, int *need_free, int save)
{
	data->check = 0;
	data->need_free = 0;
	init_data(data, save);
	read_line(fd, data);
	(*need_free)++;
	(data->need_free)++;
	if (data->check == 8)
		init_map(data);
	if (data->check == 9)
		check_map(data);
	if (data->check == 10 && !data->save)
		play(data);
	else if (data->check == 10 && data->save)
		screenshot(data);
}
