/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 12:42:34 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_stack *stack)
{
	if (stack->p_pos == stack->index)
		stack->p_pos = 1;
	else
		stack->p_pos++;
}

static int	ft_rotate_motion(t_stack *stack)
{
	int		first;
	t_stack	*cpy;

	cpy = stack;
	if (ft_stacklen(cpy) > 1)
	{
		ft_adjust_pivot_pos(stack);
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
	if (ft_rotate_motion((*ab)->a) && apply == 1)
			ft_moveappend(ab, "ra");
}

void		ft_rotate_b(t_heaps **ab, int apply)
{
	if (ft_rotate_motion((*ab)->b) && apply == 1)
		ft_moveappend(ab, "rb");
}

void		ft_rotate_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rotate_motion((*ab)->a);
	ret_b = ft_rotate_motion((*ab)->b);
	if (ret_a && ret_b && apply == 1)
		ft_moveappend(ab, "rr");
	else if (ret_a && apply == 1)
		ft_moveappend(ab, "ra");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rb");
}
