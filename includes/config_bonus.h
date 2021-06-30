/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:09:40 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/10 18:02:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

typedef struct		s_resol
{
	int			width;
	int			height;
	short		done;
}					t_resol;

typedef struct		s_color
{
	int			r;
	int			g;
	int			b;
	int			rgb;
	short		done;
}					t_color;

typedef struct		s_display
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	short		load;
}					t_display;

typedef struct		s_texture
{
	char		*path;
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
	short		done;
	short		load;
}					t_texture;

typedef struct		s_map
{
	char		*buf;
	int			**map;
	int			width;
	int			height;
	short		parsing;
	short		need_free;
	short		done;
}					t_map;

typedef struct		s_coord
{
	double		x;
	double		y;
}					t_coord;

typedef struct		s_player
{
	int			nb;
	short		life;
	short		shooting;
	short		curing;
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	double		speed;
	double		rot_speed;
}					t_player;

typedef struct		s_sprite
{
	t_coord		pos;
	short		destroyed;
	double		dist;
	int			screen_x;
	int			size;
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	t_texture	texture;
}					t_sprite;

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	short		mlx_load;
	short		win_load;
}					t_mlx;

typedef struct		s_raycast
{
	t_coord		dir;
	t_coord		delta_dist;
	t_coord		side_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera_x;
	double		perp_wall_dist;
	double		wall_x;
	double		*z_buffer;
}					t_raycast;

typedef struct		s_gunshoot
{
	t_coord		dir;
	t_coord		delta_dist;
	t_coord		side_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
//	int			hit;
//	int			side;
	double		camera_x;
}					t_gunshoot;

typedef struct		s_move
{
	short		up;
	short		down;
	short		right;
	short		left;
	short		rot_right;
	short		rot_left;
	short		shootgun;
	short		speed;
}					t_move;

typedef struct		s_data
{
	t_resol		window;
	t_color		ceil;
	t_color		floor;
	t_texture	sprite;
	t_texture	dollar;
	t_texture	ennemy;
	t_texture	medipack;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	sky;
	t_texture	gun;
	t_display	display;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
	t_raycast	ray;
	t_move		key;
	t_sprite	*sprites;
	t_gunshoot	ray_shoot;
	short		play;
	short		save;
//	short		effect;
	int			nb_sprites;
	int			nb_dollars;
	int			nb_ennemy;
	short		textures_load;
	short		need_free;
	short		sprites_need_free;
	short		z_buffer_need_free;
	short		hide_ui;
	int			check;
	int			line;
}					t_data;

void				init_data(t_data *data, short save);
void				parse(int fd, t_data *data, short *need_free, short save);
int					check_line(char *line, char *charset);
int					init_mlx(t_data *data);
void				init_map(t_data *data);
void				read_line(int fd, t_data *data);
void				parse_path(char *line, t_data *data, t_texture *text);
void				parse_resolution(char *line, t_data *data);
void				parse_rgb(char *line, t_data *data, t_color *rgb);
void				parse_map(char *line, t_data *data);
void				find_size_map(t_data *data);
int					check_empty_map(char *s, t_data *data);
void				malloc_map(t_data *data);
int					init_sprites(t_data *data);
int					malloc_z_buffer(t_data *data);
void				surround_map(t_data *data);
void				create_map(t_data *data);
void				check_map(t_data *data);
void				init_textures(t_data *data);
void				init_ray(t_data *data);
void				init_ray_shootgun(t_data *data);
void				count_sprites(t_data *data);
void				print_config(t_data *data);

#endif
