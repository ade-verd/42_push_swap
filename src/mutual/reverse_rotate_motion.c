/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_motion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/16 14:31:36 by ade-verd         ###   ########.fr       */
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
		tmp2 = cpy->next->nb;
		while (cpy->next->next)
		{
			cpy->next->nb = tmp1;
			tmp1 = tmp2;
			tmp2 = cpy->next->next->nb;
			cpy = cpy->next;
		}
		cpy->next->nb = tmp1;
		(*stack)->nb = tmp2;
		return (1);
	}
	return (0);
}

void		ft_rrotate_a(t_heaps **ab, int apply)
{
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	if (ft_rrotate_motion(&(*ab)->a))
	{
		if (apply == 1)
			ft_moveappend(ab, "rra");
	}
	else
		(*ab)->pivot_pos = ref;
}

void		ft_rrotate_b(t_heaps **ab, int apply)
{
	if (ft_rrotate_motion(&(*ab)->b) && apply == 1)
		ft_moveappend(ab, "rrb");
}

void		ft_rrotate_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	ret_a = ft_rrotate_motion(&(*ab)->a);
	ret_b = ft_rrotate_motion(&(*ab)->b);
	if (!ret_a)
		(*ab)->pivot_pos = ref;
	if (ret_a && ret_b)
	{
		if (apply == 1)
			ft_moveappend(ab, "rrr");
	}
	else if (ret_a)
	{
		if (apply == 1)
			ft_moveappend(ab, "rra");
	}
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rrb");
}
