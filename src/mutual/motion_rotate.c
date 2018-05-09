/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 16:43:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** static void	ft_adjust_pivot_pos(t_stack *stack, int *ppos)
** Adjusts the position of the pivot.
*/

static void	ft_adjust_pivot_pos(t_stack *stack, int *ppos)
{
	if (*ppos == stack->index)
		*ppos = 1;
	else
		(*ppos)++;
}

/*
** static int	ft_rotate_motion(t_stack *stack, int *ppos)
** Rotates stack
*/

static int	ft_rotate_motion(t_stack *stack, int *ppos)
{
	int		first;
	t_stack	*cpy;

	cpy = stack;
	if (cpy && cpy->index > 1)
	{
		ft_adjust_pivot_pos(stack, ppos);
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

/*
** void		ft_rotate_a(t_heaps **ab, int apply)
** Rotates stack A
*/

void		ft_rotate_a(t_heaps **ab, int apply)
{
	if (ft_rotate_motion((*ab)->a, &(*ab)->a_ppos) && apply == 1)
		ft_moveappend(ab, "ra");
}

/*
** void		ft_rotate_b(t_heaps **ab, int apply)
** Rotates stack B
*/

void		ft_rotate_b(t_heaps **ab, int apply)
{
	if (ft_rotate_motion((*ab)->b, &(*ab)->b_ppos) && apply == 1)
		ft_moveappend(ab, "rb");
}

/*
** void		ft_rotate_ab(t_heaps **ab, int apply)
** Rotates stack A and stack B
*/

void		ft_rotate_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rotate_motion((*ab)->a, &(*ab)->a_ppos);
	ret_b = ft_rotate_motion((*ab)->b, &(*ab)->b_ppos);
	if (ret_a && ret_b && apply == 1)
		ft_moveappend(ab, "rr");
	else if (ret_a && apply == 1)
		ft_moveappend(ab, "ra");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rb");
}
