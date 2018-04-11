/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/11 19:07:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_target_r(t_heaps **ab, t_stack *work, int toplace_v, int targ_p)
{
	int		count;

	count = 0;
	if ((ft_find_index(work, toplace_v)) == -1)
		return (0);
	while (ft_find_index(work, toplace_v) != targ_p)
	{
		work->id == 'a' ? ft_rotate_a(ab, 0) : ft_rotate_b(ab, 0);
		count--;
	}
	return (count);
}

static int	ft_target_rr(t_heaps **ab, t_stack *work, int toplace_v, int targ_p)
{
	int		count;

	count = 0;
	if ((ft_find_index(work, toplace_v)) == -1)
		return (0);
	while (ft_find_index(work, toplace_v) != targ_p)
	{
		work->id == 'a' ? ft_rrotate_a(ab, 0) : ft_rrotate_b(ab, 0);
		count++;
	}
	return (count);
}

int			ft_place(t_heaps **ab, t_stack *work, int toplace_v, int targ_p)
{
	t_heaps	*cpy;
	t_stack	*stack;
	int		r;
	int		rr;

	r = 0;
	rr = 0;
	ft_heaps_display(ab, 'a' + 'b', 0);
	ft_heaps_init(&cpy);
	ft_heaps_cpy(cpy, (*ab));
	stack = work->id == 'a' ? cpy->a : cpy->b;
	r = ft_target_r(&cpy, stack, toplace_v, targ_p);
	ft_heaps_del(&cpy);
	ft_heaps_init(&cpy);
	ft_heaps_cpy(cpy, (*ab));
	stack = work->id == 'a' ? cpy->a : cpy->b;
	r = ft_target_r(&cpy, stack, toplace_v, targ_p);
	ft_heaps_del(&cpy);
	if (ft_abs(r) < rr)
		ft_target_r(ab, work, toplace_v, targ_p);
	else
		ft_target_rr(ab, work, toplace_v, targ_p);
	return (ft_abs(r) < rr ? r : rr);
}
