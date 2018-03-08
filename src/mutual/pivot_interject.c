/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/08 18:57:00 by ade-verd         ###   ########.fr       */
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
			(*ab)->pivot = current->nb;
	}
}

int		ft_count_val(t_stack *stack, int val, char *sign)
{
	int		count;

	count = ft_strchr(sign, '=') ? -1 : 0;
	while (stack)
	{
		if (sign[0] == '>' && stack->nb > val)
			count++;
		else if (sign[0] == '<' && stack->nb < val)
			count++;
		else if (ft_strchr(sign, '=') && stack->nb == val)
			count++;
		stack = stack->previous;
	}
	return (count);
}

void	ft_place_pivot_on_top(t_heaps **ab, int offset)
{
	printf("START OFFSET REPLACE\n");
	while(offset-- >= 0)
	{
		ft_rrotate_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
	}
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
	ft_place_pivot_on_top(ab, offset);
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
	}
}

void	ft_interject_pivot_pushsup(t_heaps **ab)
{
	int 	count;
	int		count2;
	int 	pivot;

	count = ft_count_val((*ab)->a, (*ab)->pivot, ">=");
	count2 = count;
	pivot = (*ab)->pivot;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb >= pivot)
		{
			ft_push_b(ab);
			count--;
		}
		else
			ft_rotate_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
	}
	while (count2--)
	{
		ft_rrotate_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
	}
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		ft_rotate_a(ab);
		ft_heaps_display(ab, 'a' + 'b');
	}
}

void	ft_interject_pivot(t_heaps **ab)
{
	if ((*ab)->pivot == (*ab)->min)
		ft_rrotate_a(ab);
	else if ((*ab)->pivot != (*ab)->max)
	{
		if (ft_count_val((*ab)->a, (*ab)->pivot, "<")
			< ft_count_val((*ab)->a, (*ab)->pivot, ">"))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushinf(ab);
	}
}
