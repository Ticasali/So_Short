/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparency.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:03:18 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/08 23:57:21 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

unsigned int	get_pixel_img(Transparency_t tr, int x, int y) {
	return (*(unsigned int *)((tr.addr
			+ (y * tr.line_len) + (x * tr.bpp / 8))));
}

void	put_img_to_img(Transparency_t dst, Transparency_t src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src.x) {
		j = 0;
		while (j < src.y) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	put_pixel_img(Transparency_t img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.x && y < img.y) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

Transparency_t	load_transparency(void *ptr, int x, int y)
{
	Transparency_t	tr;

	tr.addr = mlx_get_data_addr(ptr, &(tr.bpp), &(tr.line_len), &(tr.endian));
	tr.y = y;
	tr.x = x;
	return (tr);
}
