/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/03 17:50:31 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_adjust_pivot_pos(t_stack *stack, int *ppos)
{
	if (*ppos == stack->index)
		(*ppos)--;
	else if (*ppos == stack->index - 1)
		(*ppos)++;
}

static int	ft_swap_motion(t_stack *stack, int *ppos)
{
	int		origin;

	origin = *ppos;
	if (stack && stack->index > 1)
	{
		ft_adjust_pivot_pos(stack, ppos);
		ft_swap(&stack->nb, &stack->next->nb);
		return (1);
	}
	*ppos = origin;
	return (0);
}

void		ft_swap_a(t_heaps **ab, int apply)
{
	if (!ft_issortn((*ab)->b, 2))
		ft_swap_ab(ab, apply);
	else if (ft_swap_motion((*ab)->a, &(*ab)->a_ppos) && apply == 1)
		ft_moveappend(ab, "sa");
}

void		ft_swap_b(t_heaps **ab, int apply)
{
	if (!ft_issortn((*ab)->a, 2))
		ft_swap_ab(ab, apply);
	else if (ft_swap_motion((*ab)->b, &(*ab)->b_ppos) && apply == 1)
		ft_moveappend(ab, "sb");
}

void		ft_swap_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_swap_motion((*ab)->a, &(*ab)->a_ppos);
	ret_b = ft_swap_motion((*ab)->b, &(*ab)->b_ppos);
	if (ret_a && ret_b && apply == 1)
		ft_moveappend(ab, "ss");
	else if (ret_a && apply == 1)
		ft_moveappend(ab, "sa");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "sb");
}
