/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:55:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 18:12:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_bubble_sorter(t_stack *stack, int *tab)
{
	t_stack	*cpy;
	int		i;

	if (!stack) 
		return (0);
	cpy = stack;
	tab[stack->index] = 0;
	i = stack->index;
	tab[i] = 0;
	while (i--)
	{
		tab[i] = cpy->nb;
		cpy = cpy->next;
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
	return (tab);
}

void	ft_find_median(t_stack *stack, int *fst_quart, int *mdn, int *thd_quart)
{
	int		tab[stack->index + 1];

	ft_bubble_sorter(stack, tab);
	*fst_quart = tab[stack->index / 4];
	*thd_quart = tab[stack->index  * 3 / 4];
	*mdn = tab[stack->index / 2];
	*(stack)->pval = *mdn;
	*(stack)->ppos = ft_find_index(stack, *mdn);
}
