/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/16 18:17:29 by ade-verd         ###   ########.fr       */
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
		if (toplace_index > (*ab)->a->index)
			exit(0);
	}
	//printf("END REPLACE\n___\n");
}

void	ft_interject_pivot_pushinf(t_heaps **ab)
{
	int		count;
	int 	pivot;

	count = ft_count_val((*ab)->a, (*ab)->pivot, "<");
	pivot = (*ab)->pivot;
//	printf("%s\n", __FUNCTION__);
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

//	printf("%s\n", __FUNCTION__);
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
	t_heaps	*tmp;
	int 	count;

	ft_heaps_init(&tmp);
	ft_heaps_cpy(tmp, *ab);
	f(&tmp);
	count = tmp->buff->index;
	ft_heaps_del(&tmp);
	return (count);
}

void	ft_interject_pivot(t_heaps **ab)
{
	int 	max_index;
	int		ret1;
	int		ret2;

	//ft_heaps_display(ab, 'a' + 'b');
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
		ret1 = 0;
		ret2 = 1;
//		ret1 = ft_count_moves(ab, &ft_interject_pivot_pushinf);
//		ret2 = ft_count_moves(ab, &ft_interject_pivot_pushsup);
		//printf("inf:%d\tsup:%d\n", ret1, ret2);
		if (ret1 <= ret2)
		{
		//	printf("SUP\n");
			ft_interject_pivot_pushinf(ab);
		}
		else
		{
		//	printf("SUP\n");
			ft_interject_pivot_pushsup(ab);
		}
	}
}
