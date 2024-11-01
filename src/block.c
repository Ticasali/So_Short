/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:54:10 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 21:11:31 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    node_block(Wind_t *Ws, Block_t  *Bl, char **map, int y, int x)
{
    int     h;

    h = 32;
    Bl->next = malloc(sizeof(Block_t));
    Bl->c = map[y][x];
    Bl->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Stone32.xpm", &h, &h);
    Bl->Xmin = x * h;
    Bl->Xmax = x * h + h;
    Bl->Ymax = y * h + h;
    Bl->Ymin = y * h;
}

void    load_block(Wind_t *Ws, Block_t *Bl, char **map, char c)
{
    int     Cty;
    int     Ctx;

    Cty = -1;
    while (map[++Cty] != NULL)
    {
        Ctx = -1;
        while (map[Cty][++Ctx] != '\0')
        {
            if (map[Cty][Ctx] == c)
            {
                node_block(Ws, Bl, map, Cty, Ctx);
                Bl = Bl->next;
            }
        }
    }
    Bl = NULL;
}