/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:26:48 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/13 00:58:38 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	*load_image(t_Wind *wind, char *path, int x, int y)
{
	void	*ret;

	ret = mlx_xpm_file_to_image(wind->ml, path, &x, &y);
	free(path);
	return (ret);
}
