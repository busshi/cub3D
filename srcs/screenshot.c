/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:35:29 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 22:24:57 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_header(t_data *data, int fd)
{
	int		tmp;

	write(fd, "BM", 2);
	tmp = 54 + (data->window.width * data->window.height * 4);
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &data->window.width, 4);
	write(fd, &data->window.height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &data->display.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	create_bmp(t_data *data, int fd)
{
	int		w;
	int		h;

	h = data->window.height - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < data->window.width)
		{
			write(fd, &(data->display.addr[(w * data->display.bpp >> 3)
						+ data->display.line_len * h]), 4);
			w++;
		}
		h--;
	}
}

void	screenshot(t_data *data)
{
	int		fd;
	int		close_fd;
	int		i;

	if (!init_mlx(data))
		return ;
	if (!malloc_z_buffer(data))
		return ;
	if (!init_sprites(data))
		return ;
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd == -1)
	{
		exit_error("Fail to create screnshot.bmp (open error)\n", data, 0);
		return ;
	}
	i = -1;
	while (++i < data->nb_sprites)
		raycast(data);
	create_header(data, fd);
	create_bmp(data, fd);
	close_fd = close(fd);
	if (close_fd == -1)
		exit_error("Fail to save screenshot.bmp (close error)\n", data, 0);
}
