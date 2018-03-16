/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/16 14:30:23 by ade-verd         ###   ########.fr       */
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
		while (cpy->next)
		{
			cpy->nb = cpy->next->nb;
			cpy = cpy->next;
		}
		cpy->nb = first;
		return (1);
	}
	return (0);
}

void		ft_rotate_a(t_heaps **ab, int apply)
{
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	if (ft_rotate_motion(&(*ab)->a))
	{
		if (apply == 1)
			ft_moveappend(ab, "ra");
	}
	else
		(*ab)->pivot_pos = ref;
}

void		ft_rotate_b(t_heaps **ab, int apply)
{
	if (ft_rotate_motion(&(*ab)->b) && apply == 1)
		ft_moveappend(ab, "rb");
}

void		ft_rotate_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;
	int		ref;

	ref = (*ab)->pivot_pos;
	ft_adjust_pivot_pos(ab);
	ret_a = ft_rotate_motion(&(*ab)->a);
	ret_b = ft_rotate_motion(&(*ab)->b);
	if (!ret_a)
		(*ab)->pivot_pos = ref;
	if (ret_a && ret_b)
	{
		if (apply == 1)
			ft_moveappend(ab, "rr");
	}
	else if (ret_a)
	{
		if (apply == 1)
			ft_moveappend(ab, "ra");
	}
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rb");
}
