/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/12 12:37:05 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_under_median(t_heaps **ab, t_stack **a, t_stack **b, char rot)
{
	int		count;
	int		mdn;
	int		sens;

//	printf("%s\n", __FUNCTION__);
	*(*a)->pval = ft_find_median(*a);
	*(*a)->ppos = ft_find_index(*a, *(*a)->pval);
	mdn = *(*a)->pval;
//	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*a)->sens;
	count = sens == 1 ? ft_countv(*a, mdn, "<") : ft_countv(*a, mdn, ">");
	while (*a && count)
	{
		if (ft_issort(*a) && *b && *(*a)->min > *(*b)->max)
			return ;
		if ((sens == 1 && (*a)->nb < mdn) || (sens == 0 && (*a)->nb > mdn))
		{
			(*a)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			(*a)->id == 'a' ? ft_simple_sorter(ab, b, 2)
					: ft_simple_sorter(ab, a, 2);
			count--;
		}
		else if (rot == 'r')
			(*a)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		else if (rot == 'R')
			(*a)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	}
}

void	ft_push_above_median(t_heaps **ab, t_stack **a, t_stack **b)
{
	int		count;
	int		push;
	int		mdn;
	int		sens;

//	printf("%s\n", __FUNCTION__);
	*(*b)->pval = ft_find_median(*b);
	*(*b)->ppos = ft_find_index(*b, *(*b)->pval);
	mdn = *(*b)->pval;
//	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*b)->sens;
	count = ft_countv(*b, mdn, ">");
	push = 0;
	ft_simple_sorter(ab, b, (*b)->index - ft_find_index(*b, mdn));
	while (*b && count)
	{
		//if (!ft_issortn(*b, 15))
		//	ft_simple_sorter(ab, b, 15);
		ft_place(ab, *b, *(*b)->max, (*b)->index);
		ft_push_a(ab, 1);
		push++;
		count--;
	}
	if (!ft_issort(*a))
		ft_sorter(ab, a, b);
	//ft_simple_sorter(ab, &(*ab)->a, push);
}

void 	ft_sorter(t_heaps **ab, t_stack **a, t_stack **b)
{
//	printf("%s\n", __FUNCTION__);
	//printf("ARG: %s\n", getenv("ARG"));
	if (!*a || ft_issort(*a))
		return ;
	/*while ((*work)->index > 2)
		ft_push_under_median(ab, work);
	ft_simple_sorter(ab, work, (*work)->index);
	while ((*ab)->b->index > 2)
		ft_push_under_median(ab, &(*ab)->b);
	ft_simple_sorter(ab, &(*ab)->b, (*ab)->b->index);
	while ((*ab)->b)
		ft_push_a(ab, 1);*/
	if ((*a)->index < 15)
		ft_simple_sorter(ab, a, (*a)->index);
	else
	{
		while ((*a)->index > 2)
		{
			if (ft_issort(*a) && *b && *(*a)->min > *(*b)->max)
				break ;
			ft_choose_push_under_median(ab, a, b);
		}
		if (*a)
			ft_simple_sorter(ab, a, (*a)->index);
		while (*b && (*b)->index > 2)
			ft_push_above_median(ab, a, b);
		if (*b)
			ft_simple_sorter(ab, b, (*b)->index);
		while (*b)
			ft_push_a(ab, 1);
	}
//	if (!ft_issort(*work))
//		ft_sorter(ab, work);
}

/*
** Idées d'améliorations : 
** - tester le meilleur chemin pour diminuer les rotations
** - réduire les gestes inutiles :
**		pa/pb, pb/pa
**		sa/sa, sb/sb, ss/ss
**		ra/rra, rra/ra, rb/rrb, rrb/rb, rr/rrr, rrr/rr
** - réaliser le ss (directement ds les fonctions motions) test à faire quand on fait un sa ou sb
*/
