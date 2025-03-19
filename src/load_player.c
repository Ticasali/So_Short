/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:51:55 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/19 12:14:20 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_player(t_Wind *wind, t_Play *play)
{
	play->yframe = 6;
	play->xframe = 0;
	play->player = true;
	play->imgr = load_player_animation(wind, true);
	if (play->imgr == NULL)
		return (false);
	play->imgl = load_player_animation(wind, false);
	if (play->imgl == NULL)
		return (false);
	play->img_r = load_player_animation_bis(wind, true);
	if (play->imgr == NULL)
		return (false);
	play->img_l = load_player_animation_bis(wind, false);
	if (play->imgl == NULL)
		return (false);
	play->frame = load_frame_player();
	if (play->frame == NULL)
		return (false);
	return (true);
}

void	***load_player_animation(t_Wind *wind, bool check)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 9);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_player_sprite(wind, check,
			"./texture/player/attack/attack", 11);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_player_sprite(wind, check,
			"./texture/player/attack_a/attacka", 8);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_player_sprite(wind, check,
			"./texture/player/attack_s/attacks", 18);
	if (ret[2] == NULL)
		return (NULL);
	return (load_animation_player(wind, check, ret));
}

void	***load_animation_player(t_Wind *wind, bool check, void ***ret)
{
	ret[3] = load_player_sprite(wind, check,
			"./texture/player/damage/damage", 6);
	if (ret[3] == NULL)
		return (NULL);
	ret[4] = load_player_sprite(wind, check,
			"./texture/player/death/death", 13);
	if (ret[4] == NULL)
		return (NULL);
	ret[5] = load_player_sprite(wind, check,
			"./texture/player/defend/defend", 10);
	if (ret[5] == NULL)
		return (NULL);
	ret[6] = load_player_sprite(wind, check,
			"./texture/player/idle/idle", 8);
	if (ret[6] == NULL)
		return (NULL);
	ret[7] = load_player_sprite(wind, check,
			"./texture/player/jump/jump", 20);
	if (ret[7] == NULL)
		return (NULL);
	ret[8] = load_player_sprite(wind, check,
			"./texture/player/move/move", 8);
	if (ret[8] == NULL)
		return (NULL);
	return (ret);
}
