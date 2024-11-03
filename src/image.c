/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 01:54:34 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/03 03:44:28 by ticasali         ###   ########.fr       */
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
    Im->c = 'E';
    Im->img = mlx_xpm_file_to_image(Ws->ml, "./texture/End.xpm", &w, &h);
    Im->next = malloc(sizeof(Img_t));
    Im->next = NULL;
}

void    load_anime(Anim_t  *Am, Wind_t *Ws)
{
    int     w;
    int     h;

    w = 32;
    h = 32;
    Am->t = 0;
    Am->tm = 10;
    Am->c = 'C';
    Am->img = malloc(sizeof(void *) * 10);
    Am->img[0] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon1.xpm", &w, &h);
    Am->img[1] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon2.xpm", &w, &h);
    Am->img[2] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon2.xpm", &w, &h);
    Am->img[3] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon2.xpm", &w, &h);
    Am->img[4] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon2.xpm", &w, &h);
    Am->img[5] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon3.xpm", &w, &h);
    Am->img[6] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon3.xpm", &w, &h);
    Am->img[7] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon3.xpm", &w, &h);
    Am->img[8] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon3.xpm", &w, &h);
    Am->img[9] = mlx_xpm_file_to_image(Ws->ml, "./texture/Icon4.xpm", &w, &h);
}

void    print_map(Control_t *Cts)
{
    int     Cty;
    int     Ctx;
    Img_t   *CpI;

    Cty = -1;
	if (Cts->PS->Up == 1)
	{
		if (Cts->PS->Up_Val < Cts->PS->Ymax)
		{
			ft_move_u(Cts);
			Cts->PS->Ymin -= 1;
			Cts->PS->Ymax -= 1;
		}
		else
			Cts->PS->Up = -1;
	}
	else
	{
		if (ft_move_d(Cts) == 1)
			Cts->PS->Up = 0;
		else
			Cts->PS->Up = -1;
	}
	if (Cts->PS->Up == -1)
	{
		Cts->PS->Ymin += 1;
		Cts->PS->Ymax += 1;
	}
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
                if (Cts->AS->c == Cts->MS->map[Cty][Ctx])
                {
                    if (Cts->AS->t < Cts->AS->tm)
                    {
                        mlx_put_image_to_window(Cts->WS->ml, Cts->WS->win, Cts->AS->img[Cts->AS->t], (32 * Ctx), (32 * Cty));
                        Cts->AS->t++;
                    }
                    else
                        Cts->AS->t = 0;
                }
                CpI = CpI->next;
            }
        }
    }
    mlx_put_image_to_window(Cts->WS->ml, Cts->WS->win, Cts->PS->img, Cts->PS->Xmin, Cts->PS->Ymin);
}

int    ft_print_time(Control_t *Cts)
{
    sleep(0.1);
    print_map(Cts);
    return (0);
}