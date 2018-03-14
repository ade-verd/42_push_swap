/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/14 13:18:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_heaps **ab)
{
	if ((*ab)->pivot_pos == (*ab)->a->index)
		(*ab)->pivot_pos = 1;
	else
		(*ab)->pivot_pos++;
}

static int	ft_rotate_motion(t_stack **stack)
{
	int		first;
	t_stack	*cpy;

	cpy = *stack;
	if (ft_stacklen(cpy) > 1)
	{
		first = cpy->nb;
		while (cpy->previous)
		{
			cpy->nb = cpy->previous->nb;
			cpy = cpy->previous;
		}
		cpy->nb = first;
		return (1);
	}
	return (0);
}

void		ft_rotate_a(t_heaps **ab)
{
	if (ft_rotate_motion(&(*ab)->a))
	{
		ft_moveappend(ab, "ra");
		ft_adjust_pivot_pos(ab);
	}
}

void		ft_rotate_b(t_heaps **ab)
{
	if (ft_rotate_motion(&(*ab)->b))
		ft_moveappend(ab, "rb");
}

void		ft_rotate_ab(t_heaps **ab)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rotate_motion(&(*ab)->a);
	ret_b = ft_rotate_motion(&(*ab)->b);
	if (ret_a && ret_b)
	{
		ft_moveappend(ab, "rr");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_a)
	{
		ft_moveappend(ab, "ra");
		ft_adjust_pivot_pos(ab);
	}
	else if (ret_b)
		ft_moveappend(ab, "rb");
}
