/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/11 13:03:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_under_median(t_heaps **ab, t_stack **work)
{
	int		count;
	int		mdn;
	int		sens;

	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	*(*work)->pval = ft_find_median(*work);
	*(*work)->ppos = ft_find_index(*work, *(*work)->pval);
	mdn = *(*work)->pval;
	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*work)->sens;
	count = sens == 1 ? ft_countv(*work, mdn, "<") : ft_countv(*work, mdn, ">");
	while (*work && count)
	{
		if (ft_issort(*work) && (*work)->min > (*ab)->b->max)
			return ;
		if ((sens == 1 && (*work)->nb < mdn) || (sens == 0 && (*work)->nb > mdn))
		{
			(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			(*work)->id == 'a' ? ft_simple_sorter(ab, &(*ab)->b, 2)
					: ft_simple_sorter(ab, &(*ab)->a, 2);
			count--;
		}
		else
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	}
}

void	ft_push_above_median(t_heaps **ab, t_stack **other)
{
	int		count;
	int		push;
	int		mdn;
	int		sens;

	printf("%s\twork: %c\n", __FUNCTION__, (*other)->id - 32);
	*(*other)->pval = ft_find_median(*other);
	*(*other)->ppos = ft_find_index(*other, *(*other)->pval);
	mdn = *(*other)->pval;
	printf("%s\t\tmedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*other)->sens;
	count = ft_countv(*other, mdn, ">");
	push = 0;
	ft_simple_sorter(ab, other, (*other)->index - ft_find_index(*other, mdn));
	while (*other && count)
	{
		//if ((sens == 1 && (*other)->nb < mdn) || (sens == 0 && (*other)->nb > mdn))
	//	{
		//if (!ft_issortn((*ab)->b, 3))
		//	ft_simple_sorter(ab, &(*ab)->b, 3);
		ft_push_a(ab, 1);
		push++;
		count--;
	//	}
	//	else
	//		ft_rrotate_b(ab, 1);
	}
	if (!ft_issort((*ab)->a))
		(*ab)->a->index < 20 ? ft_simple_sorter(ab, &(*ab)->a, (*ab)->a->index)
			: ft_sorter(ab, &(*ab)->a);
	//ft_simple_sorter(ab, &(*ab)->a, push);
}

void 	ft_sorter(t_heaps **ab, t_stack **work)
{
	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (!(*work) || ft_issort(*work))
		return ;
	/*while ((*work)->index > 2)
		ft_push_under_median(ab, work);
	ft_simple_sorter(ab, work, (*work)->index);
	while ((*ab)->b->index > 2)
		ft_push_under_median(ab, &(*ab)->b);
	ft_simple_sorter(ab, &(*ab)->b, (*ab)->b->index);
	while ((*ab)->b)
		ft_push_a(ab, 1);*/
	if ((*work)->index < 20)
		ft_simple_sorter(ab, work, (*work)->index);
	else
	{
		while ((*work)->index > 2)
			ft_push_under_median(ab, work);
		ft_simple_sorter(ab, work, (*work)->index);
		while ((*ab)->b->index > 2)
			ft_push_above_median(ab, &(*ab)->b);
		ft_simple_sorter(ab, &(*ab)->b, (*ab)->b->index);
		while ((*ab)->b)
			ft_push_a(ab, 1);
	}
//	if (!ft_issort(*work))
//		ft_sorter(ab, work);
}

/*
** Idées d'améliorations : 
** - tester le meilleur chemin pour diminuer les rotations
** - 
*/
