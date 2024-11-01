/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:20:11 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 21:21:15 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     main(int argc, char **argv)
{
    Control_t   *Cts;
    Wind_t      *Ws;
    Map_t       *Ms;
    Img_t       *Is;
    Anim_t      *As;
    Block_t     *Bs;
    Player_t    *Ps;
    char    **map;
    Cts = malloc(sizeof(Control_t));
    Ws = malloc(sizeof(Wind_t));
    Ms = malloc(sizeof(Map_t));
    Is = malloc(sizeof(Img_t));
    As = malloc(sizeof(Anim_t));
    Bs = malloc(sizeof(Block_t));
    Ps = malloc(sizeof(Player_t));
    Cts->WS = Ws;
    Cts->MS = Ms;
    Cts->IS = Is;
    Cts->AS = As;
    Cts->BS = Bs;
    Cts->PS = Ps;
    map = load_tab(argv[1]);
    Ms->map = map;
    Ms->X = ft_find_player(map, 'X');
    Ms->Y = ft_find_player(map, 'Y');
    Ws->ml = mlx_init();
    Ws->win = mlx_new_window(Ws->ml, (ft_strlen(map[0]) * 32), (ft_tablen(map) * 32), "ELAYM");
    load_block(Ws, Bs, map);
    load_image(Is, Ws);
    load_anime(As, Ws);
    load_player(Ps, Ws, Ms->X, Ms->Y);
    print_map(Cts);
    mlx_hook(Ws->win, 2, 1L<<0, ft_event, Cts);
    mlx_loop_hook(Ws->ml, ft_print_time, Cts);
    mlx_loop(Ws->ml);
}
