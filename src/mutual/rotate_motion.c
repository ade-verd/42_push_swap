/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/06 18:03:42 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rotate_motion(t_stack **stack)
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

void	ft_rotate_a(t_heaps **ab)
{
	if (ft_rotate_motion(&(*ab)->a))
		ft_moveappend(ab, "ra");
}

void	ft_rotate_b(t_heaps **ab)
{
	if (ft_rotate_motion(&(*ab)->b))
		ft_moveappend(ab, "rb");
}

void	ft_rotate_ab(t_heaps **ab)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rotate_motion(&(*ab)->a);
	ret_b = ft_rotate_motion(&(*ab)->b);
	if (ret_a && ret_b)
		ft_moveappend(ab, "rr");
	else if (ret_a)
		ft_moveappend(ab, "ra");
	else if (ret_b)
		ft_moveappend(ab, "rb");
}
