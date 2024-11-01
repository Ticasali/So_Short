/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:11:01 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 15:26:50 by ticasali         ###   ########.fr       */
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
  if (keycode == XK_Down)
  {
      if (ft_move_down(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
  }
  if (keycode == XK_Up)
  {
      if (ft_move_up(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
  }
  if (keycode == XK_Left)
  {
      if (ft_move_left(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
  }
  if (keycode == XK_Right)
  {
      if (ft_move_right(Cts->MS) == 1)
      {
        mlx_destroy_window(Cts->WS->ml, Cts->WS->win);
        exit(0);
      }
  }
  return (0);
}