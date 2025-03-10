/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   login.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 03:40:00 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/10 04:38:33 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	add_char_login(Control_t *ctrl, char c)
{
	size_t	ct;

	ct = ft_strlen(ctrl->login);
	if (ct < 8)
	{
		ctrl->login[ct] = c;
		ctrl->login[++ct] = '\0';
	}
}

void	del_char_login(Control_t *ctrl)
{
	size_t	ct;

	ct = ft_strlen(ctrl->login);
	if (ct != 0)
		ctrl->login[ct - 1] = '\0';
}

bool	check_login(Control_t *ctrl)
{
	size_t	ct;

	ct = 0;
	if (ctrl->login[0] == '\0')
		return (false);
	while (ctrl->save[ct] != NULL)
	{
		if (ft_strcmp(ctrl->save[ct], ctrl->login) == 0)
			return (true);
		++ct;
	}
	return (false);
}