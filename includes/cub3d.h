/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:09:40 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/04 00:07:38 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "config.h"
# include "constants.h"
# include <fcntl.h>
# include <math.h>

void	init(char *file, t_data *data, int *need_free, int save);
void	render_texture(int x, t_data *data);
void	play(t_data *data);
int		move_player(t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);
void	speed_regulation(t_data *data);
void	raycast(t_data *data);
void	calculate_sprites(t_data *data);
void	render_sprites(t_data *data, int i, t_coord transform);
void	screenshot(t_data *data);
void	free_data(t_data *data);
void	free_more(t_data *data);
void	exit_game(t_data *data);
void	exit_error(char *s, t_data *data, int bol);

#endif
