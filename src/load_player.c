/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:51:55 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/11 02:44:54 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

bool	load_player(Wind_t *wind, Player_t *play)
{
	play->Zframe = 0;
	play->Yframe = 0;
	play->Xframe = 0;
	play->imgR = load_player_animation(wind, true);
	if (play->imgR == NULL)
		return (false);
	play->imgL = load_player_animation(wind, false);
	if (play->imgL == NULL)
		return (false);
	return (true);
}

void	***load_player_animation(Wind_t *wind, bool check)
{
	void	***ret;

	ret = malloc(sizeof(void **) * 9);
	if (ret == NULL)
		return (NULL);
	ret[0] = load_player_sprite(wind, check, "/texture/player/attack/attack", 11);
	if (ret[0] == NULL)
		return (NULL);
	ret[1] = load_player_sprite(wind, check, "/texture/player/attack_a/attacka", 8);
	if (ret[1] == NULL)
		return (NULL);
	ret[2] = load_player_sprite(wind, check, "/texture/player/attack_s/attacks", 18);
	if (ret[2] == NULL)
		return (NULL);
	return (load_animation_player(wind, check, ret));
}

void	***load_animation_player(Wind_t *wind, bool check, void ***ret)
{
	ret[3] = load_player_sprite(wind, check, "/texture/player/damage/damage", 6);
	if (ret[3] == NULL)
		return (NULL);
	ret[4] = load_player_sprite(wind, check, "/texture/player/death/death", 13);
	if (ret[4] == NULL)
		return (NULL);
	ret[5] = load_player_sprite(wind, check, "/texture/player/defend/defend", 10);
	if (ret[5] == NULL)
		return (NULL);
	ret[6] = load_player_sprite(wind, check, "/texture/player/idle/idle", 8);
	if (ret[6] == NULL)
		return (NULL);
	ret[7] = load_player_sprite(wind, check, "/texture/player/jump/jump", 20);
	if (ret[7] == NULL)
		return (NULL);
	ret[8] = load_player_sprite(wind, check, "/texture/player/move/move", 8);
	if (ret[8] == NULL)
		return (NULL);
	return (ret);
}