/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/07 19:11:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_pivot_value(t_heaps **ab, int pivot_index)
{
	t_stack	*current;

	if ((*ab) && (*ab)->a)
	{
		current = (*ab)->a;
		while (current && current->index > pivot_index)
			current = current->previous;
		if (current->index == pivot_index)
			(*ab)->pivot = current->nb;
	}
}

void	ft_interject_pivot(t_heaps **ab)
{
	int		count;
	int 	pivot;

	count = (*ab)->count;
	pivot = (*ab)->pivot;
	if (pivot == (*ab)->min)
		ft_rrotate_a(ab);
	else if (pivot != (*ab)->max)
	{
		while ((*ab) && (*ab)->a && count-- > 1)
		{
			if ((*ab)->a->nb <= pivot)
				ft_push_b(ab);
			else
				ft_rotate_a(ab);
			ft_heaps_display(ab, 'a' + 'b');
		}
		while ((*ab) && (*ab)->b)
		{
			ft_push_a(ab);
			ft_heaps_display(ab, 'a' + 'b');
		}
	}
}

/*
**	1.	Chercher la valeur pivot à l'index 1
**	2.	Checker toute la pile et envoyer les valeurs inférieures au pivot dans
**	la pile B
**	3.	Placer le pivot en haut de la pile A
**	4.	Push toutes les valeurs de B vers A (Push A)
**	5.	Recommencer l'opération avec index 1
**	6.	Si aucune opération valeur inférieure, faire avec index 2 ...
**	7.	Réitérer jusqu'à atteindre l'index correspondant au nb de valeurs
*/

void 	ft_sorter(t_heaps **ab)
{
	if ((*ab)->count > 2)
	{
		ft_pivot_value(ab, 1);
		ft_interject_pivot(ab);
	}
	else if ((*ab)->count == 2 && ((*ab)->a->nb > (*ab)->a->previous->nb))
		ft_swap_a(ab);
}