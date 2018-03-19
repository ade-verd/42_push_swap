/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_motion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/19 13:21:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_stack *stack)
{
	if (stack->p_pos == 1)
		stack->p_pos = stack->index;
	else
		stack->p_pos--;
}

static int	ft_rrotate_motion(t_stack *stack)
{
	int		tmp1;
	int		tmp2;
	t_stack	*cpy;

	cpy = stack;
	if (ft_stacklen(cpy) > 1)
	{
		ft_adjust_pivot_pos(stack);
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
		stack->nb = tmp2;
		return (1);
	}
	return (0);
}

void		ft_rrotate_a(t_heaps *ab, int apply)
{
	if (ft_rrotate_motion(ab->a) && apply == 1)
		ft_moveappend(ab, "rra");
}

void		ft_rrotate_b(t_heaps *ab, int apply)
{
	if (ft_rrotate_motion(ab->b) && apply == 1)
		ft_moveappend(ab, "rrb");
}

void		ft_rrotate_ab(t_heaps *ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rrotate_motion(ab->a);
	ret_b = ft_rrotate_motion(ab->b);
	if (ret_a && ret_b && apply == 1)
			ft_moveappend(ab, "rrr");
	else if (ret_a && apply == 1)
			ft_moveappend(ab, "rra");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rrb");
}
