/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:27:39 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/04 20:01:44 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int		main(int ac, char **av)
{
	short	need_free;
	t_data	data;

	need_free = 0;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
			init(av[1], &data, &need_free, 1);
		else if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
			ft_putstr_fd("Error\nBad argument: must be --save or none\n", 2);
		else
			init(av[1], &data, &need_free, 0);
		if (need_free != 0)
			free_data(&data);
	}
	else if (ac > 3)
		ft_putstr_fd("Error\nToo many arguments\n", 2);
	else
		ft_putstr_fd("Error\nNo input file\n", 2);
	return (0);
}
