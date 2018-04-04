/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/04 13:39:48 by ade-verd         ###   ########.fr       */
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
	return (*(*work)->ppos);
}

void 	ft_rsorter(t_heaps **ab, t_stack **work, int ppos)
{
	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (ppos > (*work)->index || ft_issort(*work))
		return ;
	if ((*work)->index > 4)
	{
		*(*work)->ppos = ppos;
		ft_find_val(*work, ppos, (*work)->pval);
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
		{
			ft_interject_pivot(ab, work);
			ft_rsorter(ab, work, ppos);
		}
		else
			ft_rsorter(ab, work, ppos + 1);
	}
	else
		(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
}

void 	ft_sorter(t_heaps **ab, t_stack **work, int ppos)
{
	int		save_ppos;
	int		save_pval;

	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	printf("work->index: %d\n", (*work)->index);
	if (!(*work) || ft_issort(*work))
		return ;
	if (ppos < 1 || ppos > (*work)->index)
	{
	//	ft_rsorter(ab, work, 1);
		return ;
	}
	save_ppos = *(*work)->ppos;
	save_pval = *(*work)->pval;
	if ((*work)->index > 4)
	{
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
			ft_interject_pivot(ab, work);
		if (!ft_issort(*work))
		{
			//ft_printf("%sNEW_P%s\n", F_RED, F_NO);
			//ft_sorter(ab, work, ft_nextpivot(work, 'P'));
			//*(*work)->ppos = save_ppos;
			//*(*work)->pval = save_pval;
			//ft_printf("%sNEW_N%s\n", F_RED, F_NO);
			ft_sorter(ab, work, ft_nextpivot(work, 'N'));
		}
	}
	else
		ft_simple_sorter(ab, work);
}
