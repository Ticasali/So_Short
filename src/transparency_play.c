/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency_play.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:58:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/25 16:30:36 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	put_img_to_img_play(t_Trspy dst, t_Trspy src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.x)
	{
		j = 0;
		while (j < src.y)
		{
			put_pixel_img_play(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	put_pixel_img_play(t_Trspy img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x444945) {
		
		return ;
	}
	if (x >= 0 && y >= 0 && x < img.x && y < img.y)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
