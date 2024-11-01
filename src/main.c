/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:11 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 00:57:56 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     main(int argc, char **argv)
{
    Control_t   *Cts;
    Wind_t      *Ws;
    Map_t       *Ms;
    void    *img;
    int     w = 32;
    int     h = 32;
    char    **map;
    Cts = malloc(sizeof(Control_t));
    Ws = malloc(sizeof(Wind_t));
    Ms = malloc(sizeof(Map_t));
    Cts->WS = Ws;
    Cts->MS = Ms;
    map = load_tab(argv[1]);
    ft_puttab(map);
    ft_putchar('\n');
    Ms->map = map;
    Ms->X = ft_find_player(map, 'X');
    Ms->Y = ft_find_player(map, 'Y');
    Ws->ml = mlx_init();
    Ws->win = mlx_new_window(Ws->ml, (ft_strlen(map[0]) * 32), (ft_tablen(map) * 32), "ELAYM");
    img = mlx_xpm_file_to_image(Ws->ml, "./texture/Grass32.xpm", &w, &h);
    mlx_put_image_to_window(Ws->ml, Ws->win, img, 0, 0);
    mlx_put_image_to_window(Ws->ml, Ws->win, img, 0, 32);
    mlx_hook(Ws->win, 2, 1L<<0, ft_event, Cts);
    mlx_loop(Ws->ml);
}
