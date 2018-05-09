/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:55:59 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 15:37:24 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** int	*ft_bubble_sorter(t_stack *stack, int *tab)
** Sorts with "bubble sort" method and returns an array of integers.
*/

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
	while (i)
	{
		i--;
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
