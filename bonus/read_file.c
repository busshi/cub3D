/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:59:54 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 10:48:55 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	check_done(t_data *data)
{
	if (!data->window.done)
		exit_error("Missing window resolution\n", data, 1);
	else if (!data->ceil.done)
		exit_error("Missing ceil RGB colors\n", data, 1);
	else if (!data->floor.done)
		exit_error("Missing floor RGB colors\n", data, 1);
	else if (!data->sprite.done)
		exit_error("Missing sprite texture path\n", data, 1);
	else if (!data->north.done)
		exit_error("Missing north texture path\n", data, 1);
	else if (!data->south.done)
		exit_error("Missing south texture path\n", data, 1);
	else if (!data->east.done)
		exit_error("Missing east texture path\n", data, 1);
	else if (!data->west.done)
		exit_error("Missing west texture path\n", data, 1);
	else if (!data->dollar.done)
		exit_error("Missing item texture path\n", data, 1);
	else if (!data->ennemy.done)
		exit_error("Missing ennemy texture path\n", data, 1);
	else if (!data->medipack.done)
		exit_error("Missing medipack texture path\n", data, 1);
	else if (!data->gun.done)
		exit_error("Missing gun texture path\n", data, 1);
}

static void	init_path(char *line, t_data *data)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_path(line + 2, data, &data->north);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_path(line + 2, data, &data->south);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_path(line + 2, data, &data->east);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_path(line + 2, data, &data->west);
	else if (line[0] == 'S' && line[1] != 'O' && line[1] != 'K')
		parse_path(line + 1, data, &data->sprite);
	else if (line[0] == 'S' && line[1] != 'O' && line[1] == 'K')
		parse_path(line + 2, data, &data->sky);
	else if (line[0] == 'D' && line[1] == ' ')
		parse_path(line + 1, data, &data->dollar);
	else if (line[0] == 'E' && line[1] == ' ')
		parse_path(line + 1, data, &data->ennemy);
	else if (line[0] == 'M' && line[1] == ' ')
		parse_path(line + 1, data, &data->medipack);
	else if (line[0] == 'G' && line[1] == ' ')
		parse_path(line + 1, data, &data->gun);
	else
		exit_error("Wrong option in configuration file\n", data, 1);
}

static int	check_coma(char *line, t_data *data)
{
	int	i;
	int	nb_coma;

	i = 0;
	nb_coma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			nb_coma++;
		i++;
	}
	if (nb_coma == 2)
		return (1);
	exit_error("Wrong definition of RGB colors\n", data, 1);
	return (0);
}

static void	parse_line(char *line, t_data *data)
{
	if (data->check == 13)
		parse_map(line, data);
	else if (data->check == -1)
		return ;
	else
	{
		while (*line == ' ')
			line++;
		if (*line == '\n' || *line == '\0')
			return ;
		else if (*line == 'R')
			parse_resolution(line + 1, data);
		else if (*line == 'F' && check_coma(line, data))
			parse_rgb(line + 1, data, &data->floor);
		else if (*line == 'C' && check_coma(line, data))
			parse_rgb(line + 1, data, &data->ceil);
		else if (*line == 'S' || *line == 'N' || *line == 'E' ||
				*line == 'W' || *line == 'D' || *line == 'M' || *line == 'G')
			init_path(line, data);
		else if (data->check != -1)
			check_done(data);
	}
}

void		read_line(int fd, t_data *data)
{
	char	*line;

	data->line = 1;
	while (get_next_line(fd, &line) == 1)
	{
		parse_line(line, data);
		free(line);
		data->line++;
	}
	if (line)
	{
		parse_line(line, data);
		free(line);
	}
	close(fd);
}
