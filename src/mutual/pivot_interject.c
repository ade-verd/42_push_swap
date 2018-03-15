/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/15 18:18:00 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_place_on_target(t_heaps **ab, int toplace_index, int target_index)
{
	float	median_index;
	int 	sens;

	//printf("START REPLACE\n___\n");
	median_index = (*ab)->a->index / 2;
	sens = toplace_index > median_index ? 1 : -1;
	while (toplace_index != target_index)
	{
		if (sens == 1)
		{
			ft_rotate_a(ab, 1);
			toplace_index = toplace_index == (*ab)->a->index ? 1 : toplace_index + 1;
		}
		else
		{
			ft_rrotate_a(ab, 1);
			toplace_index = toplace_index == 1 ? (*ab)->a->index : toplace_index - 1;
		}
	}
	//printf("END REPLACE\n___\n");
}

void	ft_interject_pivot_pushinf(t_heaps **ab)
{
	int		count;
	int 	pivot;

	count = ft_count_val((*ab)->a, (*ab)->pivot, "<");
	pivot = (*ab)->pivot;
	printf("%s\n", __FUNCTION__);
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb < pivot)
		{
			ft_push_b(ab, 1);
			if ((*ab)->b->next && (*ab)->b->nb < (*ab)->b->next->nb)
				ft_swap_b(ab, 1);
			count--;
		}
		else
			ft_rrotate_a(ab, 1);
	}
	ft_place_on_target(ab, (*ab)->pivot_pos, (*ab)->a->index);
	while ((*ab) && (*ab)->b)
	{
		if ((*ab)->b->next && (*ab)->b->nb < (*ab)->b->next->nb)
			ft_swap_b(ab, 1);
		else
			ft_push_a(ab, 1);
	}
}

void	ft_interject_pivot_pushsup(t_heaps **ab)
{
	int 	count;
	int 	pivot;

	printf("%s\n", __FUNCTION__);
	count = ft_count_val((*ab)->a, (*ab)->pivot, ">");
	pivot = (*ab)->pivot;
	while ((*ab) && (*ab)->a && count)
	{
		if ((*ab)->a->nb > pivot)
		{
			ft_push_b(ab, 1);
			if ((*ab)->b->next && (*ab)->b->nb > (*ab)->b->next->nb)
				ft_swap_b(ab, 1);
			count--;
		}
		else
			ft_rotate_a(ab, 1);
	}
	ft_place_on_target(ab, (*ab)->pivot_pos, 1);
	while ((*ab) && (*ab)->b)
	{
		if ((*ab)->b->next && (*ab)->b->nb > (*ab)->b->next->nb)
			ft_swap_b(ab, 1);
		else
		{
			ft_push_a(ab, 1);
			ft_rotate_a(ab, 1);
		}
	}
}

int		ft_count_moves(t_heaps **ab, void (*f)(t_heaps**))
{
	int 	ref_buffindex;
	int 	count;

	ref_buffindex = (*ab)->buff->index;
	f(ab);
	count = (*ab)->buff->index - ref_buffindex;
	while ((*ab)->buff->index > ref_buffindex)
		ft_del_lastmove(ab);
	return (count);
}

void	ft_interject_pivot(t_heaps **ab)
{
	int 	max_index;

	if ((*ab)->pivot == (*ab)->min && (*ab)->pivot_pos != (*ab)->a->index)
	{
		ft_place_on_target(ab, (*ab)->pivot_pos,(*ab)->a->index);
		ft_push_b(ab, 1);
		if ((max_index = ft_find_index((*ab)->a, (*ab)->max)) > 1)
			ft_place_on_target(ab, max_index, 1);
		ft_push_a(ab, 1);
	}
	else
	{
	/*	if (ft_count_val((*ab)->a, (*ab)->pivot, "<")
			<= (ft_count_val((*ab)->a, (*ab)->pivot, ">") + 1))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushsup(ab);*/
		if (ft_count_moves(ab, &ft_interject_pivot_pushinf) 
			< ft_count_moves(ab, &ft_interject_pivot_pushsup))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushsup(ab);
	}
}
