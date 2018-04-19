/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:17:05 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 12:42:41 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_index(t_stack *stack, int nb)
{
	int 	index;
	t_stack	*cpy;

	if (!stack)
		return (-1);
	index = stack->index;
	cpy = stack;
	while (cpy)
	{
		if (cpy->nb == nb)
			return (cpy->index);
		cpy = cpy->next;
	}
	return (-1);
}

int		ft_find_val(t_stack *stack, int index_tofind)
{
	t_stack	*cpy;

	if (!stack)
		return (0);
	cpy = stack;
	while (cpy)
	{
		if (cpy->index == index_tofind)
			return (cpy->nb);
		cpy = cpy->next;
	}
	return (0);
}

int		ft_find_next(t_stack *stack, int ref)
{
	int		next_val;
	t_stack	*cpy;

	if (!stack)
		return (0);
	next_val = *stack->max;
	cpy = stack;
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

	if (!stack)
		return (0);
	prev_val = *stack->min;
	cpy = stack;
	while (cpy)
	{
		if (cpy->nb < ref && cpy->nb > prev_val)
			prev_val = cpy->nb;
		cpy = cpy->next;
	}
	return (prev_val);
}

void	ft_find_minmax(t_stack *stack, int *min, int *max, int n)
{
	t_stack	*cpy;

	if (!stack)
		return ;
	cpy = stack;
	*min = stack->nb;
	*max = stack->nb;
	while (cpy && n)
	{
		*min = cpy->nb < *min ? cpy->nb : *min;
		*max = cpy->nb > *max ? cpy->nb : *max;
		n--;
		cpy = cpy->next;
	}
}

int		ft_find_median(t_stack *stack)
{
	int		i;
	int		tab[stack->index + 1];
	t_stack	*cpy;

	if (!stack)
		return (0);
	cpy = stack;
	tab[stack->index] = 0;
	i = stack->index;
	tab[i] = 0;
	while (i)
	{
		tab[i - 1] = cpy->nb;
		cpy = cpy->next;
		i--;
	}
	while (i + 1 < stack->index)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = -1;
		}
		i++;
	}
	return (tab[stack->index / 2]);
}
