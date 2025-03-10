/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:58:44 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/09 21:40:21 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

int	main(int ac, char **av)
{
	Control_t	*ctrl;

	ctrl == malloc(sizeof(Control_t));
	if (ctrl == NULL)
		return (-1);
	load_data(&ctrl, ac, av);
	if (ctrl == NULL)
		return (-1);
	game_menu(ctrl);
}