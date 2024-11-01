/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:54:34 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 02:30:58 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    load_image(Img_t    *Im, Wind_t *Ws)
{
    int     w;
    int     h;

    w = 32;
    h = 32;
    Im->c = '1';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Stone32.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im = Im->next;
    Im->c = '0';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Grass32.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im = Im->next;
    Im->c = 'P';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Player32.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im = Im->next;
    Im->c = 'C';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Grass32.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im = Im->next;
    Im->c = 'E';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/Grass32.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im->next = NULL;
}

void    print_map(Control_t *Cts)
{
    int     Cty;
    int     Ctx;
    Img_t   *CpI;

    Cty = -1;
    while (Cts->MS->map[++Cty] != NULL)
    {
        Ctx = -1;
        while (Cts->MS->map[Cty][++Ctx] != '\0')
        {
            CpI = Cts->IS;
            while (CpI != NULL)
            {
                if (CpI->c == Cts->MS->map[Cty][Ctx])
                    mlx_put_image_to_window(Cts->WS->ml, Cts->WS->win, CpI->img, (32 * Ctx), (32 * Cty));
                CpI = CpI->next;
            }
        }
    }
}