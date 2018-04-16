/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/16 19:16:31 by ade-verd         ###   ########.fr       */
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
	int		ref;
	int		r;
	int		rr;

	r = 0;
	rr = 0;
	ref = work->nb;
	r = ft_target_r(ab, work, toplace_v, targ_p);
	ft_target_rr(ab, work, ref, work->index);
	rr = ft_target_rr(ab, work, toplace_v, targ_p);
	ft_target_r(ab, work, ref, work->index);
	if (ft_abs(r) < rr)
	{
		while (r++)
			work->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
	}
	else
	{
		while (rr--)
			work->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	}
	return (ft_abs(r) < rr ? r : rr);
}

int			ft_place2(t_heaps **ab, t_stack **work, int toplace_v, int targ_p)
{
	int		ref;
	int		r;
	int		rr;
	int		next;
	int		penult;

	r = 0;
	rr = 0;
	ref = (*work)->nb;
	next = (*work)->id == 'a' ? ft_find_next(*work, toplace_v) : ft_find_prev(*work, toplace_v);
	penult = (*work)->id == 'a' ? ft_find_next(*work, next) : ft_find_prev(*work, next);
	//printf("%sDEBUUUUUUUUT%s\n", F_GREEN, F_NO);
	r = ft_target_r(ab, *work, toplace_v, targ_p);
	ft_target_rr(ab, *work, ref, (*work)->index);
	rr = ft_target_rr(ab, *work, toplace_v, targ_p);
	ft_target_r(ab, *work, ref, (*work)->index);
	if (ft_abs(r) < rr)
	{
		while (r++ && (*work)->nb != toplace_v)
		{
			if ((*work)->nb == next)
				(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			//if (ft_find_index(*work, next) == -1 && (*work)->nb == penult)
			//	(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			if ((*work)->nb != toplace_v)
				(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		}
	}
	else
	{
		while (rr-- && (*work)->nb != toplace_v)
		{
			if ((*work)->nb == next)
				(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			//if (ft_find_index(*work, next) == -1 && (*work)->nb == penult)
			//	(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			if ((*work)->nb != toplace_v)
				(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
		}
	}
//	printf("%sFIIIIIIIIIIN%s\n", F_RED, F_NO);
	return (ft_abs(r) < rr ? r : rr);
}

void		ft_place_nmax(t_heaps **ab, t_stack *work, int n)
{
	int		max;
	t_stack	*cpy;

	n = (n % 2 == 0) ? (n / 2) : (n / 2) + 1; 
	if (!work)
		return ;
	cpy = work;
	max = cpy->nb;
	while (cpy)
	{
		if (cpy->index > (cpy->index - n) || cpy->index <= n)
			max = cpy->nb > max ? cpy->nb : max;
		cpy = cpy->next;
	}
	ft_place(ab, work, max, work->index);
}

void		ft_place_nmin(t_heaps **ab, t_stack *work, int n)
{
	int		min;
	t_stack	*cpy;

	n = (n % 2 == 0) ? (n / 2) : (n / 2) + 1; 
	if (!work)
		return ;
	cpy = work;
	min = cpy->nb;
	while (cpy)
	{
		if (cpy->index > (cpy->index - n) || cpy->index <= n)
			min = cpy->nb < min ? cpy->nb : min;
		cpy = cpy->next;
	}
	ft_place(ab, work, min, work->index);
}
