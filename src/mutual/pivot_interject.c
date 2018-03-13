/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/13 18:46:34 by ade-verd         ###   ########.fr       */
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

void	ft_place_pivot_on_bottop(t_heaps **ab, int pivot_pos, int target)
{
	float	median;

	printf("START OFFSET REPLACE\n");
	median = (*ab)->a->index / 2;
	while (pivot_pos != target)
	{
		printf("pivot_pos:%d\ttarget:%d\n", pivot_pos, target);
		if (pivot_pos > median)
		{
			ft_rotate_a(ab);
			pivot_pos = pivot_pos == (*ab)->a->index ? 1 : pivot_pos + 1;
		}
		else
		{
			ft_rrotate_a(ab);
			pivot_pos = pivot_pos == 1 ? (*ab)->a->index : pivot_pos - 1;
		}
		printf("pivot_pos:%d\ttarget:%d\n", pivot_pos, target);
	}
	(*ab)->pivot_pos = target; 
	printf("END OFFSET REPLACE\n");
}

void	ft_interject_pivot_pushinf(t_heaps **ab)
{
	int		count;
	int 	pivot;
	int 	pos;

	printf("%s\n", __FUNCTION__);
	count = ft_count_val((*ab)->a, (*ab)->pivot, "<");
	pivot = (*ab)->pivot;
	pos = (*ab)->pivot_pos;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb < pivot)
		{
			ft_push_b(ab);
			count--;
		}
		else
		{
			ft_rrotate_a(ab);
			pos = (pos == 1) ? (*ab)->a->index : pos - 1;
		}
		printf("pos:%d\n", pos);
	}
	ft_place_pivot_on_bottop(ab, pos, (*ab)->a->index);
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		(*ab)->pivot_pos = (*ab)->pivot_pos == 1
			? (*ab)->a->index : (*ab)->pivot_pos - 1; 
	}
}

void	ft_interject_pivot_pushsup(t_heaps **ab)
{
	int 	count;
	int 	pivot;
	int		pos;

	printf("%s\n", __FUNCTION__);
	count = ft_count_val((*ab)->a, (*ab)->pivot, ">");
	pivot = (*ab)->pivot;
	pos = (*ab)->pivot_pos;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb > pivot)
		{
			ft_push_b(ab);
			count--;
		}
		else
		{
			ft_rotate_a(ab);
			pos = (pos == (*ab)->a->index) ? 1 : pos + 1;
		}
	}
	ft_place_pivot_on_bottop(ab, pos, 1);
	while ((*ab) && (*ab)->b)
	{
		ft_push_a(ab);
		ft_rotate_a(ab);
		(*ab)->pivot_pos = (*ab)->pivot_pos == (*ab)->a->index 
			? 1 : (*ab)->pivot_pos + 1; 
	}
	printf("fin\n");
}

int		ft_find_index(t_stack *stack, int nb)
{
	int 	index;

	index = stack->index;
	while (stack->index > 0)
	{
		if (stack->nb == nb)
			return (stack->index);
		stack = stack->previous;
	}
	return (-1);
}

void	ft_interject_pivot(t_heaps **ab)
{
	int 	pos;

	if ((*ab)->pivot == (*ab)->min && (*ab)->pivot_pos != (*ab)->a->index)
	{
		printf("MIN\n");
		ft_place_pivot_on_bottop(ab, (*ab)->pivot_pos, (*ab)->a->index);
		ft_push_b(ab);
		if ((pos = ft_find_index((*ab)->a, (*ab)->max)) > 1)
			ft_place_pivot_on_bottop(ab, pos, 1);
		printf("(*ab)->pivot_pos:%d\n", (*ab)->pivot_pos);
		ft_push_a(ab);
	}
	/*else if ((*ab)->pivot == (*ab)->max && (*ab)->pivot_pos != 1)
	{
		printf("MAX\n");
		ft_place_pivot_on_bottop(ab, (*ab)->pivot_pos - 1, 1);
	}*/
	else
	{
		printf("ELSE\n");
		if (ft_count_val((*ab)->a, (*ab)->pivot, "<")
			<= (ft_count_val((*ab)->a, (*ab)->pivot, ">") + 1))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushinf(ab);
	}
}
