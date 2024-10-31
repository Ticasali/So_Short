/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:11:01 by ticasali          #+#    #+#             */
/*   Updated: 2024/10/31 15:04:59 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/elaym.h"

int     ft_close(int keycode, str_t *I)
{
  if (keycode == XK_Escape)
  {
      mlx_destroy_window(I->ml, I->win);
      exit(0);
  }
  if (keycode == XK_Down)
      ft_move_down(I);
  if (keycode == XK_Up)
      ft_move_up(I);
  if (keycode == XK_Left)
      ft_move_left(I);
  if (keycode == XK_Right)
      ft_move_right(I);
  return (0);
}