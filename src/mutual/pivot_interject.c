/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/12 18:52:19 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_pivot_value(t_heaps **ab, int pivot_index)
{
	t_stack	*current;

	if ((*ab) && (*ab)->a)
	{
		current = (*ab)->a;
		while (current && current->index > pivot_index)
			current = current->previous;
		if (current->index == pivot_index)
		{
			(*ab)->pivot = current->nb;
			(*ab)->pivot_pos = pivot_index;
		}
	}
}

void	ft_place_pivot_on_bottop(t_heaps **ab, int offset, int target)
{
	int		pivot_pos;
	float	median;

	printf("START OFFSET REPLACE\n");
	pivot_pos = 1 + ft_abs(offset);
	median = (*ab)->a->index / 2;
	while (pivot_pos != target)
	{
		if (pivot_pos > median)
		{
			ft_rotate_a(ab);
			ft_heaps_display(ab, 'a' + 'b');
			pivot_pos = pivot_pos == (*ab)->a->index ? 1 : pivot_pos + 1;
		}
		else
		{
			ft_rrotate_a(ab);
			ft_heaps_display(ab, 'a' + 'b');
			pivot_pos = pivot_pos == 1 ? (*ab)->a->index : pivot_pos - 1;
		}
	}
	(*ab)->pivot_pos = target; 
	printf("END OFFSET REPLACE\n");
}

void	ft_interject_pivot_pushinf(t_heaps **ab)
{
	int		count;
	int 	pivot;
	int 	offset;

	count = ft_count_val((*ab)->a, (*ab)->pivot, "<=");
	pivot = (*ab)->pivot;
	offset = 0;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb <= pivot)
		{
			ft_push_b(ab);
			count--;
		}
		else
		{
			ft_rotate_a(ab);
			offset++;
		}
		ft_heaps_display(ab, 'a' + 'b');
	}
	ft_place_pivot_on_bottop(ab, offset,(*ab)->a->index);
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		(*ab)->pivot_pos = (*ab)->pivot_pos == 1
			? (*ab)->a->index : (*ab)->pivot_pos - 1; 
		ft_heaps_display(ab, 'a' + 'b');
	}
}

void	ft_interject_pivot_pushsup(t_heaps **ab)
{
	int 	count;
	int		offset;
	int 	pivot;

	count = ft_count_val((*ab)->a, (*ab)->pivot, ">=");
	offset = 0;
	pivot = (*ab)->pivot;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb >= pivot)
		{
			ft_push_b(ab);
			count--;
		}
		else
		{
			offset--;
			ft_rotate_a(ab);
		}
		ft_heaps_display(ab, 'a' + 'b');
	}
	ft_place_pivot_on_bottop(ab, offset, 1);
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
		ft_rotate_a(ab);
		(*ab)->pivot_pos = (*ab)->pivot_pos == (*ab)->a->index 
			? 1 : (*ab)->pivot_pos + 1; 
		ft_heaps_display(ab, 'a' + 'b');
	}
}

void	ft_interject_pivot(t_heaps **ab)
{
	if ((*ab)->pivot == (*ab)->min && (*ab)->pivot_pos != (*ab)->a->index)
	{
		printf("MIN\n");
		ft_place_pivot_on_bottop(ab, (*ab)->pivot_pos - 1, (*ab)->a->index);
	}
	else if ((*ab)->pivot == (*ab)->max && (*ab)->pivot_pos != 1)
	{
		printf("MAX\n");
		ft_place_pivot_on_bottop(ab, (*ab)->pivot_pos - 1, 1);
	}
	else
	{
		printf("ELSE\n");
		if (ft_count_val((*ab)->a, (*ab)->pivot, "<")
			< ft_count_val((*ab)->a, (*ab)->pivot, ">"))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushsup(ab);
	}
}
