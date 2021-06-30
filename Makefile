# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 14:19:00 by aldubar           #+#    #+#              #
#    Updated: 2021/03/09 21:54:53 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS		=	main.c \
			utils.c \
			read_file.c \
			parse.c \
			parse_rgb.c \
			parse_map.c \
			init.c \
			init_data.c \
			init_display.c \
			init_sprites.c \
			init_textures.c \
			create_map.c \
			check_player.c \
			calc_sprites.c \
			raycast.c \
			render.c \
			render_sprites.c \
			play.c \
			move_player.c \
			rotate_player.c \
			screenshot.c \
			free.c \
			free_more.c \
			exit.c \
			print_config.c

BONUS_SRCS	=	speed_regulation.c \
			raycast_shootgun.c \
			events.c \
			keyboard.c \
			draw_utils.c \
			render_cross.c \
			render_gun.c \
			render_counter.c \
			render_lifebar.c \
			render_minimap.c

CC		=	@clang

CFLAGS		=	-Wall -Wextra -Werror -O3

RM		=	@rm -rf

MLX_DIR		=	./mlx_linux
LIB_DIR		=	./libft
INC_DIR		=	./includes

OBJS		=	$(addprefix srcs/, $(SRCS:.c=.o))
BONUS_OBJS	=	$(addprefix bonus/, $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o))

OK		=	[ \e[0;32mok\e[0m ]

.c.o:
		$(CC) $(CFLAGS) -I includes -I libft -I $(MLX_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(INC_DIR)/cub3d.h $(INC_DIR)/constants.h $(INC_DIR)/config.h
		@echo "Compiling MiniLibX..."
		@make -s -C $(MLX_DIR)
		@echo "$(OK) MiniLibX build."
		@make -s -C $(LIB_DIR)
		$(CC) $(CFLAGS) $(OBJS) -lm -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -o $@
		@echo "$(OK) cub3D build ! Ready to play."

all:		$(NAME)

bonus:		$(BONUS_OBJS) $(INC_DIR)/cub3d_bonus.h $(INC_DIR)/constants_bonus.h $(INC_DIR)/config_bonus.h
		@echo "Compiling MiniLibX..."
		@make -s -C $(MLX_DIR)
		@echo "$(OK) MiniLibX build."
		@make -s -C $(LIB_DIR)
		$(CC) $(CFLAGS) $(BONUS_OBJS) -lm -L$(LIB_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -o $(NAME)
		@echo "$(OK) cub3D with bonus build ! Ready to play."

clean:
		@echo "Cleaning..."
		$(RM) $(OBJS) $(BONUS_OBJS)
		@make clean -s -C $(LIB_DIR)
		@make clean -s -C $(MLX_DIR)
		@echo "$(OK) Cleaned !"

fclean:		clean
		@echo "Removing libft and cub3D..."
		$(RM) $(NAME)
		$(RM) $(LIB_DIR)/libft.a
		@echo "$(OK) Fcleaned !"

re:		fclean all

.PHONY:		all clean fclean re bonus
