/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 04:23:16 by ticasali          #+#    #+#             */
/*   Updated: 2025/03/14 04:33:46 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Elaym.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		ft_putchar(str[ct]);
		++ct;
	}
}

void	ft_puttab(char **tab)
{
	size_t	ct;

	ct = 0;
	while (tab[ct] != NULL)
	{
		ft_putstr(tab[ct]);
		ft_putchar('\n');
		++ct;
	}
}