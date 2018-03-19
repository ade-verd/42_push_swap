/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_interject_method1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:21:44 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/19 19:14:36 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_place_on_target(t_heaps *ab, int toplace_indx, int target_index)
{
	float	median_index;
	int 	sens;

	//printf("START REPLACE\n___\n");
	median_index = ab->a->index / 2;
	sens = toplace_indx > median_index ? 1 : -1;
	while (toplace_indx != target_index)
	{
		if (sens == 1)
		{
			ft_rotate_a(ab, 1);
			toplace_indx = toplace_indx == ab->a->index ? 1 : toplace_indx + 1;
		}
		else
		{
			ft_rrotate_a(ab, 1);
			toplace_indx = toplace_indx == 1 ? ab->a->index : toplace_indx - 1;
		}
		if (toplace_indx > ab->a->index)
			exit(0);
	}
	//printf("END REPLACE\n___\n");
}

void	ft_interject_pivot_pushinf(t_heaps *ab)
{
	int		count;
	int 	pivot;

	count = ft_count_val(ab->a, ab->a->p_val, "<");
	pivot = ab->a->p_val;
//	printf("%s\n", __FUNCTION__);
	while (ab && ab->a && count)
	{
		if (ab->a->nb < pivot)
		{
			ft_push_b(ab, 1);
			if (ab->b->next && ab->b->nb < ab->b->next->nb)
				ft_swap_b(ab, 1);
			count--;
		}
		else
			ft_rrotate_a(ab, 1);
	}
	ft_place_on_target(ab, ab->a->p_pos, ab->a->index);
	while (ab && ab->b)
	{
		if (ab->b->next && ab->b->nb < ab->b->next->nb)
			ft_swap_b(ab, 1);
		else
			ft_push_a(ab, 1);
	}
}

void	ft_interject_pivot_pushsup(t_heaps *ab)
{
	int 	count;
	int 	pivot;

//	printf("%s\n", __FUNCTION__);
	count = ft_count_val(ab->a, ab->a->p_val, ">");
	pivot = ab->a->p_val;
	while (ab && ab->a && count)
	{
		if (ab->a->nb > pivot)
		{
			ft_push_b(ab, 1);
			if (ab->b->next && ab->b->nb > ab->b->next->nb)
				ft_swap_b(ab, 1);
			count--;
		}
		else
			ft_rotate_a(ab, 1);
	}
	ft_place_on_target(ab, ab->a->p_pos, 1);
	while (ab && ab->b)
	{
		if (ab->b->next && ab->b->nb > ab->b->next->nb)
			ft_swap_b(ab, 1);
		else
		{
			ft_push_a(ab, 1);
			ft_rotate_a(ab, 1);
		}
	}
}

int		ft_count_moves(t_heaps *ab, void (*f)(t_heaps*))
{
	t_heaps	*tmp;
	int 	count;

	ft_heaps_init(&tmp);
	ft_heaps_cpy(tmp, ab);
	f(tmp);
	count = tmp->buff->index;
	ft_heaps_del(tmp);
	return (count);
}

void	ft_interject_pivot(t_heaps *ab)
{
	int 	max_index;
	int		ret1;
	int		ret2;

	//ft_heaps_display(ab, 'a' + 'b');
	if (ab->a->p_val == ab->min && ab->a->p_pos != ab->a->index)
	{
		ft_place_on_target(ab, ab->a->p_pos, ab->a->index);
		ft_push_b(ab, 1);
		if ((max_index = ft_find_index(ab->a, ab->max)) > 1)
			ft_place_on_target(ab, max_index, 1);
		ft_push_a(ab, 1);
	}
	else
	{
		ret1 = 0;
		ret2 = 1;
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
