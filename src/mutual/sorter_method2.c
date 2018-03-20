/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 15:53:21 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_pivot_value(t_heaps **ab, int pivot_index)
{
	t_stack	*current;

	if (*ab && (*ab)->a)
	{
		current = (*ab)->a;
		while (current && current->index > pivot_index)
			current = current->next;
		if (current->index == pivot_index)
		{
			(*ab)->a_pval = current->nb;
			(*ab)->a_ppos = pivot_index;
		}
	}
}

void 	ft_rsorter(t_heaps **ab, int pivot_pos)
{
	if (pivot_pos == 1)
		return ;
	if ((*ab)->count > 2)
	{
		ft_pivot_value(ab, pivot_pos);
		if ((ft_count_bad((*ab)->a, (*ab)->a_pval, pivot_pos)) != 0)
		{
			ft_interject_pivot(ab);
			ft_rsorter(ab, pivot_pos);
		}
		else
			ft_rsorter(ab, pivot_pos - 1);
	}
	else if ((*ab)->count == 2 && ((*ab)->a->nb > (*ab)->a->next->nb))
		ft_swap_a(ab, 1);
}

void 	ft_sorter(t_heaps **ab, int pivot_pos)
{
	if (pivot_pos > (*ab)->a->index)
	{
		ft_rsorter(ab, (*ab)->a->index);
		return ;
	}
	if ((*ab)->count > 2)
	{
		ft_pivot_value(ab, pivot_pos);
		if ((ft_count_bad((*ab)->a, (*ab)->a_pval, pivot_pos)) != 0)
		{
			ft_interject_pivot(ab);
			ft_sorter(ab, pivot_pos);
		}
		else
			ft_sorter(ab, pivot_pos + 1);
	}
	else if ((*ab)->count == 2 && ((*ab)->a->nb > (*ab)->a->next->nb))
		ft_swap_a(ab, 1);
}
