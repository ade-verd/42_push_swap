/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/03 17:54:06 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_nextpivot(t_stack **work, char next_previous)
{
	int		start_val;
	int		end_val;

	if (!*work)
		return ;
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
}

void 	ft_rsorter(t_heaps **ab, t_stack **work, int ppos)
{
//	printf("%s\n", __FUNCTION__);
	if (ppos > (*work)->index || ft_issort(*work))
		return ;
	if ((*work)->index > 5)
	{
		//////ft_pivot_value(ab, work, ppos);
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
//	printf("%s\n", __FUNCTION__);
	if (!(*work) || ft_issort(*work))
		return ;
	if (ppos < 1 || ppos > (*work)->index)
	{
		ft_rsorter(ab, work, 1);
		return ;
	}
	if ((*work)->index > 5)
	{
		//////ft_pivot_value(ab, work, ppos);
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
		{
			ft_interject_pivot(ab, work);
			ft_sorter(ab, work, ppos);
		}
		else
		{
			ft_sorter(ab, work, ppos - 1);
			ft_sorter(ab, work, ppos + 1);
		}
	}
	else
		ft_simple_sorter(ab, work);
}
