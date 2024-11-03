/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:06:39 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/03 03:34:01 by ticasali         ###   ########.fr       */
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

int		ft_move_r(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->Xmax + Cts->PS->Speed) >= Cpy->Xmin) && ((Cts->PS->Xmax + Cts->PS->Speed) < Cpy->Xmax))
		&& ((Cts->PS->Ymin >= Cpy->Ymin && Cts->PS->Ymin < Cpy->Ymax)
		|| (Cts->PS->Ymax > Cpy->Ymin && Cts->PS->Ymax <= Cpy->Ymax)))
		{
			Cts->PS->Xmax = Cpy->Xmin;
			Cts->PS->Xmin = Cts->PS->Xmax - 32;
			return (1);
		}
		Cpy = Cpy->next;
	}
	return (0);
}

int		ft_move_l(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->Xmin - Cts->PS->Speed) <= Cpy->Xmax) && ((Cts->PS->Xmin - Cts->PS->Speed) > Cpy->Xmin))
		&& ((Cts->PS->Ymin >= Cpy->Ymin && Cts->PS->Ymin < Cpy->Ymax)
		|| (Cts->PS->Ymax > Cpy->Ymin && Cts->PS->Ymax <= Cpy->Ymax)))
		{
			Cts->PS->Xmin = Cpy->Xmax;
			Cts->PS->Xmax = Cts->PS->Xmin + 32;
			return (1);
		}
		Cpy = Cpy->next;
	}
	return (0);
}

int		ft_move_u(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->Ymin - Cts->PS->Speed) <= Cpy->Ymax) && ((Cts->PS->Ymin - Cts->PS->Speed) > Cpy->Ymin))
		&& ((Cts->PS->Xmin >= Cpy->Xmin && Cts->PS->Xmin < Cpy->Xmax)
		|| (Cts->PS->Xmax > Cpy->Xmin && Cts->PS->Xmax <= Cpy->Xmax)))
		{
			Cts->PS->Ymin = Cpy->Ymax;
			Cts->PS->Ymax = Cts->PS->Ymin + 32;
			return (1);
		}
		Cpy = Cpy->next;
	}
	return (0);
}

int		ft_move_d(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->Ymax + Cts->PS->Speed) >= Cpy->Ymin) && ((Cts->PS->Ymax + Cts->PS->Speed) < Cpy->Ymax))
		&& ((Cts->PS->Xmin >= Cpy->Xmin && Cts->PS->Xmin < Cpy->Xmax)
		|| (Cts->PS->Xmax > Cpy->Xmin && Cts->PS->Xmax <= Cpy->Xmax)))
		{
			Cts->PS->Ymax = Cpy->Ymin;
			Cts->PS->Ymin = Cts->PS->Ymax - 32;
			return (1);
		}
		Cpy = Cpy->next;
	}
	return (0);
}