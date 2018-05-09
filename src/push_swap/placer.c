/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 16:11:35 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** static int	ft_moves2top(t_stack *w, int toplace_v)
** Takes an integer and counts the number of moves it would take to place it
** at the top of the stack.
*/

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

/*
** static int	ft_moves2next(t_stack *o, int toplace_v)
** Takes an integer and counts the number of moves it would take to place
** THE NEXT INTEGER OF THE OTHER STACK at the top.
*/

static int	ft_moves2next(t_stack *o, int toplace_v)
{
	int		moves;

	if (!o)
		return (0);
	moves = ft_abs(ft_moves2top(o, ft_find_next(o, toplace_v)));
	return (moves);
}

/*
** int	ft_find_bestmove(t_stack **w, t_stack **o)
** Calculates the number of strokes of each integer using the insert sort method
** Returns the integer that is more interesting to send to the other stack.
*/

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

/*
** int	ft_placetop(t_heaps **ab, t_stack **w, int toplace_v)
** Do the best move on the stack
*/

int			ft_placetop(t_heaps **ab, t_stack **w, int toplace_v)
{
	int		mv;

	mv = ft_moves2top(*w, toplace_v);
	while (mv && (*w)->nb != toplace_v)
		mv < 0 ? ft_rotatew(ab, w, 1) : ft_rrotatew(ab, w, 1);
	return (mv);
}

/*
** void	ft_placetopboth(t_heaps **ab, int b_val, int a_next)
** Do the best move using rr & rrr movements
*/

void		ft_placetopboth(t_heaps **ab, int b_val, int a_next)
{
	int		mv_a;
	int		mv_b;
	int		min;

	mv_a = !(*ab)->a ? 0 : ft_moves2top((*ab)->a, a_next);
	mv_b = !(*ab)->b ? 0 : ft_moves2top((*ab)->b, b_val);
	min = ft_abs(mv_a) < ft_abs(mv_b) ? ft_abs(mv_a) : ft_abs(mv_b);
	while (min-- && ((mv_a > 0 && mv_b > 0) || (mv_a < 0 && mv_b < 0)))
		mv_a < 0 ? ft_rotate_ab(ab, 1) : ft_rrotate_ab(ab, 1);
	ft_placetop(ab, &(*ab)->a, a_next);
	ft_placetop(ab, &(*ab)->b, b_val);
}
