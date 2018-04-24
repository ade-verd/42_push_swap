/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 17:52:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sorter(t_heaps **ab, t_stack **a, t_stack **b)
{
	int		count;
	int		mdn;
	int		sens;
	int		fst_quarter;
	int		thd_quarter;

	ft_find_median(*a, &fst_quarter, &mdn, &thd_quarter);
	sens = (*a)->sens;
	count = sens == 1 ? ft_countv(*a, mdn, "<") : ft_countv(*a, mdn, ">");
	while (*a && count && !(ft_issort(*a) && *b && *(*a)->min > *(*b)->max))
	{
		(*a)->index < 6 ? ft_select_sorter(ab, a, (*a)->index) : none;
		if ((sens == 1 && (*a)->nb < mdn) || (sens == 0 && (*a)->nb > mdn))
		{
			ft_pushw(ab, a, 1);
			if ((sens == 1 && (*b)->nb < fst_quarter)
				|| (sens == 0 && (*b)->nb > fst_quarter))
				ft_rotatew(ab, b, 1);
			ft_select_sorter(ab, b, 2);
			count--;
		}
		else
			ft_rotatew(ab, a, 1);
	}
}

void	ft_insert_sorter(t_heaps **ab, t_stack **a, t_stack **b)
{
	int		bestval;

	bestval = ft_find_bestmove(b, a);
	ft_placetopboth(ab, bestval, ft_find_next(*a, bestval));
	ft_pushw(ab, b, 1);
}

void	ft_sorter(t_heaps **ab, t_stack **a, t_stack **b)
{
	if (!*a || ft_issort(*a))
		return ;
	if ((*a)->index < 6)
		ft_select_sorter(ab, a, (*a)->index);
	else
	{
		while ((*a)->index > 2)
		{
			if (ft_issort(*a) && *b && *(*a)->min > *(*b)->max)
				break ;
			ft_quick_sorter(ab, a, b);
		}
		if (*a)
			ft_select_sorter(ab, a, (*a)->index);
		while (*b)
			ft_insert_sorter(ab, a, b);
		ft_placetop(ab, a, *(*a)->min);
	}
}
