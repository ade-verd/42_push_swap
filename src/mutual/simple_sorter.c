/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:34:11 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/29 15:11:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_simple_sorter(t_heaps **ab, t_stack **work)
{

}

void static	ft_two_values(t_heaps **ab, t_stack **work)
{
	if ((*work)->index == 2)
	{
		if (((*work)->sens == 1 && (*work)->nb > (*work)->next->nb)
			|| ((*work)->sens == 0 && (*work)->nb < (*work)->next->nb))
			(*work)->id == 'a' ? ft_swap_a(ab, 1) : ft_swap_b(ab, 1);
	}
}

void static	ft_three_values(t_heaps **ab, t_stack **work)
{
	if ((*work)->index == 3 && !ft_issort(*work))
	{
		if (((*work)->sens == 1)
		{


		}
		else
		{

		}
	}
}
