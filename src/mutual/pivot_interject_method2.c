/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject_method2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 18:46:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_place_on_target(t_heaps **ab, t_stack *work, int toplace_ind, int target_index)
{
	float	median_index;
	int 	sens;

	//printf("START REPLACE\n___\n");
	median_index = (*ab)->a->index / 2;
	sens = toplace_ind > median_index ? 1 : -1;
	while (toplace_ind != target_index)
	{
		if (sens == 1)
		{
			ft_rotate_a(ab, 1);
			toplace_ind = toplace_ind == (*ab)->a->index ? 1 : toplace_ind + 1;
		}
		else
		{
			ft_rrotate_a(ab, 1);
			toplace_ind = toplace_ind == 1 ? (*ab)->a->index : toplace_ind - 1;
		}
		if (toplace_ind > (*ab)->a->index)
			exit(0);
	}
	//printf("END REPLACE\n___\n");
}

void	ft_interject_pivot_pushinf(t_heaps **ab, t_stack *work)
{
	int		count;
	int 	pivot;

	count = ft_count_val((*ab)->a, (*ab)->a_pval, "<");
	pivot = (*ab)->a_pval;
//	printf("%s\n", __FUNCTION__);
	while (*ab && (*ab)->a && count)
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
	ft_place_on_target(ab, work, (*ab)->a_ppos, (*ab)->a->index);
	while (*ab && (*ab)->b)
	{
		if ((*ab)->b->next && (*ab)->b->nb < (*ab)->b->next->nb)
			ft_swap_b(ab, 1);
		else
			ft_push_a(ab, 1);
	}
}

void	ft_interject_pivot(t_heaps **ab, t_stack *work)
{
	int 	max_index;
	int		ret1;
	int		ret2;

	/*if ((*ab)->a_pval == (*ab)->min && (*ab)->a_ppos != (*ab)->a->index)
	{
		ft_place_on_target(ab, work, (*ab)->a_ppos, (*ab)->a->index);
		ft_push_b(ab, 1);
		if ((max_index = ft_find_index((*ab)->a, (*ab)->max)) > 1)
			ft_place_on_target(ab, work, max_index, 1);
		ft_push_a(ab, 1);
	}
	else*/
		ft_interject_pivot_pushinf(ab, work);
}
