/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject_method2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/28 15:13:55 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Revoir la fonction en testant le nombre de coups*/
void	ft_place_on_target(t_heaps **ab, t_stack **work,
											int toplace_ind, int target_index)
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
	}
	//printf("END REPLACE\n___\n");
}

void	ft_sort_n_repush(t_heaps **ab, t_stack **other, int push)
{
	while (*ab && *other && push)
	{
		if ((*other)->next 
				&& (((*other)->sens == 1 && (*other)->nb > (*other)->next->nb)
				|| ((*other)->sens == 0 && (*other)->nb < (*other)->next->nb)))
			(*other)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
		else
			(*other)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
		push--;
	}
}

void	ft_interject(t_heaps **ab, t_stack **work, t_stack **othr, int sens)
{
	int		count;
	int		push;
	int 	pvt;

	push = 0;
	pvt = *(*work)->pval;
	count = sens == 1 ? ft_countv(*work, pvt, "<") : ft_countv(*work, pvt, ">");
//	printf("%s\n", __FUNCTION__);
	//if (*work && (*work)->id == 'b')
	//	exit(0);
	while (*ab && *work && count)
	{
		if ((sens == 1 && (*work)->nb < pvt) || (sens == 0 && (*work)->nb > pvt))
		{
			(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			push++;
			if ((*othr)->next 
					&& (((*othr)->sens == 1 && (*othr)->nb > (*othr)->next->nb)
					|| ((*othr)->sens == 0 && (*othr)->nb < (*othr)->next->nb)))
				(*othr)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
			count--;
		}
		else
			(*work)->id == 'a' ? ft_rrotate_a(ab, 1) : ft_rrotate_b(ab, 1);
		*othr && !ft_issort(*othr) ? ft_rsorter(ab, othr, 1) : none;
	}
	ft_place_on_target(ab, work, *(*work)->ppos, (*work)->index);
	ft_sort_n_repush(ab, othr, push);
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
		ft_interject(ab, work, other, (*work)->sens);
}
