/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 16:47:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** static void	ft_adjust_pivot_pos(t_stack *stack, int *ppos)
** Adjusts the position of the pivot.
*/

static void	ft_adjust_pivot_pos(t_stack *stack, int *ppos)
{
	if (*ppos == 1)
		*ppos = stack->index;
	else
		(*ppos)--;
}

/*
** static int	ft_rrotate_motion(t_stack *stack, int *ppos)
** Reverse rotates stack
*/

static int	ft_rrotate_motion(t_stack *stack, int *ppos)
{
	int		tmp1;
	int		tmp2;
	t_stack	*cpy;

	cpy = stack;
	if (cpy && cpy->index > 1)
	{
		ft_adjust_pivot_pos(stack, ppos);
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

/*
** void		ft_rrotate_a(t_heaps **ab, int apply)
** Reverse rotates stack A
*/

void		ft_rrotate_a(t_heaps **ab, int apply)
{
	if (ft_rrotate_motion((*ab)->a, &(*ab)->a_ppos) && apply == 1)
		ft_moveappend(ab, "rra");
}

/*
** void		ft_rrotate_b(t_heaps **ab, int apply)
** Reverse rotates stack B
*/

void		ft_rrotate_b(t_heaps **ab, int apply)
{
	if (ft_rrotate_motion((*ab)->b, &(*ab)->b_ppos) && apply == 1)
		ft_moveappend(ab, "rrb");
}

/*
** void		ft_rrotate_ab(t_heaps **ab, int apply)
** Reverse rotates stack A and stack B
*/

void		ft_rrotate_ab(t_heaps **ab, int apply)
{
	int		ret_a;
	int		ret_b;

	ret_a = ft_rrotate_motion((*ab)->a, &(*ab)->a_ppos);
	ret_b = ft_rrotate_motion((*ab)->b, &(*ab)->b_ppos);
	if (ret_a && ret_b && apply == 1)
		ft_moveappend(ab, "rrr");
	else if (ret_a && apply == 1)
		ft_moveappend(ab, "rra");
	else if (ret_b && apply == 1)
		ft_moveappend(ab, "rrb");
}
