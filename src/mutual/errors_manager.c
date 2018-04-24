/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:35:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 11:17:47 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_heaps **ab, char *precision)
{
	if (precision && ft_strcmp(precision, "NO") != 0)
	{
		ft_putstr(precision);
		ft_putstr("() ");
		ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	if ((*ab))
		ft_heaps_del(ab);
	exit(0);
}

void	ft_error_sdl(t_heaps **ab, char *precision, char *precision2)
{
	if (precision && ft_strcmp(precision, "NO") != 0)
	{
		ft_printf("%s() Error\n", precision);
		if (precision2)
			ft_printf("%s\n", precision2);
	}
	else
		ft_putstr("Error\n");
	if ((*ab))
		ft_heaps_del(ab);
	exit(0);
}

int		none(void)
{
	return (0);
}
