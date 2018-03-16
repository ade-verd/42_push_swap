/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/16 15:00:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_heaps **ab)
{
	if ((*ab)->pivot_pos == (*ab)->a->index)
		(*ab)->pivot_pos--;
	else if ((*ab)->pivot_pos == (*ab)->a->index - 1)
		(*ab)->pivot_pos++;
}

static int	ft_swap_motion(t_stack **stack)
{
	if (ft_stacklen(*stack) > 1)
	{
		ft_swap(&(*stack)->nb, &(*stack)->next->nb);
		return (1);
	}
	return (0);
}

void		ft_swap_a(t_heaps **ab, int apply)
{
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	if (ft_swap_motion(&(*ab)->a))
	{
		if (apply == 1)
			ft_moveappend(ab, "sa");
	}
	else
		(*ab)->pivot_pos = ref;
}

void		ft_swap_b(t_heaps **ab, int apply)
{
	if (ft_swap_motion(&(*ab)->b) && apply == 1)
		ft_moveappend(ab, "sb");
}

void		ft_swap_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	ret_a = ft_swap_motion(&(*ab)->a);
	ret_b = ft_swap_motion(&(*ab)->b);
	if (!ret_a)
		(*ab)->pivot_pos = ref;
	if (ret_a && ret_b)
	{
		if (apply == 1)
			ft_moveappend(ab, "ss");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_a)
	{
		if (apply == 1)
			ft_moveappend(ab, "sa");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "sb");
}
