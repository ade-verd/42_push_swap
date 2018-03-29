/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:34:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/29 17:54:47 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_two_values(t_heaps **ab, t_stack **work)
{
	if ((*work)->index == 2 && !ft_issort(*work))
	{
	//	if (((*work)->sens == 1 && (*work)->nb > (*work)->next->nb)
	//		|| ((*work)->sens == 0 && (*work)->nb < (*work)->next->nb))
			(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
	}
}

void static	ft_three_values(t_heaps **ab, t_stack **work)
{
	int		top;
	int 	btm;

	top = (*work)->sens == 1 ? *(*work)->min : *(*work)->max;
	btm = (*work)->sens == 1 ? *(*work)->max : *(*work)->min;
	if ((*work)->index == 3 && !ft_issort(*work))
	{
		if (ft_find_index(*work, btm) == 3)
			(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		else if (ft_find_index(*work, btm) == 2)
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
		if (!ft_issort(*work))
			(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
	}
}

void		ft_simple_sorter(t_heaps **ab, t_stack **work)
{
	if ((*work)->index == 2)
		ft_two_values(ab, work);
	else if ((*work)->index == 3)
		ft_three_values(ab, work);
}
