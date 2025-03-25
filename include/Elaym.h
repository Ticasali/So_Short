/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elaym.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:14:48 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/25 15:56:48 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELAYM_H
# define ELAYM_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <time.h>
# include <stdbool.h>

typedef struct Wind_s
{
	void	*ml;
	void	*win;
}	t_Wind;

typedef struct Block_s
{
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	void			*img;
	void			*imgp;
	struct Block_s	*next;
}	t_Block;

typedef struct Back_s
{
	void			*img;
	void			*imgp;
	struct Back_s	*next;
}	t_Back;

typedef struct Map_s
{
	int				id;
	char			**map;
	int				x;
	int				y;
	struct Map_s	*next;
}	t_Map;

typedef struct Trspy_s
{
	int		y;
	int		x;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_Trspy;

typedef struct Stat_s
{
	int		hp;
	double	damage;
	int		speed;
	//Inventaire
	//ressources
}	t_Stat;

typedef struct Play_s
{
	int				x;
	int				y;
	int				xminh;
	int				xmaxh;
	int				ymaxh;
	int				yminh;
	int				up;
	int				up_val;
	int				yframe;
	int				xframe;
	bool			move;
	bool			left;
	bool			right;
	bool			dir;
	bool			player;
	void			***imgr;
	void			***imgl;
	t_Stat			*stat;
}	t_Play;

typedef struct Enemi_s
{
	int				xmin;
	int				xmax;
	int				ymax;
	int				ymin;
	int				speed;
	bool			dir;
	int				yframe;
	int				xframe;
	bool			life;
	void			***imgr;
	void			***imgl;
	struct Enemi_s	*next;
}	t_Enemi;

typedef struct Coin_s
{
	int				xmin;
	int				ymin;
	int				xmax;
	int				ymax;
	int				frame;
	bool			life;
	void			**img;
	struct Coin_s	*next;
}	t_Coin;

typedef struct Spell_s
{
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		speed;
	void	**img;
}	t_Spell;

typedef struct Menu_s
{
	void	**background;
	int		frameback;
	void	***button;
	int		*framebutton;
	double	time;
	int		xmouse;
	int		ymouse;
	int		statement;
	int		try;
}	t_Menu;

typedef struct Font_s
{
	void	**imgfont;
	void	**imgfontn;
}	t_Font;

typedef	struct Inter_s
{
	void	*water;
	void	*fire;
	void	*banner;
}	t_Inter;

typedef struct Control_s
{
	size_t	statement;
	char	*login;
	char	**save;
	bool	paral;
	int		x_dif;
	int		y_dif;
	t_Wind	*ws;
	t_Map	*ms;
	t_Block	*bls;
	t_Play	*ps;
	t_Play	*bs;
	t_Enemi	*es;
	t_Back	*bas;
	t_Menu	*mes;
	t_Font	*fs;
	t_Coin	*cs;
}	t_Control;

t_Enemi	*load_enemis(t_Wind *wind, t_Map *map);

t_Back	*create_node(t_Wind	*wind, char *path, char *pathp);
t_Back	*load_back(t_Wind *wind, int ac);

t_Coin	*load_coin(t_Wind *wind, t_Map *map);

t_Menu	*load_menu_struct(t_Wind *wind);

t_Stat	*load_stat(void);

t_Trspy	load_transparency(void *ptr, int x, int y);

t_Map	*load_map(int ac, char **av);
t_Map	*pars_map_block(t_Map **map, size_t ct_m);
t_Map	*pars_map_coin(t_Map **map, size_t ct_m);

t_Block	*load_block(t_Wind *wind, t_Map *map, int ct_map);

void	***load_button_menu(t_Wind *wind);
void	***load_enem_animation(t_Wind *wind, bool check);
void	***load_animation_player(t_Wind *wind, bool check, void ***ret);
void	***load_player_animation(t_Wind *wind, bool check);

void	**load_button_menu_sprite(t_Wind *wind, char const *path, int sprite);
void	**load_coin_sprite(t_Wind *wind);
void	**load_enem_sprite(t_Wind *wind, bool check, char *path, int sprite);
void	**load_font_ascii(t_Wind *wind, char const *path, int sprite);
void	**load_font_num(t_Wind *wind, char const *path, int sprite);
void	**load_back_menu_img(t_Wind *wind, char const *path, int sprite);
void	**load_player_sprite(t_Wind *wind, bool c, char *path, int sprite);

void	*gen_background_border(t_Wind *wind, t_Map *map, int *pos, bool check);
void	*gen_background_corner(t_Wind *wind, t_Map *map, int *pos, bool check);
void	*gen_background_three_link(t_Wind *wind, t_Map *map, int *pos, bool c);
void	*gen_background_one_link(t_Wind *wind, t_Map *map, int *pos, bool c);
void	*gen_background(t_Wind *wind, t_Map *map, int *pos, bool check);
void	*gen_back_spe_case(t_Wind *wind, t_Map *map, int *pos, bool check);
void	*ft_free_all(char **tab);
void	*load_img_block(t_Wind *wind, int *pos, bool check, char const *str);
void	*load_image(t_Wind *wind, char *path, int x, int y);

int		*load_frame_button(void);

char	**tab_cpy(char **tab);
char	**ft_split(char *str, char c);
char	**load_tab(const char *path);
char	**flood_map(char **map);

char	*font_path_concat(char const *path, char ascii, char const *file);
char	*menu_path_concat(char const *path, char *num, char const *file);
char	*player_path_concat(char const *path, char c, char *n, char const *fil);
char	*block_path_concat(char const *path, char *m, char c, char const *str);
char	*back_path_concat(char const *path, char *m, char c, char const *str);
char	*ft_strdup(char *str, char c);
char	*ft_strcpy(char	*str);
char	*ft_revstr(char *ret);
char	*ft_itoa(int n);

double	atod(char *str);
double	get_time(void);

size_t	get_pixel_img(t_Trspy tr, int x, int y);

size_t	find_player(char **map, bool check);
size_t	ft_count_words(char *str, char c);
size_t	ft_allocated_value(int n);
size_t	ft_strlen(char const *str);
size_t	ft_tablen(char **tab);

int		ft_strcmp(char *s1, char *s2);
int		escape_touch(int keycode, t_Control *ctrl);
int		mlx_reset(t_xvar *xvar);
int		check_click_menu(int button, int x, int y, t_Control *ctrl);
int		menu_render(t_Control *ctrl);
int		mouse_event_game(int keycode, t_Control *ctrl);
int		key_pressed_game(int keycode, t_Control *ctrl);
int		key_release_game(int keycode, t_Control *ctrl);
int		key_event_game(int keycode, t_Control *ctrl);
int		game_render(t_Control *ctrl);
int		keyboard_input(int keycode, t_Control *ctrl);
int		keyboard_input_two(int keycode, t_Control *ctrl);
int		keyboard_input_three(int keycode, t_Control *ctrl);
int		load_new_game_render(t_Control *ctrl);
int		button_click(int button, int x, int y, t_Control *ctrl);

bool	add_node_block(t_Wind *wind, t_Block **block, t_Map *map, int *pos);
bool	load_block_struct(t_Control *ctrl);
bool	add_back_coin(t_Coin *node, t_Control *ctrl);
bool	add_node_coin(t_Wind *wind, int *pos, t_Coin **coin);
bool	load_coin_struct(t_Control *ctrl);
bool	load_enemis_sprite(t_Wind *wind, t_Enemi *enem);
bool	load_enemis_struct(t_Control *ctrl);
bool	load_font(t_Wind *wind, t_Font *font);
bool	add_node_map(t_Map **map, size_t id, char **tab);
bool	load_player(t_Wind *wind, t_Play *play);
bool	load_window(t_Wind	*wind);
bool	check_login(t_Control *ctrl);
bool	ft_move_down(t_Control *ctrl);
bool	ft_move_up(t_Control *ctrl);
bool	ft_move_left(t_Control *ctrl);
bool	ft_move_right(t_Control *ctrl);
bool	check_border_left_right(char **map, size_t x);
bool	check_border_top_bot(char **map, size_t y);
bool	check_border(char **map);
bool	check_double_char(char **map);
bool	check_need_char(char **map);
bool	check_char(char **map);
bool	valid_char(char c);
bool	check_lenght(char **map);
bool	change_map(char **map, int y, int x);
bool	check_map_end(char **map);
bool	check_map_coin(char **map);
bool	check_pathfinding(char **map);
bool	check_parsing(t_Control *ctrl);
bool	load_data(t_Control *ctrl, int ac, char **av);
bool	add_node_enem(t_Wind *wind, int *pos, t_Enemi **enem);
bool	e_move_down(t_Control *ctrl, t_Enemi *en);
bool	e_move_left(t_Control *ctrl, t_Enemi *en);
bool	e_move_right(t_Control *ctrl, t_Enemi *en);
bool	check_block_top(t_Control *ctrl);

void	display_back(t_Control *ctrl);
void	error(char *str, t_Control *ctrl);
void	game_menu(t_Control *ctrl);
void	game(t_Control *ctrl);
void	key_event_game_up(t_Control *ctrl);
void	add_back(t_Back	**back, t_Back	*node, int ct);
void	load_new_game(t_Control *ctrl);
void	load_pos_player(t_Control *ctrl);
void	del_char_login(t_Control *ctrl);
void	add_char_login(t_Control *ctrl, char c);
void	menu_animation_button(t_Control *ctrl);
void	menu_animation_button_incr(t_Control *ctrl, int check);
void	menu_animation_button_reset(t_Control *ctrl);
void	print_number(t_Control *ctrl, char *str, int x, int y);
void	print_string(t_Control *ctrl, char *str, int x, int y);
void	start_game_setup(t_Control *ctrl);
void	put_pixel_img(t_Trspy img, int x, int y, int color);
void	put_img_to_img(t_Trspy dst, t_Trspy src, int x, int y);
void	set_zero(char *str, size_t num);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puttab(char **tab);
void	display_player(t_Control *ctrl);
void	display_block(t_Control *ctrl);
void	display_coin(t_Control *ctrl);
void	key_event_game_right(t_Control *ctrl);
void	key_event_game_left(t_Control *ctrl);
void	movement(t_Control *ctrl);
void	gravity(t_Control *ctrl);
void	display_player_attack(t_Control *ctrl);
void	display_player_attack_a(t_Control *ctrl);
void	display_player_attack_s(t_Control *ctrl);
void	display_player_damage(t_Control *ctrl);
void	display_player_death(t_Control *ctrl);
void	display_player_defend(t_Control *ctrl);
void	display_player_idle(t_Control *ctrl);
void	display_player_jump(t_Control *ctrl);
void	display_player_move(t_Control *ctrl);
void	display_enemis(t_Control *ctrl);
void	enem_move_down(t_Control *ctrl);
void	movement_player(t_Control *ctrl);
void	display_en_attack(t_Control *ctrl, t_Enemi *cpy);
void	display_en_damage(t_Control *ctrl, t_Enemi *cpy);
void	display_en_death(t_Control *ctrl, t_Enemi *cpy);
void	display_en_move(t_Control *ctrl, t_Enemi *cpy);
void	ia_enemis(t_Control *ctrl, t_Enemi *en);
void	movement_enemis(t_Control *ctrl);
void	check_enemis_damage(t_Control *ctrl, int range);
void	check_enemis_hitbox(t_Control *ctrl, t_Enemi *en, int range);
void	load_scroll(t_Control *ctrl);
void	reset_window(t_Control *ctrl);
void	put_img_to_img_play(t_Trspy dst, t_Trspy src, int x, int y);
void	put_pixel_img_play(t_Trspy img, int x, int y, int color);
void	hitbox_coin_right(t_Control *ctrl);
void	hitbox_coin_left(t_Control *ctrl);
void	hitbox_coin_up(t_Control *ctrl);
void	hitbox_coin_down(t_Control *ctrl);

#endif