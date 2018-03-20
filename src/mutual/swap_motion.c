/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 12:39:09 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_stack *stack)
{
	if (stack->p_pos == stack->index)
		stack->p_pos--;
	else if (stack->p_pos == stack->index - 1)
		stack->p_pos++;
}

static int	ft_swap_motion(t_stack *stack)
{
	int		origin;

	origin = stack->p_pos;
	if (ft_stacklen(stack) > 1)
	{
		ft_adjust_pivot_pos(stack);
		ft_swap(&stack->nb, &stack->next->nb);
		return (1);
	}
	stack->p_pos = origin;
	return (0);
}

void		ft_swap_a(t_heaps **ab, int apply)
{
	if (ft_swap_motion((*ab)->a) && apply == 1)
		ft_moveappend(ab, "sa");
}

void		ft_swap_b(t_heaps **ab, int apply)
{
	if (ft_swap_motion((*ab)->b) && apply == 1)
		ft_moveappend(ab, "sb");
}

void		ft_swap_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_swap_motion((*ab)->a);
	ret_b = ft_swap_motion((*ab)->b);
	if (ret_a && ret_b && apply == 1)
			ft_moveappend(ab, "ss");
	else if (ret_a && apply == 1)
			ft_moveappend(ab, "sa");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "sb");
}
