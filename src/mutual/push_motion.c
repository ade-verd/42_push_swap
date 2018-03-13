/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/13 11:41:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_heaps **ab)
{
	if ((*ab)->b)
	{
		ft_stackpush(&(*ab)->a, (*ab)->b->nb, 'a');
		ft_stackpop(&(*ab)->b);
		ft_moveappend(ab, "pa");
	}
}

void	ft_push_b(t_heaps **ab)
{
	if ((*ab)->a)
	{
		ft_stackpush(&(*ab)->b, (*ab)->a->nb, 'b');
		ft_stackpop(&(*ab)->a);
		ft_moveappend(ab, "pb");
	}
}
