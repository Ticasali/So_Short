/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaym.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:00:53 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 14:42:39 by ticasali         ###   ########.fr       */
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
#include "../mlx_linux/mlx.h"
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

typedef struct  Anim_s
{
    char    c;
    int     t;
    int     tm;
    void    **img;
}Anim_t;

typedef struct  Control_s
{
    Wind_t  *WS;
    Map_t   *MS;
    Img_t   *IS;
    Anim_t  *AS;
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
void    ft_move_up(Map_t *Data);
void    ft_move_down(Map_t *Data);
void    ft_move_right(Map_t *Data);
void    ft_move_left(Map_t *Data);
void    load_image(Img_t *Im, Wind_t *Ws);
void    load_anime(Anim_t *Am, Wind_t *Ws);
void    print_map(Control_t *Cts);
void    ft_puttab(char **map);
void    ft_putstr(char *str);
void    ft_putchar(char c);

#endif