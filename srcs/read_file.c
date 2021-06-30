/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:59:54 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 19:08:53 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	else if (line[0] == 'S' && line[1] != 'O')
		parse_path(line + 1, data, &data->sprite);
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
	if (data->check == 8)
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
		else if (*line == 'S' || *line == 'N' || *line == 'E' || *line == 'W')
			init_path(line, data);
		else if (data->check != -1)
			exit_error("Wrong option in configuration file\n", data, 1);
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
