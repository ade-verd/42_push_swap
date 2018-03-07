/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/07 18:42:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_ab_minmax(t_heaps **ab, int nb)
{
	if ((*ab) && !(*ab)->a)
	{
		(*ab)->min = nb;
		(*ab)->max = nb;
	}
	else
	{
		if (nb < (*ab)->min)
			(*ab)->min = nb;
		if (nb > (*ab)->max)
			(*ab)->max = nb;
	}
}

int		ft_read_and_fillstack(int ac, char **av, t_heaps **ab)
{
	int		nb;

	while (ac > 1)
	{
		ac--;
		if (ft_isnumber(av[ac]))
		{
			nb = ft_atoi(av[ac]);
			ft_ab_minmax(ab, nb);
			ft_stackpush(&(*ab)->a, nb);
		}
		else
			ft_error(ab, 0);
	}
	(*ab)->count = (*ab)->a->index;
	return (1);
}
