/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:35:50 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/16 07:41:09 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*load_img_block(t_Wind *wind, int *pos, bool check, char const *str)
{
	char const	*path;
	char		*map;
	char		*final_path;
	int			val;
	void		*ret;

	path = "./texture/Block/";
	map = ft_itoa(pos[2]);
	if (map == NULL)
		return (NULL);
	if (check == true)
		final_path = block_path_concat(path, map, 'b', str);
	if (check == false)
		final_path = block_path_concat(path, map, 'B', str);
	if (final_path == NULL)
	{
		free(map);
		return (NULL);
	}
	val = 64;
	ret = mlx_xpm_file_to_image(wind->ml, final_path, &val, &val);
	free(final_path);
	free(map);
	return (ret);
}
