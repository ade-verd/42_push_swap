/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/04 19:22:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_nextpivot(t_stack **work, char next_previous)
{
	int		start_val;
	int		end_val;

	if (!*work)
		return (0);
	if (next_previous == 'N')
	{
		start_val = (*work)->ppos == 0 ? *(*work)->min : *(*work)->pval;
		end_val = *(*work)->max;
	}
	else
	{
		start_val = *(*work)->min;
		end_val = (*work)->ppos == 0 ? *(*work)->max : *(*work)->pval;
	}
	*(*work)->pval = ft_find_median(*work, (*work)->ppos, start_val, end_val);
	*(*work)->ppos = ft_find_index(*work, *(*work)->pval);
	printf("NextPivot: %d\tPos: #%d\n", *(*work)->pval, *(*work)->ppos);
	return (*(*work)->ppos);
}

void 	ft_sorter(t_heaps **ab, t_stack **work, int ppos)
{
	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (!(*work) || ft_issort(*work) || ppos <= 1)
		return ;
	*(*work)->ppos = ppos;
	ft_find_val(*work, *(*work)->ppos, (*work)->pval);
	if ((*work)->index > 4)
	{
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
			ft_interject_pivot(ab, work);
		if (!ft_issort(*work))
			ft_sorter(ab, work, ppos - 1);
	}
	else
		ft_simple_sorter(ab, work);
}
