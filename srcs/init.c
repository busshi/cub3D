/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:52:10 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 17:53:20 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_map(t_data *data)
{
	find_size_map(data);
	if (data->map.width > 2 && data->map.height > 2)
		malloc_map(data);
	if (!check_empty_map(data->map.buf, data))
		create_map(data);
}

static int	check_name(char *file)
{
	size_t	len;

	len = ft_strlen(file) - 4;
	if (len < 0)
	{
		ft_putstr_fd("Error\nCheck file name\n", 2);
		return (0);
	}
	if (ft_strcmp(&file[len], ".cub") != 0)
	{
		ft_putstr_fd("Error\nBad file extension\n", 2);
		return (0);
	}
	return (1);
}

void		init(char *file, t_data *data, int *need_free, int save)
{
	int	fd;

	if (check_name(file))
	{
		fd = open(file, O_RDONLY);
		if (read(fd, file, 0) < 0 || fd < 0)
		{
			ft_putstr_fd("Error\nFile open error\n", 2);
			return ;
		}
		else
			parse(fd, data, need_free, save);
	}
}
