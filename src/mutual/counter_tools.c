/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:25:12 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 11:46:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issort(t_stack *stack)
{
	int		sens;

	sens = stack->sens;
	while (stack && stack->next)
	{
		if (sens == 1 && stack->nb > stack->next->nb)
			return (0);
		else if (sens == 0 && stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		ft_issortn(t_stack *stack, int n)
{
	int		sens;

	if (!stack)
		return (0);
	sens = stack->sens;
	while (stack && stack->next && n - 1)
	{
		if (sens == 1 && stack->nb > stack->next->nb)
			return (0);
		else if (sens == 0 && stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
		n--;
	}
	return (1);
}

int		ft_countv(t_stack *stack, int val, char *sign)
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
		if (stack->sens == 1)
		{
			if (stack->nb > pivot && stack->index > pos)
				count++;
			if (stack->nb < pivot && stack->index < pos)
				count++;
		}
		else
		{
			if (stack->nb > pivot && stack->index < pos)
				count++;
			if (stack->nb < pivot && stack->index > pos)
				count++;
		}
		stack = stack->next;
	}
	return (count);
}
