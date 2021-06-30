/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:04:24 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 10:47:53 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"
#include <stdio.h>

void	print_next(t_data *data)
{
	int		h;
	int		w;

	printf("Player Plane x: %f / y: %f\n", data->player.plane.x,
			data->player.plane.y);
	printf("Player Speed: %f / Rotation: %f\n", data->player.speed,
			data->player.rot_speed);
	printf("-------------------------------------------------------\n");
	printf("Sprite nb: %d\n", data->nb_sprites);
	printf("-------------------------------------------------------\n");
	h = 0;
	while (h < data->map.height)
	{
		w = 0;
		while (w < data->map.width)
		{
			printf("%d ", data->map.map[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	printf("-------------------------------------------------------\n");
	printf("\n[ \e[0;32mok\e[0;m ] Parsing config\n\n");
}

void	print_config(t_data *data)
{
	printf("\n-------------------------------------------------------\n");
	printf("Save image: %d\n", data->save);
	printf("Resolution: x = %d / y = %d\n", data->window.width,
			data->window.height);
	printf("Floor colors: r = %d / g = %d / b = %d / rgb = %d\n", data->floor.r,
			data->floor.g, data->floor.b, data->floor.rgb);
	printf("Ceil colors: r = %d / g = %d / b = %d / rgb = %d\n", data->ceil.r,
			data->ceil.g, data->ceil.b, data->ceil.rgb);
	printf("North path: %s\n", data->north.path);
	printf("South path: %s\n", data->south.path);
	printf("East path: %s\n", data->east.path);
	printf("West path: %s\n", data->west.path);
	printf("Sprite path: %s\n", data->sprite.path);
	printf("Dollar path: %s\n", data->dollar.path);
	printf("Ennemy path: %s\n", data->ennemy.path);
	printf("Medipack path: %s\n", data->medipack.path);
	printf("Gun path: %s\n", data->gun.path);
	printf("-------------------------------------------------------\n");
	printf("Map width: %d\nMap height: %d\n", data->map.width,
			data->map.height);
	printf("-------------------------------------------------------\n");
	printf("Player Coord x: %f / y: %f\n", data->player.pos.x,
			data->player.pos.y);
	printf("Player Orientation x: %f / y: %f\n", data->player.dir.x,
			data->player.dir.y);
	print_next(data);
}
