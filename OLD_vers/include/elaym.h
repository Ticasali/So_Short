/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaym.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:00:53 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 01:32:42 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELAYM
#define ELAYM

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "../../mlx_linux/mlx.h"
#include <time.h>

typedef struct Wind_s
{
    void    *ml;
    void    *win;
}Wind_t;

typedef struct  Map_s
{
    char    **map;
    int     X;
    int     Y;
}Map_t;

typedef struct  Img_s
{
    char    c;
    void    *img;
    struct  Img_s   *next;
}Img_t;

typedef struct  Block_s
{
    char    c;
    int     Xmin;
    int     Xmax;
    int     Ymin;
    int     Ymax;
    void    *img;
    struct  Block_s *next;
}Block_t;

typedef struct  Player_s
{
    int     Xmin;
    int     Xmax;
    int     Ymax;
    int     Ymin;
    int     Speed;
	int 	Up;
	int		Move;
	int		Up_Val;
    void    *img;
}Player_t;

typedef struct  Anim_s
{
    char    c;
    int     t;
    int     tm;
    void    **img;
}Anim_t;

typedef struct  Control_s
{
    int     Statement;
    Wind_t  *WS;
    Map_t   *MS;
    Img_t   *IS;
    Anim_t  *AS;
    Block_t *BS;
    Player_t*PS;
}Control_t;

char    **load_tab(const char *path);
char    **ft_split(char *str);
char    *ft_strcpy_dup(char *str);
int     ft_find_player(char **map, char c);
int     ft_count_line(char *str);
int     ft_event(int keycode, Control_t *Cts);
int     ft_print_time(Control_t *Cts);
int     ft_strlen(char *str);
int     ft_tablen(char **tab);
int     ft_move_up(Map_t *Data);
int     ft_move_down(Map_t *Data);
int     ft_move_right(Map_t *Data);
int     ft_move_left(Map_t *Data);
int		ft_move_r(Control_t *Cts);
int		ft_move_l(Control_t *Cts);
int		ft_move_d(Control_t *Cts);
int		ft_move_u(Control_t *Cts);
void    load_image(Img_t *Im, Wind_t *Ws);
void    load_anime(Anim_t *Am, Wind_t *Ws);
void	load_block(Wind_t *Ws, Block_t *Bl, char **map, char c);
void	load_player(Player_t *Ps, Wind_t *Ws, int x, int y);
void    print_map(Control_t *Cts);
void	node_block(Wind_t *Ws, Block_t *Bl, char **map, int y, int x);
void    ft_puttab(char **map);
void    ft_putstr(char *str);
void    ft_putchar(char c);

#endif