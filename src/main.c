/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:11 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 21:38:41 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     main(int argc, char **argv)
{
    str_t *t;
    void    *img;
    int     w = 32;
    int     h = 32;
    char    **map;
    t = malloc(sizeof(str_t));
    map = load_tab(argv[1]);
    ft_puttab(map);
    ft_putchar('\n');
    t->map = map;
    t->X = ft_find_player(map, 'X');
    t->Y = ft_find_player(map, 'Y');
    t->ml = mlx_init();
    t->win = mlx_new_window(t->ml, 1920, 1080, "HELLO WORLD!");
    img = mlx_xpm_file_to_image(t->ml, "./texture/Grass32.xpm", &w, &h);
    mlx_put_image_to_window(t->ml, t->win, img, 0, 0);
    mlx_put_image_to_window(t->ml, t->win, img, 0, 32);
    mlx_hook(t->win, 2, 1L<<0, ft_close, t);
    mlx_loop(t->ml);
}
