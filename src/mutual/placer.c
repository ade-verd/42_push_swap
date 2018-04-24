/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 16:21:04 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_moves2top(t_stack *w, int toplace_v)
{
	int		r;
	int		rr;
	int		top;

	if ((ft_find_index(w, toplace_v)) == -1)
		return (0);
	if (w->nb == toplace_v)
		return (0);
	top = w->index;
	r = top - ft_find_index(w, toplace_v);
	rr = ft_find_index(w, toplace_v);
	return (r < rr ? -r : rr);
}

static int	ft_moves2next(t_stack *o, int toplace_v)
{
	int		moves;

	if (!o)
		return (0);
	moves = ft_abs(ft_moves2top(o, ft_find_next(o, toplace_v)));
	return (moves);
}

int			ft_find_bestmove(t_stack **w, t_stack **o)
{
	int		bestval;
	int		bestmove;
	int		count;
	t_stack	*cpy;

	if (!*w)
		return (0);
	cpy = *w;
	bestval = cpy->nb;
	bestmove = 0;
	while (cpy)
	{
		count = ft_abs(ft_moves2top(*w, cpy->nb)) + ft_moves2next(*o, cpy->nb);
		count++;
		if ((count < bestmove) || !bestmove)
		{
			bestmove = count;
			bestval = cpy->nb;
		}
		cpy = cpy->next;
	}
	return (bestval);
}

int			ft_placetop(t_heaps **ab, t_stack **w, int toplace_v)
{
	int		mv;
	int		tmp;
	int		top;
	int		count;

	mv = 0;
	top = (*w)->index;
	mv = ft_moves2top(*w, toplace_v);
	tmp = mv;
	count = 0;
	while (mv && (*w)->nb != toplace_v)
	{
		mv < 0 ? ft_rotatew(ab, w, 1) : ft_rrotatew(ab, w, 1);
		mv = mv < 0 ? mv + 1 : mv - 1;
	}
	return (tmp);
}
