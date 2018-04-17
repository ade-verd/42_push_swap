/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/17 17:55:02 by ade-verd         ###   ########.fr       */
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
	if (ft_atointmax(str) < INT_MINI || ft_atointmax(str) > INT_MAXI)
		return (0);
	return (1);
}

int		ft_nb_exists(t_stack *a, int nb)
{
	t_stack	*cpy;

	if (a)
	{
		cpy = a;
		while (cpy)
		{
			if (cpy->nb == nb)
				return (1);
			cpy = cpy->next;
		}
	}
	return (0);
}

void	ft_ab_minmax(t_heaps **ab, int nb)
{
	if (*ab && !(*ab)->a)
	{
		(*ab)->min = nb;
		(*ab)->max = nb;
	}
	else if (*ab)
	{
		if (nb < (*ab)->min)
			(*ab)->min = nb;
		if (nb > (*ab)->max)
			(*ab)->max = nb;
	}
}

void	ft_check_n_push(t_heaps **ab, char *str)
{
	int		nb;

	nb = 0;
	if (ft_isnumber(str))
	{
		nb = ft_atoi(str);
		ft_nb_exists((*ab)->a, nb) == 1 ? ft_error(ab, 0) : none;
		ft_ab_minmax(ab, nb);
		ft_stackpush(ab, &(*ab)->a, nb, 'a');
	}
	else if (str[0] == '-' && str[1] == 'v')
		(*ab)->option_v = 1;
	else
		ft_error(ab, 0);
}

int		ft_read_and_fillstack(int ac, char **av, t_heaps **ab)
{
	int		i;
	char	**tab;

	if (!(*ab))
		ft_error(ab, "read_and_fillstack");
	while (ac > 1)
	{
		ac--;
		i = ft_countwords(av[ac], ' ');
		tab = ft_strsplit(av[ac], ' ');
		while (--i >= 0)
			ft_check_n_push(ab, tab[i]);
		ft_freetab_strsplit(tab);
	}
	(*ab)->a_min = (*ab)->min;
	(*ab)->a_max = (*ab)->max;
	(*ab)->count = (*ab)->a->index;
	return (1);
}
