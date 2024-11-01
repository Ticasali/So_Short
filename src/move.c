/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:06:39 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 02:38:55 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

void    ft_move_up(Map_t *Data)
{
    if (Data->map[Data->Y - 1][Data->X] == '0' || Data->map[Data->Y - 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y - 1][Data->X] = 'P';
        Data->Y--;
    }
}

void    ft_move_down(Map_t *Data)
{
    if (Data->map[Data->Y + 1][Data->X] == '0' || Data->map[Data->Y + 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y + 1][Data->X] = 'P';
        Data->Y++;
    }
}

void    ft_move_left(Map_t *Data)
{
    if (Data->map[Data->Y][Data->X - 1] == '0' || Data->map[Data->Y][Data->X - 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X - 1] = 'P';
        Data->X--;
    }
}

void    ft_move_right(Map_t *Data)
{
    if (Data->map[Data->Y][Data->X + 1] == '0' || Data->map[Data->Y][Data->X + 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X + 1] = 'P';
        Data->X++;
    }
}