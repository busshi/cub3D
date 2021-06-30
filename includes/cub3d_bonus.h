/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:09:40 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 17:59:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "config_bonus.h"
# include "constants_bonus.h"
# include <fcntl.h>
# include <math.h>

void	init(char *file, t_data *data, short *need_free, short save);
void	render_texture(int x, t_data *data);
void	play(t_data *data);
int		move_player(t_data *data);
int		press_key(int key, t_data *data);
int		release_key(int key, t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);
void	speed_regulation(t_data *data);
void	raycast(t_data *data);
void	draw_pixel(t_data *data, int x, int y, int color);
void	calculate_sprites(t_data *data);
void	render_sprites(t_data *data, int i, t_coord transform);
void	render_cross(t_data *data);
void	render_gun(t_data *data, t_texture *gun);
void	render_counter(t_data *data);
void	render_lifebar(t_data *data);
void	render_minimap(t_data *data);
void	render_effects(t_data *data);
int		get_dollars(t_data *data);
int		get_medipack(t_data *data);
int		check_life(t_data *data);
int		shootgun(t_data *data);
void	raycast_shootgun(t_data *data);
void	win_or_loose(t_data *data);
void	screenshot(t_data *data);
void	free_data(t_data *data);
void	free_more(t_data *data);
void	exit_game(t_data *data);
void	exit_error(char *s, t_data *data, short bol);

#endif
