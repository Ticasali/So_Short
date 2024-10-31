/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elaym.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:00:53 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 18:08:05 by ticasali         ###   ########.fr       */
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

typedef struct mlx_s
{
    void    *ml;
    void    *win;
    char    **map;
    int     X;
    int     Y;
}str_t;

char    **load_tab(const char *path);
char    **ft_split(char *str);
char    *ft_strcpy_dup(char *str);
int     ft_find_player(char **map, char c);
int     ft_count_line(char *str);
int     ft_close(int keycode, str_t *I);
int     ft_strlen(char *str);
int     ft_tablen(char **tab);
void    ft_move_up(str_t *Data);
void    ft_move_down(str_t *Data);
void    ft_move_right(str_t *Data);
void    ft_move_left(str_t *Data);
void    ft_puttab(char **map);
void    ft_putstr(char *str);
void    ft_putchar(char c);

#endif