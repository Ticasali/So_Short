/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:18:56 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 03:22:57 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	load_data(Control_t **ctrl, int ac, char **av)
{
	Map_t		*map;
	Wind_t		*wind;
	Player_t	*play;
	Back_t		*back;
	Font_t		*font;

	back = malloc(sizeof(Back_t));
	wind = malloc(sizeof(Wind_t));
	play = malloc(sizeof(Player_t));
	font = malloc(sizeof(Font_t));
	if (wind == NULL
		|| play == NULL || back == NULL)
		return (free_all(ctrl));
	ctrl[0]->MS = map;
	ctrl[0]->WS = wind;
	ctrl[0]->PS = play;
	ctrl[0]->BaS = back;
	ctrl[0]->FS = font;
	if ((load_map(map, ac, av) == false)
		|| (load_window(wind) == false)
		|| (load_block_struct(ctrl, ac) == false)
		|| (load_back(wind, back, ac) == false)
		|| (load_player(wind, play) == false)
		|| (load_font(wind, font) == false))
	if (map == NULL || wind == NULL || play == NULL)
		return (free_all(ctrl));
	ctrl[0]->Statement = 0;
	ctrl[0]->login = malloc(sizeof(char) * 9);
	if (ctrl[0]->login == NULL)
		return (NULL);
	ctrl[0]->save = load_tab("save");
	if (ctrl[0]->save == NULL)
		return (NULL);
}
