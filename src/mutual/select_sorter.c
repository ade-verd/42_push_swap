/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:34:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 18:26:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_first_three_values(t_heaps **ab, t_stack **work, int n)
{
	int		min;
	int		max;
	int		top;
	int		btm;

	ft_find_minmax(*work, &min, &max, n);
	top = (*work)->sens == 1 ? min : max;
	btm = (*work)->sens == 1 ? max : min;
	if (ft_find_index(*work, btm) >= (*work)->index - 1)
	{
		if (ft_find_index(*work, btm) == (*work)->index)
			(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
		(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
		(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
		(*work)->id == 'a' ? ft_push_a(ab, 1) : ft_push_b(ab, 1);
	}
	if (!ft_issortn(*work, n))
		(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
}

static void	ft_three_values(t_heaps **ab, t_stack **work, int n)
{
	int		min;
	int		max;
	int		top;
	int		btm;

	ft_find_minmax(*work, &min, &max, n);
	top = (*work)->sens == 1 ? min : max;
	btm = (*work)->sens == 1 ? max : min;
	if (ft_find_index(*work, btm) == 3)
		(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
	else if (ft_find_index(*work, btm) == 2)
		(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	if (!ft_issort(*work))
		(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
}

static void	ft_n_more_values(t_heaps **ab, t_stack **work, int n)
{
	int		min;
	int		max;
	int		top;
	int		btm;
	int		c;

	ft_find_minmax(*work, &min, &max, n);
	top = (*work)->sens == 1 ? min : max;
	btm = (*work)->sens == 1 ? max : min;
	c = ft_place(ab, *work, top, (*work)->index);
	if (!ft_issortn(*work, n))
		(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
	while (c && !ft_issortn(*work, n))
	{
		if (c < 0)
			(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		else if (c > 0)
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
		c < 0 ? c++ : c--;
	}
	ft_select_sorter(ab, work, n - 1);
	(*work)->id == 'a' ? ft_push_a(ab, 1) : ft_push_b(ab, 1);
}

static void	ft_more_values(t_heaps **ab, t_stack **work)
{
	int		min;
	int		max;
	int		top;
	int		btm;
	int		i;

	i = 0;
	while ((*work)->index > 3 && !ft_issort(*work))
	{
		ft_find_minmax(*work, &min, &max, (*work)->index);
		top = (*work)->sens == 1 ? min : max;
		btm = (*work)->sens == 1 ? max : min;
		ft_place(ab, *work, top, (*work)->index);
		(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
		i++;
	}
	ft_select_sorter(ab, work, (*work)->index);
	while (i--)
		(*work)->id == 'a' ? ft_push_a(ab, 1) : ft_push_b(ab, 1);
}

void		ft_select_sorter(t_heaps **ab, t_stack **work, int n)
{
	if (!*work || ft_issortn(*work, n))
		return ;
	if ((*work)->index == 2 || (n == 2 && !ft_issortn(*work, n)))
	{
		if ((((*work)->id == 'a' && (*work)->nb == *(*work)->max))
			|| (((*work)->id == 'b' && (*work)->nb == *(*work)->min)))
			(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		else
			(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
	}
	else if ((*work)->index == 3 || (n == 3 && !ft_issortn(*work, n)))
		n != (*work)->index ? ft_first_three_values(ab, work, n)
			: ft_three_values(ab, work, n);
	else if (n > 3 && !ft_issortn(*work, n))
		n != (*work)->index ? ft_n_more_values(ab, work, n)
			: ft_more_values(ab, work);
}
