/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:11:01 by ticasali          #+#    #+#             */
/*   Updated: 2024/11/01 02:21:18 by ticasali         ###   ########.fr       */
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
      ft_move_down(Cts->MS);
      print_map(Cts);
  }
  if (keycode == XK_Up)
  {
      ft_move_up(Cts->MS);
      print_map(Cts);
  }
  if (keycode == XK_Left)
  {
      ft_move_left(Cts->MS);
      print_map(Cts);
  }
  if (keycode == XK_Right)
  {
      ft_move_right(Cts->MS);
      print_map(Cts);
  }
  return (0);
}