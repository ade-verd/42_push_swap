/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/14 19:02:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_under_median(t_heaps **ab, t_stack **w, t_stack **o, char rot)
{
	int		count;
	int		mdn;
	int		sens;

//	printf("%s\n", __FUNCTION__);
	*(*w)->pval = ft_find_median(*w);
	*(*w)->ppos = ft_find_index(*w, *(*w)->pval);
	mdn = *(*w)->pval;
//	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*w)->sens;
	count = sens == 1 ? ft_countv(*w, mdn, "<") : ft_countv(*w, mdn, ">");
	while (*w && count)
	{
		if (ft_issort(*w) && *o && *(*w)->min > *(*o)->max)
			return ;
		if ((*w)->index < 6)
			ft_simple_sorter(ab, w, (*w)->index);
		//ft_place_nmin(ab, *w, 10);
		if ((sens == 1 && (*w)->nb < mdn) || (sens == 0 && (*w)->nb > mdn))
		{
			(*w)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			(*o)->nb < ft_find_median(*o) ? ft_rotate_b(ab, 1) : none;
			ft_simple_sorter(ab, o, 2);
			if ((*o)->nb < ft_find_median(*o))
				(*w)->id == 'a' ? ft_rotate_b(ab, 1) : ft_rotate_a(ab, 1);
			ft_simple_sorter(ab, o, 2);
			count--;
		}
		else if (rot == 'r')
			(*w)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
	}
}

void	ft_push_above_median(t_heaps **ab, t_stack **w, t_stack **o)
{
	int		count;
	int		mdn;
	int		sens;

//	printf("%s\n", __FUNCTION__);
	*(*o)->pval = ft_find_median(*o);
	*(*o)->ppos = ft_find_index(*o, *(*o)->pval);
	mdn = *(*o)->pval;
//	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*o)->sens;
	count = sens == 1 ? ft_countv(*w, mdn, "<") : ft_countv(*w, mdn, ">");
	//ft_simple_sorter(ab, o, (*o)->index - ft_find_index(*o, mdn));
	while (*o && count)
	{
		//if (!ft_issortn(*b, 15))
		//ft_simple_sorter(ab, o, 10);
		ft_place2(ab, o, *(*o)->max, (*o)->index);
		ft_push_a(ab, 1);
		ft_simple_sorter(ab, w, 2);
		count--;
	}
	if (!ft_issort(*w))
		ft_sorter(ab, w, o);
	//ft_simple_sorter(ab, &(*ab)->a, push);
}

void 	ft_sorter(t_heaps **ab, t_stack **w, t_stack **o)
{
//	printf("%s\n", __FUNCTION__);
	//printf("ARG: %s\n", getenv("ARG"));
	if (!*w || ft_issort(*w))
		return ;
	/*while ((*work)->index > 2)
		ft_push_under_median(ab, work);
	ft_simple_sorter(ab, work, (*work)->index);
	while ((*ab)->b->index > 2)
		ft_push_under_median(ab, &(*ab)->b);
	ft_simple_sorter(ab, &(*ab)->b, (*ab)->b->index);
	while ((*ab)->b)
		ft_push_a(ab, 1);*/
	if ((*w)->index < 6)
		ft_simple_sorter(ab, w, (*w)->index);
	else
	{
		while ((*w)->index > 2)
		{
			if (ft_issort(*w) && *o && *(*w)->min > *(*o)->max)
				break ;
			//ft_choose_push_under_median(ab, a, b);
			ft_push_under_median(ab, w, o, 'r');
		}
		if (*w)
			ft_simple_sorter(ab, w, (*w)->index);
		
		while (*o && (*o)->index > 2)
			ft_push_above_median(ab, w, o);
		if (*o)
			ft_simple_sorter(ab, o, (*o)->index);
		while (*o)
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
