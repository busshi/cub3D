/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:40:10 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/04 22:40:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	render_counter(t_data *data)
{
	char	*s;
	char	*nb;
	int		color;

	if (data->window.width < 500 || data->window.height < 500)
		return ;
	color = 0xFF0000;
	if (data->nb_dollars < 10)
		color = 0x008000;
	if (data->nb_dollars < 5)
		color = 0x00FF00;
	nb = ft_itoa(data->nb_dollars);
	s = ft_strjoin("Items remaining : ", nb);
	mlx_string_put(data->mlx.mlx, data->mlx.win,
			data->window.width - PLAYER_LIFE + 15, 60, color, s);
	free(nb);
	free(s);
}
