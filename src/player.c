/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:13:43 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 21:23:13 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    load_player(Player_t *Pl, Wind_t *Ws, int x, int y)
{
    int     h;

    h = 32;

    Pl->Xmin = x * h;
    Pl->Xmax = x * h + h;
    Pl->Ymin = y * h;
    Pl->Ymax = y * h + h;
    Pl->Speed = 1;
    Pl->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Player32.xpm", &h, &h);
}