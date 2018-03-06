/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/06 17:50:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] && !ft_strchr("0123456789+-", str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_read_and_fillstack(int ac, char **av, t_heaps **ab)
{
	while (ac > 1)
	{
		ac--;
		if (ft_isnumber(av[ac]))
			ft_stackpush(&(*ab)->a, ft_atoi(av[ac]));
		else
			ft_error(ab, 0);
	}
	return (1);
}
