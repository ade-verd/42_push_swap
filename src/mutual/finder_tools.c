/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:17:05 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/03 16:07:26 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_index(t_stack *stack, int nb)
{
	int 	index;
	t_stack	*cpy;

	index = stack->index;
	cpy = stack ? stack : NULL;
	while (cpy)
	{
		if (cpy->nb == nb)
			return (cpy->index);
		cpy = cpy->next;
	}
	return (-1);
}

int		ft_find_val(t_stack *stack, int index_tofind, int *val)
{
	t_stack	*cpy;

	cpy = stack ? stack : NULL;
	while (cpy)
	{
		if (cpy->index == index_tofind)
		{
			*val = cpy->nb;
			return (1);
		}
		cpy = cpy->next;
	}
	return (0);
}

int		ft_find_next(t_stack *stack, int ref)
{
	int		next_val;
	t_stack	*cpy;

	next_val = *stack->max;
	cpy = stack ? stack : NULL;
	while (cpy)
	{
		if (cpy->nb > ref && cpy->nb < next_val)
			next_val = cpy->nb;
		cpy = cpy->next;
	}
	return (next_val);
}

int		ft_find_prev(t_stack *stack, int ref)
{
	int		prev_val;
	t_stack	*cpy;

	prev_val = *stack->min;
	cpy = stack ? stack : NULL;
	while (cpy)
	{
		if (cpy->nb < ref && cpy->nb > prev_val)
			prev_val = cpy->nb;
		cpy = cpy->next;
	}
	return (prev_val);
}

int		ft_find_median(t_stack *stack, int *index, int start_val, int end_val)
{
	int 	median_val;

	start_val = start_val < *stack->min ? *stack->min : start_val;
	end_val = end_val > *stack->max ? *stack->max : end_val;
	median_val = start_val + ((end_val - start_val) / 2);
	if ((*index = ft_find_index(stack, median_val)) == -1)
		median_val = ft_find_next(stack, median_val);
	*index = ft_find_index(stack, median_val);
	return (median_val);
}
