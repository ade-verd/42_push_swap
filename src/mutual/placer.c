/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 14:13:19 by ade-verd         ###   ########.fr       */
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
		ft_rotatew(ab, &work, 0);
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
		ft_rrotatew(ab, &work, 0);
		count++;
	}
	return (count);
}

int			ft_place(t_heaps **ab, t_stack *w, int toplace_v, int targ_p)
{
	int		tmp;
	int		r;
	int		rr;

	r = 0;
	rr = 0;
	tmp = w->nb;
	r = ft_target_r(ab, w, toplace_v, targ_p);
	ft_target_rr(ab, w, tmp, w->index);
	rr = ft_target_rr(ab, w, toplace_v, targ_p);
	ft_target_r(ab, w, tmp, w->index);
	tmp = ft_abs(r) < rr ? r : rr;
	while (r++ && rr--)
		if (w->nb != toplace_v)
			ft_abs(r) < rr ? ft_rotatew(ab, &w, 1) : ft_rrotatew(ab, &w, 1);
	return (tmp);
}

void		ft_place2(t_heaps **ab, t_stack **w, int v, int targ_p)
{
	int		ref;
	int		r;
	int		rr;
	int		next;

	r = 0;
	rr = 0;
	ref = (*w)->nb;
	next = (*w)->id == 'a' ? ft_find_next(*w, v) : ft_find_prev(*w, v);
	r = ft_target_r(ab, *w, v, targ_p);
	ft_target_rr(ab, *w, ref, (*w)->index);
	rr = ft_target_rr(ab, *w, v, targ_p);
	ft_target_r(ab, *w, ref, (*w)->index);
	while (r++ && rr-- && (*w)->nb != v)
	{
		if ((*w)->nb == next)
			ft_pushw(ab, w, 1);
		if ((*w)->nb != v)
			ft_abs(r) < rr ? ft_rotatew(ab, w, 1) : ft_rrotatew(ab, w, 1);
	}
}
