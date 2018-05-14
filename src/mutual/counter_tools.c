/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:25:12 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/14 15:18:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** int	ft_issort(t_stack *stack)
** Returns 1 if stack is sorted. Else returns 0
*/

int		ft_issort(t_stack *stack)
{
	int		sens;

	if (!stack)
		return (0);
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

/*
** int	ft_issortn(t_stack *stack, int n)
** Returns 1 if the n first values of the stack are sorted. Else returns 0
*/

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

/*
** int	ft_countv(t_stack *stack, int val, char *sign)
** Returns the nb of values "<", ">", "==", ">=", or "<="" to the integer val.
*/

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
