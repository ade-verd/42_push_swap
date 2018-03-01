/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_motion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/01 12:48:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_rrotate_motion(t_stack **stack)
{
	int 	tmp1;
	int 	tmp2;
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

void 	ft_rrotate_a(t_stack **stack)
{
	if (ft_rrotate_motion(stack))
		ft_putstr("rra\n");
}

void 	ft_rrotate_b(t_stack **stack)
{
	if (ft_rrotate_motion(stack))
		ft_putstr("rrb\n");
}

void 	ft_rrotate_ab(t_heaps **ab)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rrotate_motion(&(*ab)->a);
	ret_b = ft_rrotate_motion(&(*ab)->b);
	if (ret_a && ret_b)
		ft_putstr("rrr\n");
	else if (ret_a)
		ft_putstr("rra\n");
	else if (ret_b)
		ft_putstr("rrb\n");
}