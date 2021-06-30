/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:18:53 by aldubar           #+#    #+#             */
/*   Updated: 2021/02/13 18:01:37 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		exit_game(t_data *data)
{
	if (data->need_free)
		free_data(data);
	exit(0);
}

void		exit_error(char *s, t_data *data, int bol)
{
	if (bol)
	{
		ft_putstr_fd("Error\nLine ", 2);
		ft_putnbr_fd(data->line, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(s, 2);
	}
	else if (!bol)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(s, 2);
	}
	data->check = -1;
	if (data->need_free)
		free_data(data);
}
