/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:18:56 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:40:15 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_data(t_Control *ctrl, int ac, char **av)
{
	t_Wind	*wind;
	t_Play	*play;
	t_Play	*boss;
	t_Font	*font;

	wind = malloc(sizeof(t_Wind));
	play = malloc(sizeof(t_Play));
	font = malloc(sizeof(t_Font));
	boss = malloc(sizeof(t_Play));
	if (wind == NULL || play == NULL || boss == NULL)
		return (false);
	ctrl->ws = wind;
	ctrl->ps = play;
	ctrl->fs = font;
	ctrl->bs = boss;
	ctrl->ms = load_map(ac, av);
	if (ctrl->ms == NULL)
		write(1, "m", 1);
	if	(load_window(wind) == false)
		write(1, "w", 1);
	if (load_player(wind, play) == false)
		write(1, "p", 1);
	if (load_boss(wind, boss) == false)
		write(1, "b", 1);
	if (load_font(wind, font) == false)
		write(1, "f", 1);
	if (wind == NULL || play == NULL || boss == NULL)
	{
		write(1, "a", 1);
	}
	ctrl->bas = load_back(wind, ac);
	ctrl->statement = 0;
	ctrl->login = malloc(sizeof(char) * 9);
	if (ctrl->login == NULL)
		return (false);
	set_zero(ctrl->login, 9);
//	ctrl->save = load_tab("save");
//	if (ctrl->save == NULL)
//		return (false);
	ctrl->paral = false;
	ctrl->x_dif = 0;
	ctrl->y_dif = 0;
	return (true);
}
