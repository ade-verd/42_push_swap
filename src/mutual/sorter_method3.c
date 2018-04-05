/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/05 13:29:44 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_merge(t_heaps **ab, int cutsize)
{
	if (!*ab)
		return ;
	while ((*ab)->b)
	{
		if ((*ab)->a->nb > (*ab)->b->nb)
		{
			ft_push_a(ab, 1);
			cutsize++;
		}
		else
		{
			while ((*ab)->a && cutsize && (*ab)->a->nb < (*ab)->b->nb)
			{
				if ((*ab)->a->next && (*ab)->a->nb > (*ab)->a->next->nb)
					ft_swap_a(ab, 1);
				else
				{
					ft_rotate_a(ab, 1);
					cutsize--;
				}
			}
			ft_push_a(ab, 1);
			cutsize++;
		}
	}
	while (cutsize--)
		ft_rotate_a(ab, 1);
}

void	ft_push_n_sort(t_heaps **ab, int cutsize, int pushback)
{
	if (cutsize == 2)
		ft_swap_a(ab, 1);
	else
	{
		while (cutsize--)
		{
			ft_push_b(ab, 1);
			ft_simple_sorter(ab, &(*ab)->b);
		}
	}
	while (pushback && (*ab)->b)
		ft_push_a(ab, 1);
}

void 	ft_mergesorter(t_heaps **ab, t_stack **work, int cutsize)
{
	int		nbcycle;
	int		rest;
	int		cycle;
	int		i;

	nbcycle = (*work)->index / cutsize;
	rest = (*work)->index % cutsize;
	cycle = 1;
	(*ab)->cutsize = cutsize;
	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (!*ab || !*work || ft_issort(*work) || cutsize > (*work)->index)
		return ;
	while (cycle <= nbcycle)
	{
		if (*work && !ft_issortn(*work, cutsize))
		{
			printf("%scycle %d n'est pas trié%s\n", F_RED, cycle, F_NO);
			ft_push_n_sort(ab, cutsize, 0);
			ft_merge(ab, cutsize);
		}
		else if (cycle + 1 < nbcycle)
		{
			printf("cycle %d est trié\n", cycle);
			i = cutsize;
			while (i--)
				ft_rotate_a(ab, 1);
		}
		cycle++;
	}
	ft_push_n_sort(ab, rest, 1);
	//ft_mergesorter(ab, work, cutsize * 2);
}
