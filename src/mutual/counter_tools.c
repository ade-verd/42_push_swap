/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:25:12 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/15 13:37:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		stack = stack->next;
	}
	return (count);
}

int		ft_count_bad(t_stack *stack, int pivot, int pos)
{
	int		count;

	count = 0;
	while (stack)
	{
		if (stack->nb > pivot && stack->index > pos)
			count++;
		if (stack->nb < pivot && stack->index < pos)
			count++;
		stack = stack->next;
	}
	return (count);
}

int		ft_find_index(t_stack *stack, int nb)
{
	int 	index;

	index = stack->index;
	while (stack->index > 0)
	{
		if (stack->nb == nb)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}
