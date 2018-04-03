/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:34:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/03 13:26:19 by ade-verd         ###   ########.fr       */
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

void static	ft_more_values(t_heaps **ab, t_stack **work)
{
	int		top;
	int 	btm;

	if ((*work)->index <= 3 || ft_issort(*work))
		return ;
	top = (*work)->sens == 1 ? *(*work)->min : *(*work)->max;
	btm = (*work)->sens == 1 ? *(*work)->max : *(*work)->min;
	if (((*work)->sens == 1 && (*work)->nb > (*work)->next->nb)
			|| ((*work)->sens == 0 && (*work)->nb < (*work)->next->nb))
		(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
	ft_place_on_target(ab, work, ft_find_index(*work, top), (*work)->index);
	if (!ft_issort(*work))
		(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
	ft_simple_sorter(ab, work);
	(*work)->id == 'a' ? ft_push_a(ab, 1) : ft_push_b(ab, 1);
}

void		ft_simple_sorter(t_heaps **ab, t_stack **work)
{
//	printf("%s\n", __FUNCTION__);
	if (ft_issort(*work))
		return ;
	if ((*work)->index == 2)
		ft_two_values(ab, work);
	else if ((*work)->index == 3)
		ft_three_values(ab, work);
	else
		ft_more_values(ab, work);
}
