/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject_method3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/06 15:04:38 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Revoir la fonction en testant le nombre de coups*/
void	ft_place_on_target(t_heaps **ab, t_stack **work,
			int toplace_ind, int target_index)
{
	float	median_index;
	int 	sens;

	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	printf("Toplace:%d\tTarget:%d\n", toplace_ind, target_index);
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
}

void	ft_sort_repush(t_heaps **ab, t_stack **other, int push)
{
	printf("%s\twork: %c\n", __FUNCTION__, (*other)->id - 32);
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
	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	int		push;
	int 	pvl;
	int 	ppos;
	int		count;

	push = 0;
	pvl = *(*work)->pval;
	ppos = *(*work)->ppos;
	count = sens == 1 ? ft_countv(*work, pvl, "<") : ft_countv(*work, pvl, ">");
	while (*ab && *work && count)
	{
		if ((*work)->index < 4)
			ft_simple_sorter(ab, work, (*work)->index);
		else if ((sens == 1 && (*work)->nb < pvl) || (sens == 0 && (*work)->nb > pvl))
		{
			(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
			count--;
		}
		else
			(*work)->id == 'a' ? ft_rotate_a(ab, 1) : ft_rotate_b(ab, 1);
		*othr && !ft_issort(*othr) ? ft_simple_sorter(ab, othr, (*othr)->index) : none;
	}
	//!ft_issort(*work) ? ft_sorter(ab, work, ft_nextpivot(work, 'N')) : none;
	//if (!ft_issort(*work))
	//ft_place_on_target(ab, work, *(*work)->ppos, (*work)->index);
	//ft_sort_repush(ab, othr, push);
}

void	ft_interject_pivot(t_heaps **ab, t_stack **work)
{
	t_stack	**other;

	printf("%s\twork: %c\n", __FUNCTION__, (*work)->id - 32);
	other = (*work)->id == 'a' ? &(*ab)->b : &(*ab)->a;
	ft_interject(ab, work, other, (*work)->sens);
	while (*other)
		(*work)->id == 'a' ? ft_push_b(ab, 1) : ft_push_a(ab, 1);
}
