/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:06:39 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 22:00:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

/*
int    ft_move_up(Map_t *Data)
{
    if (Data->map[Data->Y - 1][Data->X] == '0' || Data->map[Data->Y - 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y - 1][Data->X] = 'P';
        Data->Y--;
    }
    else if (Data->map[Data->Y - 1][Data->X] == 'E')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y - 1][Data->X] = 'E';
        Data->Y--;
    }
    if (Data->map[Data->Y][Data->X] == 'E')
        return (1);
    return (0);
}

int    ft_move_down(Map_t *Data)
{
    if (Data->map[Data->Y + 1][Data->X] == '0' || Data->map[Data->Y + 1][Data->X] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y + 1][Data->X] = 'P';
        Data->Y++;
    }
    else if (Data->map[Data->Y + 1][Data->X] == 'E')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y + 1][Data->X] = 'E';
        Data->Y++;
    }
    if (Data->map[Data->Y][Data->X] == 'E')
        return (1);
    return (0);
}

int    ft_move_left(Map_t *Data)
{
    if (Data->map[Data->Y][Data->X - 1] == '0' || Data->map[Data->Y][Data->X - 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X - 1] = 'P';
        Data->X--;
    }
    else if (Data->map[Data->Y][Data->X - 1] == 'E')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X - 1] = 'E';
        Data->X--;
    }
    if (Data->map[Data->Y][Data->X] == 'E')
        return (1);
    return (0);
}

int    ft_move_right(Map_t *Data)
{
    if (Data->map[Data->Y][Data->X + 1] == '0' || Data->map[Data->Y][Data->X + 1] == 'C')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X + 1] = 'P';
        Data->X++;
    }
    else if (Data->map[Data->Y][Data->X + 1] == 'E')
    {
        Data->map[Data->Y][Data->X] = '0';
        Data->map[Data->Y][Data->X + 1] = 'E';
        Data->X++;
    }
    if (Data->map[Data->Y][Data->X] == 'E')
        return (1);
    return (0);
}
*/

void	ft_move_r(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BS;
	while (Cpy != NULL)
	{
		if ((Cts->PS->Xmax + Cts->PS->Speed > Cpy->Xmin) && (Cts->PS->Ymin < ) && ())
			return (1);
		Cpy = Cpy->next;
	}
	return (0);
}