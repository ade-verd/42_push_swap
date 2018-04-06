/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_method3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/06 16:10:32 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_merge(t_heaps **ab, int cutsize)
{
	if (!*ab)
		return ;
	while ((*ab)->b)
	{
		if ((*ab)->a && (*ab)->a->index <= 3)
			ft_simple_sorter(ab, &(*ab)->a, (*ab)->a->index);
		if ((*ab)->a && (*ab)->a->next && !ft_issortn((*ab)->a, 2))
			ft_swap_a(ab, 1);
		if (!cutsize || ((*ab)->a && (*ab)->a->nb > (*ab)->b->nb))
			ft_push_a(ab, 1);
		else
		{
			ft_rotate_a(ab, 1);
			cutsize--;
			//while (cutsize && (*ab)->a && (*ab)->a->nb < (*ab)->b->nb)
			//{
			//	if ((*ab)->a->next && (*ab)->a->nb > (*ab)->a->next->nb)
			//		ft_swap_a(ab, 1);
			//	else
			//	{
			//		ft_rotate_a(ab, 1);
			//		cutsize--;
			//	}
			//}
			//ft_push_a(ab, 1);
		}
	}
//	while (cutsize--)
//		ft_rotate_a(ab, 1);
}

void	ft_push_sort_merge(t_heaps **ab, int cutsize)
{
	int		cut;

	cut = cutsize;
	if (cutsize < 2)
		return ;
	//if (cutsize == 2)
	//	ft_swap_a(ab, 1);
	if (!ft_issortn((*ab)->a, cutsize * 2))
	{
		while (cut--)
		{
			ft_push_b(ab, 1);
			ft_simple_sorter(ab, &(*ab)->b, (*ab)->b->index);
		}
		ft_merge(ab, cutsize);
	}
	else
	{
		while (cutsize--)
			ft_rotate_a(ab, 1);
	}
}

void 	ft_mergesorter(t_heaps **ab, t_stack **work, int cutsize)
{
	int		nbcycle;
	int		rest;
	int		cycle;
//	int		i;

	nbcycle = (*work)->index / cutsize;
	rest = (*work)->index % cutsize;
	cycle = 1;
	(*ab)->cut = cutsize;
//	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	if (!*ab || !*work || ft_issort(*work) || cutsize > (*work)->index)
		return ;
	while (cycle <= nbcycle && !ft_issort(*work))
	{
		printf("%scycle(%d) %d/%d%s\n", F_YELLOW, cutsize, cycle, nbcycle, F_NO);
		/*if (*work && !ft_issortn(*work, cutsize))
		{
			ft_push_n_sort(ab, cutsize);
			ft_merge(ab, cutsize);
		}
		else if (cycle + 1 <= nbcycle)
		{
			i = cutsize;
			while (i--)
				ft_rotate_a(ab, 1);
		}*/
		ft_push_sort_merge(ab, cutsize);
		cycle++;
	}
/*	while (rest--)
	{
		printf("%srest %d/%d%s\n", F_YELLOW, rest + 1, (*work)->index % cutsize, F_NO);
		ft_rotate_a(ab, 1);
	}*/
	ft_mergesorter(ab, work, cutsize * 2);
}
