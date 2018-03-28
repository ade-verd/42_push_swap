/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/28 16:50:39 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_heaps **ab, int apply)
{
	if ((*ab)->b)
	{
		if ((*ab)->b->index == *(*ab)->b->ppos)
		{
			(*(*ab)->b->ppos)--;
			*(*ab)->b->pval = (*ab)->b->next ? (*ab)->b->next->nb : 0;
		}
		ft_stackpush(ab, &(*ab)->a, (*ab)->b->nb, 'a');
		ft_stackpop(&(*ab)->b);
		if (apply == 1)
			ft_moveappend(ab, "pa");
	}
}

void	ft_push_b(t_heaps **ab, int apply)
{
	if ((*ab)->a)
	{
		if ((*ab)->a->index == *(*ab)->a->ppos)
		{
			(*(*ab)->a->ppos)--;
			*(*ab)->a->pval = (*ab)->a->next ? (*ab)->a->next->nb : 0;
		}
		ft_stackpush(ab, &(*ab)->b, (*ab)->a->nb, 'b');
		ft_stackpop(&(*ab)->a);
		if (apply == 1)
			ft_moveappend(ab, "pb");
	}
}
