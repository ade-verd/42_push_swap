/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject_method2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/21 19:19:14 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_place_on_target(t_heaps **ab, t_stack **work, int toplace_ind, int target_index)
{
	float	median_index;
	int 	sens;

	//printf("START REPLACE\n___\n");
	median_index = (*work)->index / 2;
	sens = toplace_ind > median_index ? 1 : -1;
	while (toplace_ind != target_index)
	{
		if (sens == 1)
		{
			(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
			toplace_ind = toplace_ind == (*work)->index ? 1 : toplace_ind + 1;
		}
		else
		{
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
			toplace_ind = toplace_ind == 1 ? (*work)->index : toplace_ind - 1;
		}
		if (toplace_ind > (*work)->index)
			exit(0);
	}
	//printf("END REPLACE\n___\n");
}

void	ft_interject_pivot_push(t_heaps **ab, t_stack **work, t_stack **other)
{
	int		count;
	int		push;
	int 	pivot;

	push = 0;
	count = ft_count_val(*work, *(*work)->pval, "<");
	pivot = *(*work)->pval;
//	printf("%s\n", __FUNCTION__);
	while (*ab && *work && count)
	{
		if ((*work)->nb < pivot)
		{
			(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			push++;
			if ((*other)->next && (*other)->nb < (*other)->next->nb)
				(*other)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
			count--;
		}
		else
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
	}
	ft_place_on_target(ab, work, *(*work)->ppos, (*work)->index);
	while (*ab && *other && push)
	{
		if ((*other)->next && (*other)->nb < (*other)->next->nb)
			(*other)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
		else
		{
			(*other)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			push--;
		}
	}
}

void	ft_interject_pivot(t_heaps **ab, t_stack **work)
{
//	int		max_index;
	t_stack	**other;

	other = (*work)->id == 'a' ? &(*ab)->b : &(*ab)->a;
	/*if ((*ab)->a_pval == (*ab)->min && (*ab)->a_ppos != (*ab)->a->index)
	{
		ft_place_on_target(ab, work, (*ab)->a_ppos, (*ab)->a->index);
		ft_push_b(ab, 1);
		if ((max_index = ft_find_index((*ab)->a, (*ab)->max)) > 1)
			ft_place_on_target(ab, work, max_index, 1);
		ft_push_a(ab, 1);
	}
	else*/
		ft_interject_pivot_push(ab, work, other);
}
