/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:25 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/12 13:52:55 by ade-verd         ###   ########.fr       */
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

void		ft_choose_push_under_median(t_heaps **ab, t_stack **a, t_stack **b)
{
	t_heaps *cpy;
	int		r;
	int		rr;

	r = 0;
	rr = 0;
	printf("BEFORE TESTS\n");
	ft_heaps_display(ab, 'a' + 'b', 0);
	ft_heaps_init(&cpy);
	ft_heaps_cpy(cpy, *ab);
	printf("BEFORE TESTS CPY:\n");
	ft_heaps_display(&cpy, 'a' + 'b', 0);
	ft_push_under_median(&cpy, &cpy->a, &cpy->b, 'r');
	r = cpy->buff->index;
	ft_heaps_display(ab, 'a' + 'b', 0);
	printf("AFTER TESTS CPY:\n");
	ft_heaps_display(&cpy, 'a' + 'b', 0);
	ft_heaps_del(&cpy);
	printf("AFTER TESTS R\n");
	ft_heaps_init(&cpy);
	ft_heaps_cpy(cpy, *ab);
	ft_push_under_median(&cpy, &cpy->a, &cpy->b, 'R');
	rr = cpy->buff->index;
	ft_heaps_del(&cpy);
	printf("AFTER TESTS RR\n");
	ft_heaps_display(ab, 'a' + 'b', 0);
	if (r < rr)
	{
		printf("\t\tr:%d < rr:%d\t", r, rr);
		printf("r is the best\n");
		ft_push_under_median(ab, a, b, 'r');
	}
	else
	{
		printf("\t\tr:%d < rr:%d\t", r, rr);
		printf("\t\trr is the best\t");
		ft_push_under_median(ab, a, b, 'R');
	}
	printf("AFTER APPLY\n");
	ft_heaps_display(ab, 'a' + 'b', 0);
}
