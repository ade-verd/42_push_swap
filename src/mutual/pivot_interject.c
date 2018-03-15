/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/15 13:36:22 by ade-verd         ###   ########.fr       */
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
			ft_rotate_a(ab);
			toplace_index = toplace_index == (*ab)->a->index ? 1 : toplace_index + 1;
		}
		else
		{
			ft_rrotate_a(ab);
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
			ft_push_b(ab);
			if ((*ab)->b->next && (*ab)->b->nb < (*ab)->b->next->nb)
				ft_swap_b(ab);
			count--;
		}
		else
			ft_rrotate_a(ab);
	}
	ft_place_on_target(ab, (*ab)->pivot_pos, (*ab)->a->index);
	while ((*ab) && (*ab)->b)
	{
		if ((*ab)->b->next && (*ab)->b->nb < (*ab)->b->next->nb)
			ft_swap_b(ab);
		else
			ft_push_a(ab);
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
			ft_push_b(ab);
			if ((*ab)->b->next && (*ab)->b->nb > (*ab)->b->next->nb)
				ft_swap_b(ab);
			count--;
		}
		else
			ft_rotate_a(ab);
	}
	ft_place_on_target(ab, (*ab)->pivot_pos, 1);
	while ((*ab) && (*ab)->b)
	{
		if ((*ab)->b->next && (*ab)->b->nb > (*ab)->b->next->nb)
			ft_swap_b(ab);
		else
		{
			ft_push_a(ab);
			ft_rotate_a(ab);
		}
	}
}

void	ft_interject_pivot(t_heaps **ab)
{
	int 	max_index;

	if ((*ab)->pivot == (*ab)->min && (*ab)->pivot_pos != (*ab)->a->index)
	{
		ft_place_on_target(ab, (*ab)->pivot_pos,(*ab)->a->index);
		ft_push_b(ab);
		if ((max_index = ft_find_index((*ab)->a, (*ab)->max)) > 1)
			ft_place_on_target(ab, max_index, 1);
		ft_push_a(ab);
	}
	else
	{
		if (ft_count_val((*ab)->a, (*ab)->pivot, "<")
			<= (ft_count_val((*ab)->a, (*ab)->pivot, ">") + 1))
			ft_interject_pivot_pushinf(ab);
		else
			ft_interject_pivot_pushsup(ab);
	}
}
