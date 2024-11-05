/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:11:01 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/03 05:12:43 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     ft_event(int keycode, Control_t *Cts)
{
  if (keycode == XK_Escape)
  {
      mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
      exit(0);
  }
  /*
  if (keycode == XK_Down)
  {
	if (ft_move_d(Cts) == 0)
	{
		Cts->PS->Ymin += Cts->PS->Speed;
		Cts->PS->Ymax += Cts->PS->Speed;
	}
	//ft_move_d(Cts);
      if (ft_move_down(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
  }
  */
  if (keycode == XK_Up)
  {
	if (Cts->PS->Up == 0)
	{
		if (Cts->PS->Up == 0)
		{
			Cts->PS->Up_Val = Cts->PS->Ymax - 75;
			Cts->PS->Up = 1;
		}
		if (ft_move_u(Cts) == 0)
		{
			Cts->PS->Ymin -= 1;
			Cts->PS->Ymax -= 1;
		}
	}
	/*
      if (ft_move_up(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
	  */
  }
  if (keycode == XK_Left)
  {
	if (ft_move_l(Cts) == 0)
	{
		Cts->PS->Xmin -= Cts->PS->Speed;
		Cts->PS->Xmax -= Cts->PS->Speed;
	}
	/*
      if (ft_move_left(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
	  */
  }
  if (keycode == XK_Right)
  {
	if (ft_move_r(Cts) == 0)
	{
		Cts->PS->Xmin += Cts->PS->Speed;
		Cts->PS->Xmax += Cts->PS->Speed;
	}
	/*
      if (ft_move_right(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
	  */
  }
  return (0);
}