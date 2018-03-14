/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_motion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/14 13:20:11 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_heaps **ab)
{
	if ((*ab)->pivot_pos == 1)
		(*ab)->pivot_pos = (*ab)->a->index;
	else
		(*ab)->pivot_pos--;
}

static int	ft_rrotate_motion(t_stack **stack)
{
	int		tmp1;
	int		tmp2;
	t_stack	*cpy;

	cpy = *stack;
	if (ft_stacklen(cpy) > 1)
	{
		tmp1 = cpy->nb;
		tmp2 = cpy->previous->nb;
		while (cpy->previous->previous)
		{
			cpy->previous->nb = tmp1;
			tmp1 = tmp2;
			tmp2 = cpy->previous->previous->nb;
			cpy = cpy->previous;
		}
		cpy->previous->nb = tmp1;
		(*stack)->nb = tmp2;
		return (1);
	}
	return (0);
}

void		ft_rrotate_a(t_heaps **ab)
{
	if (ft_rrotate_motion(&(*ab)->a))
	{
		ft_moveappend(ab, "rra");
		ft_adjust_pivot_pos(ab);
	}
}

void		ft_rrotate_b(t_heaps **ab)
{
	if (ft_rrotate_motion(&(*ab)->b))
		ft_moveappend(ab, "rrb");
}

void		ft_rrotate_ab(t_heaps **ab)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rrotate_motion(&(*ab)->a);
	ret_b = ft_rrotate_motion(&(*ab)->b);
	if (ret_a && ret_b)
	{
		ft_moveappend(ab, "rrr");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_a)
	{
		ft_moveappend(ab, "rra");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_b)
		ft_moveappend(ab, "rrb");
}
