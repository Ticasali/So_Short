/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:41:59 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/26 15:47:41 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_boss(t_Wind *wind, t_Play *play)
{
	play->yframe = 8;
	play->xframe = 0;
	play->imgr = load_boss_animation(wind, true);
	if (play->imgr == NULL)
		return (false);
	play->imgl = load_boss_animation(wind, false);
	if (play->imgl == NULL)
		return (false);
	return (true);
}

void	***load_boss_animation(t_Wind *wind, bool check)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 9);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_player_sprite(wind, check,
			"./texture/boss/attack/attack", 7);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_player_sprite(wind, check,
			"./texture/boss/attack_a/attacka", 8);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_player_sprite(wind, check,
			"./texture/boss/attack_s/attacks", 32);
	if (ret[2] == NULL)
		return (NULL);
	return (load_animation_boss(wind, check, ret));
}

void	***load_animation_boss(t_Wind *wind, bool check, void ***ret)
{
	ret[3] = load_player_sprite(wind, check,
			"./texture/boss/damage/damage", 7);
	if (ret[3] == NULL)
		return (NULL);
	ret[4] = load_player_sprite(wind, check,
			"./texture/boss/death/death", 10);
	if (ret[4] == NULL)
		return (NULL);
	ret[5] = load_player_sprite(wind, check,
			"./texture/boss/defend/defend", 12);
	if (ret[5] == NULL)
		return (NULL);
	ret[6] = load_player_sprite(wind, check,
			"./texture/boss/idle/idle", 8);
	if (ret[6] == NULL)
		return (NULL);
	ret[7] = load_player_sprite(wind, check,
			"./texture/boss/jump/jump", 16);
	if (ret[7] == NULL)
		return (NULL);
	ret[8] = load_player_sprite(wind, check,
			"./texture/boss/move/move", 8);
	if (ret[8] == NULL)
		return (NULL);
	return (ret);
}
