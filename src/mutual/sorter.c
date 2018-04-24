/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/20 18:26:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_under_median(t_heaps **ab, t_stack **w, t_stack **o)
{
	int		count;
	int		mdn;
	int		sens;
	int		fst_quarter;
	int		thd_quarter;

	ft_find_median(*w, &fst_quarter, &mdn, &thd_quarter);
	sens = (*w)->sens;
	count = sens == 1 ? ft_countv(*w, mdn, "<") : ft_countv(*w, mdn, ">");
	while (*w && count && !(ft_issort(*w) && *o && *(*w)->min > *(*o)->max))
	{
		(*w)->index < 6 ? ft_select_sorter(ab, w, (*w)->index) : none;
		if ((sens == 1 && (*w)->nb < mdn) || (sens == 0 && (*w)->nb > mdn))
		{
			ft_pushw(ab, w, 1);
			if ((sens == 1 && (*o)->nb < fst_quarter)
				|| (sens == 0 && (*o)->nb > fst_quarter))
				ft_rotatew(ab, o, 1);
			ft_select_sorter(ab, o, 2);
			count--;
		}
		else
			ft_rotatew(ab, w, 1);
	}
}

void	ft_push_above_median(t_heaps **ab, t_stack **w, t_stack **o)
{
	ft_place2(ab, o, *(*o)->max, (*o)->index);
	ft_pushw(ab, o, 1);
	ft_select_sorter(ab, w, 2);
}

void	ft_sorter(t_heaps **ab, t_stack **w, t_stack **o)
{
	int		cycle;

	cycle = 0;
	if (!*w || ft_issort(*w))
		return ;
	if ((*w)->index < 6)
		ft_select_sorter(ab, w, (*w)->index);
	else
	{
		while ((*w)->index > 2)
		{
			if (ft_issort(*w) && *o && *(*w)->min > *(*o)->max)
				break ;
			ft_push_under_median(ab, w, o);
			if ((*ab)->count > 200 && cycle == 0)
				ft_push_under_median(ab, o, w);
			cycle++;
		}
		if (*w)
			ft_select_sorter(ab, w, (*w)->index);
		while (*o)
			ft_push_above_median(ab, w, o);
		ft_place(ab, *w, *(*w)->min, (*w)->index);
	}
}