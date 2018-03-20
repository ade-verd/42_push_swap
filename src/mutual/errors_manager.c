/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:35:03 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 12:11:37 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_heaps **ab, char *precision)
{
	if (precision)
	{
		ft_putstr(precision);
		ft_putstr("() ");
	}
	ft_putstr("Error\n");
	if ((*ab))
		ft_heaps_del(ab);
	exit(0);
}
