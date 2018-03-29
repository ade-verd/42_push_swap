/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/29 16:56:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_minmax(t_stack *dest, t_stack *src)
{
	t_stack	*cpy_src;
	int		nb;

	nb = dest->nb;
	if (src)
	{
		*(src->min) = src->nb;
		*(src->max) = src->nb;
	}
	if (nb < *(dest->min) || dest->index == 1)
		*(dest->min) = nb;
	if (nb > *(dest->max) || dest->index == 1)
		*(dest->max) = nb;
	cpy_src = src;
	while (cpy_src)
	{
		*(src->min) = cpy_src->nb < *(src->min) ? cpy_src->nb : *(src->min); 
		*(src->max) = cpy_src->nb > *(src->max) ? cpy_src->nb : *(src->max); 
		*(src->min) = *(src->min);
		*(src->max) = *(src->max);
		cpy_src = cpy_src->next;
	}
}

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
		ft_check_minmax((*ab)->a, (*ab)->b);
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
		ft_check_minmax((*ab)->b, (*ab)->a);
		if (apply == 1)
			ft_moveappend(ab, "pb");
	}
}
