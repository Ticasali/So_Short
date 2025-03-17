# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 09:27:00 by ticasali          #+#    #+#              #
#    Updated: 2025/03/17 22:23:26 by ticasali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Elaym

DIR_SRCS =			src

SRCS		=	src/main.c				\
				src/attack_hitbox.c		\
				src/background_border.c	\
				src/background_link.c	\
				src/background.c		\
				src/button_click_game.c	\
				src/check_block_top.c	\
				src/compare.c			\
				src/concat_path.c		\
				src/copy.c				\
				src/display_back.c		\
				src/display_block.c		\
				src/display_coin.c		\
				src/display_enemis.c	\
				src/display_player.c	\
				src/enemis_move.c		\
				src/error.c				\
				src/find_player.c		\
				src/ft_split.c			\
				src/game_menu.c			\
				src/game_render.c		\
				src/game.c				\
				src/get_time.c			\
				src/gravity.c			\
				src/ia_enemis.c			\
				src/itoa.c				\
				src/key_event_game.c	\
				src/key_pressed_game.c	\
				src/key_release_game.c	\
				src/key_input_login.c	\
				src/length.c			\
				src/load_back.c			\
				src/load_block.c		\
				src/load_button.c		\
				src/load_coin_sprite.c	\
				src/load_coin.c			\
				src/load_enemis_sprite.c\
				src/load_ennemis.c		\
				src/load_font.c			\
				src/load_image_block.c	\
				src/load_image.c		\
				src/load_map.c			\
				src/load_menu_struct.c	\
				src/load_new_game.c		\
				src/load_player_pos.c	\
				src/load_player_sprite.c\
				src/load_player.c		\
				src/load_stat.c			\
				src/load_struct.c		\
				src/load_window.c		\
				src/login.c				\
				src/menu_sprite_button.c\
				src/mlx_reset.c			\
				src/mouse_event_game.c	\
				src/move.c				\
				src/movement.c			\
				src/parsing_border.c	\
				src/parsing_char.c		\
				src/parsing_length.c	\
				src/parsing_path.c		\
				src/parsing.c			\
				src/player_attack.c		\
				src/player_damage.c		\
				src/player_move.c		\
				src/print_char.c		\
				src/print_number.c		\
				src/print_string.c		\
				src/setup_game.c		\
				src/transparency.c		\
			
DIR_OBJS =			.objs
OBJS =				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

CC	=	cc

CFLAGS	= -Wextra -Wall -Werror -O3

all:	$(NAME)

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I./include

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) -r $(DIR_OBJS)

fclean:	clean
	make clean -C mlx_linux/
	rm -f $(NAME)

re :	fclean all