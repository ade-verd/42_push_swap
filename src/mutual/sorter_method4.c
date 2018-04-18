/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/18 18:42:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_under_median(t_heaps **ab, t_stack **w, t_stack **o, int size)
{
	int		count;
	int		mdn;
	int		sens;
	int		mdn_of_mdn;

//	printf("%s\n", __FUNCTION__);
	//*(*w)->pval = ft_find_median(*w);
	*(*w)->pval = ft_find_median(*w);
	*(*w)->ppos = ft_find_index(*w, *(*w)->pval);
	mdn = *(*w)->pval;
	mdn_of_mdn = *(*w)->min + ((*(*w)->max - *(*w)->min) / 4);
	sens = (*w)->sens;
	count = sens == 1 ? ft_countv(*w, mdn, "<") : ft_countv(*w, mdn, ">");
	while (*w && count && size)
	{
		if (ft_issort(*w) && *o && *(*w)->min > *(*o)->max)
			return ;
		//if ((*w)->index < 6)
		//	ft_simple_sorter(ab, w, (*w)->index);
		if ((sens == 1 && (*w)->nb < mdn) || (sens == 0 && (*w)->nb > mdn))
		{
			(*w)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			if ((sens == 1 && (*o)->nb < mdn_of_mdn)
				|| (sens == 0 && (*o)->nb > mdn_of_mdn))
				(*w)->id == 'a' ? ft_rotate_b(ab, 1) : ft_rotate_a(ab, 1);
			ft_simple_sorter(ab, o, 2);
			count--;
		}
		else
			(*w)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		size--;
	}
	ft_place2(ab, w, mdn, (*w)->index);
}

void	ft_push_above_median(t_heaps **ab, t_stack **w, t_stack **o, int size)
{
	int		count;
	int		mdn;
	int		sens;

//	printf("%s\n", __FUNCTION__);
	*(*o)->pval = ft_find_median(*o);
	*(*o)->ppos = ft_find_index(*o, *(*o)->pval);
	mdn = *(*o)->pval;
	sens = (*o)->sens;
	count = sens == 1 ? ft_countv(*w, mdn, "<") : ft_countv(*w, mdn, ">");
	while (*o && count && size)
	{
		ft_place2(ab, o, *(*o)->max, (*o)->index);
		(*o)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
	//	ft_simple_sorter(ab, w, 3);
		ft_simple_sorter(ab, w, 2);
		count--;
		size--;
	}
}

void 	ft_sorter(t_heaps **ab, t_stack **w, t_stack **o, int size)
{
//	printf("%s\n", __FUNCTION__);
	if (!*w || ft_issort(*w))
		return ;
	if ((*w)->index < 6)
		ft_simple_sorter(ab, w, (*w)->index);
	else
	{
		while ((*w)->index > 2)
		{
			if (ft_issort(*w) && *o && *(*w)->min > *(*o)->max)
				break ;
			ft_push_under_median(ab, w, o, size);
		}
		if (*w)
			ft_simple_sorter(ab, w, (*w)->index);
		
		while (*o && (*o)->index > 2)
			ft_push_above_median(ab, w, o, size);
		if (*o)
			ft_simple_sorter(ab, o, (*o)->index);
		while (*o)
			ft_push_a(ab, 1);
	}
}

/*
** Idées d'améliorations : 
** - réduire les gestes inutiles :
**		pa/pb, pb/pa
**		sa/sa, sb/sb, ss/ss
**		ra/rra, rra/ra, rb/rrb, rrb/rb, rr/rrr, rrr/rr
*/
