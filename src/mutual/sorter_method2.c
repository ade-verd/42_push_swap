/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/27 16:35:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_pivot_value(t_heaps **ab, t_stack **work, int pivot_index)
{
	t_stack	*current;

	if (*ab && *work)
	{
		current = *work;
		while (current && current->index > pivot_index)
			current = current->next;
		if (current->index == pivot_index)
		{
			*(*work)->pval = current->nb;
			*(*work)->ppos = pivot_index;
		}
	}
}

void 	ft_rsorter(t_heaps **ab, t_stack **work, int ppos)
{
	if (ppos > (*work)->index)
		return ;
	if ((*work)->index > 2)
	{
		ft_pivot_value(ab, work, ppos);
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
		{
			ft_interject_pivot(ab, work);
			ft_rsorter(ab, work, ppos);
		}
		else
			ft_rsorter(ab, work, ppos + 1);
	}
	else if ((*work)->index == 2 && ((*work)->nb > (*work)->next->nb))
		ft_swap_a(ab, 1);
}

void 	ft_sorter(t_heaps **ab, t_stack **work, int ppos)
{
	if (ppos < 1)
	{
		ft_rsorter(ab, work, 1);
		return ;
	}
	if ((*work)->index > 2)
	{
		ft_pivot_value(ab, work, ppos);
		if ((ft_count_bad(*work, *(*work)->pval, ppos)) != 0)
		{
			ft_interject_pivot(ab, work);
			ft_sorter(ab, work, ppos);
		}
		else
			ft_sorter(ab, work, ppos - 1);
	}
	else if ((*work)->index == 2 && ((*work)->nb > (*work)->next->nb))
		ft_swap_a(ab, 1);
}
