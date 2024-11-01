/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:11 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 02:27:41 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     main(int argc, char **argv)
{
    Control_t   *Cts;
    Wind_t      *Ws;
    Map_t       *Ms;
    Img_t       *Is;
    char    **map;
    Cts = malloc(sizeof(Control_t));
    Ws = malloc(sizeof(Wind_t));
    Ms = malloc(sizeof(Map_t));
    Is = malloc(sizeof(Img_t));
    Cts->WS = Ws;
    Cts->MS = Ms;
    Cts->IS = Is;
    map = load_tab(argv[1]);
    ft_puttab(map);
    ft_putchar('\n');
    Ms->map = map;
    Ms->X = ft_find_player(map, 'X');
    Ms->Y = ft_find_player(map, 'Y');
    Ws->ml = mlx_init();
    Ws->win = mlx_new_window(Ws->ml, (ft_strlen(map[0]) * 32), (ft_tablen(map) * 32), "ELAYM");
    load_image(Is, Ws);
    print_map(Cts);
    mlx_hook(Ws->win, 2, 1L<<0, ft_event, Cts);
    mlx_loop(Ws->ml);
}
