/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/09 13:22:33 by ade-verd         ###   ########.fr       */
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
	printf("%smedian: %d%s\n", F_YELLOW, mdn, F_NO);
	sens = (*work)->sens;
	count = sens == 1 ? ft_countv(*work, mdn, "<") : ft_countv(*work, mdn, ">");
	while (*work && count)
	{
		if ((sens == 1 && (*work)->nb < mdn) || (sens == 0 && (*work)->nb > mdn))
		{
			(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			ft_simple_sorter(ab, &(*ab)->b, 2);
			count--;
		}
		else
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	}
}

void 	ft_sorter(t_heaps **ab, t_stack **work)
{
	//printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (!(*work))
		return ;
	while ((*work)->index > 2)
		ft_push_under_median(ab, work);
	ft_simple_sorter(ab, work, (*work)->index);
	while ((*ab)->b)
		ft_push_under_median(ab, work);
	//ft_simple_sorter(ab, work, (*work)->index);
}
