/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:29:40 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/08 02:40:43 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool		ft_move_r(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BlS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->XmaxH + Cts->PS->Speed) >= Cpy->Xmin)
		&& ((Cts->PS->XmaxH + Cts->PS->Speed) < Cpy->Xmax))
		&& ((Cts->PS->YminH >= Cpy->Ymin && Cts->PS->YminH < Cpy->Ymax)
		|| (Cts->PS->YmaxH > Cpy->Ymin && Cts->PS->YmaxH <= Cpy->Ymax)))
		{
			Cts->PS->XmaxH = Cpy->Xmin;
			Cts->PS->XminH = Cts->PS->XmaxH - 32;
			return (true);
		}
		Cpy = Cpy->next;
	}
	return (false);
}

bool	ft_move_l(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BlS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->XminH - Cts->PS->Speed) <= Cpy->Xmax)
		&& ((Cts->PS->XminH - Cts->PS->Speed) > Cpy->Xmin))
		&& ((Cts->PS->YminH >= Cpy->Ymin && Cts->PS->YminH < Cpy->Ymax)
		|| (Cts->PS->YmaxH > Cpy->Ymin && Cts->PS->YmaxH <= Cpy->Ymax)))
		{
			Cts->PS->XminH = Cpy->Xmax;
			Cts->PS->XmaxH = Cts->PS->XminH + 32;
			return (true);
		}
		Cpy = Cpy->next;
	}
	return (false);
}

bool	ft_move_u(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BlS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->YminH - Cts->PS->Speed) <= Cpy->Ymax) && ((Cts->PS->YminH - Cts->PS->Speed) > Cpy->Ymin))
		&& ((Cts->PS->XminH >= Cpy->Xmin && Cts->PS->XminH < Cpy->Xmax)
		|| (Cts->PS->XmaxH > Cpy->Xmin && Cts->PS->XmaxH <= Cpy->Xmax)))
		{
			Cts->PS->YminH = Cpy->Ymax;
			Cts->PS->YmaxH = Cts->PS->YminH + 32;
			Cts->PS->Up = -1;
			return (true);
		}
		Cpy = Cpy->next;
	}
	return (false);
}

bool	ft_move_d(Control_t *Cts)
{
	Block_t *Cpy;

	Cpy = Cts->BlS;
	while (Cpy != NULL)
	{
		if ((((Cts->PS->YmaxH + Cts->PS->Speed) >= Cpy->Ymin) && ((Cts->PS->YmaxH + Cts->PS->Speed) < Cpy->Ymax))
		&& ((Cts->PS->XminH >= Cpy->Xmin && Cts->PS->XminH < Cpy->Xmax)
		|| (Cts->PS->XmaxH > Cpy->Xmin && Cts->PS->XmaxH <= Cpy->Xmax)))
		{
			Cts->PS->YmaxH = Cpy->Ymin;
			Cts->PS->YminH = Cts->PS->YmaxH - 32;
			return (true);
		}
		Cpy = Cpy->next;
	}
	return (false);
}