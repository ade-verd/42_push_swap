/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 14:17:05 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 19:26:53 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** int	ft_find_index(t_stack *stack, int nb)
** Takes a number and a stack in arguments.
** Returns the index of this number or -1 if not found.
*/

int		ft_find_index(t_stack *stack, int nb)
{
	int		index;
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

/*
** int	ft_find_val(t_stack *stack, int index_tofind)
** Takes an index and a stack in arguments.
** Returns the value corresponding index or 0 if not found.
*/

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

/*
** int	ft_find_next(t_stack *stack, int ref)
** Takes an integer and returns the next integer in the stack.
*/

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

/*
** void	ft_find_minmax(t_stack *stack, int *min, int *max, int n)
** Completes the min and max values for the first n integers of the stack.
*/

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

/*
** void	ft_find_median(t_stack *stack, int *fst_quart, int *mdn, int *thd_quart)
** Finds the median, first quartile, and third quartile of the stack.
*/

void	ft_find_median(t_stack *stack, int *fst_quart, int *mdn, int *thd_quart)
{
	int		tab[stack->index + 1];
	int		i;

	i = 0;
	ft_bubble_sorter(stack, tab);
	*fst_quart = tab[stack->index / 4];
	*thd_quart = tab[stack->index * 3 / 4];
	*mdn = tab[stack->index / 2];
	*(stack)->pval = *mdn;
	*(stack)->ppos = ft_find_index(stack, *mdn);
}
