/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:30:56 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 01:26:45 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_font(Wind_t *wind, Font_t *font)
{
	font->ImgFont = load_font_ascii(wind, "/texture/font/", 26);
	if (font->ImgFont == NULL)
		return (false);
	font->ImgFontN = load_font_num(wind, "/texture/font/", 10);
	if (font->ImgFontN == NULL)
		return (false);
	return (true);
}

void	**load_font_ascii(Wind_t *wind, char const *path, int sprite)
{
	void	**ret;
	size_t	ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		ret[ct] = load_image(wind
				, font_path_concat(path, ct + 97, ".xpm"), 64, 64);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}

void	**load_font_num(Wind_t *wind, char const *path, int sprite)
{
	void	**ret;
	size_t	ct;

	ret = malloc(sizeof(void *) * sprite);
	if (ret == NULL)
		return (NULL);
	ct = 0;
	while (ct < sprite)
	{
		ret[ct] = load_image(wind
				, font_path_concat(path, ct + 48, ".xpm"), 64, 64);
		if (ret[ct] == NULL)
			return (NULL);
		++ct;
	}
	return (ret);
}
