/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:47:14 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/09 21:10:15 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <X11/keysym.h>

# define ESCAPE XK_Escape
# define MOVE_FORWARD XK_w
# define MOVE_FORWARD_ALT XK_t
# define MOVE_BACK XK_s
# define MOVE_BACK_ALT XK_g
# define MOVE_RIGHT XK_d
# define MOVE_RIGHT_ALT XK_h
# define MOVE_LEFT XK_a
# define MOVE_LEFT_ALT XK_f
# define TURN_RIGHT XK_Right
# define TURN_LEFT XK_Left
# define MAX_INT 2147483647
# define PLAYER 0.2
# define FOV 0.66
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.05
# define SPACE 0
# define WALL 1
# define SPRITE 2
# define N 5
# define S 6
# define E 7
# define W 8
# define OUTSIDE 9

typedef enum	e_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_side;

#endif
