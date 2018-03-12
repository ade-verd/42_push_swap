/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/12 18:13:11 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_count_val(t_stack *stack, int val, char *sign)
{
	int		count;

	count = ft_strchr(sign, '=') ? -1 : 0;
	while (stack)
	{
		if (sign[0] == '>' && stack->nb > val)
			count++;
		else if (sign[0] == '<' && stack->nb < val)
			count++;
		else if (ft_strchr(sign, '=') && stack->nb == val)
			count++;
		stack = stack->previous;
	}
	return (count);
}

int		ft_count_bad(t_stack *stack, int pivot, int pos)
{
	int		count;

	count = 0;
	while (stack)
	{
		if (stack->nb > pivot && stack->index > pos)
			count++;
		if (stack->nb < pivot && stack->index < pos)
			count++;
		stack = stack->previous;
	}
	return (count);
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

void 	ft_rsorter(t_heaps **ab, int pivot_pos)
{
	if (pivot_pos <= 0)
		return ;
	if ((*ab)->count > 2)
	{
		ft_pivot_value(ab, pivot_pos);
		ft_interject_pivot(ab);
		ft_heaps_display(ab, 'a' + 'b');
		printf("REVERSE SORT pos:%d\n", pivot_pos);
		if ((ft_count_bad((*ab)->a, (*ab)->pivot, pivot_pos)) == 0)
			ft_rsorter(ab, pivot_pos - 1);
		else
			ft_rsorter(ab, pivot_pos);
	}
	else if ((*ab)->count == 2 && ((*ab)->a->nb > (*ab)->a->previous->nb))
		ft_swap_a(ab);
}

void 	ft_sorter(t_heaps **ab, int pivot_pos)
{
	if (pivot_pos > (*ab)->a->index)
	//	ft_rsorter(ab, (*ab)->a->index);
		return ;
	if ((*ab)->count > 2)
	{
		ft_pivot_value(ab, pivot_pos);
		ft_interject_pivot(ab);
		ft_heaps_display(ab, 'a' + 'b');
		printf("SORT pos:%d\n", pivot_pos);
		if ((ft_count_bad((*ab)->a, (*ab)->pivot, pivot_pos)) == 0)
			ft_sorter(ab, pivot_pos + 1);
		else
			ft_sorter(ab, pivot_pos);
	}
	else if ((*ab)->count == 2 && ((*ab)->a->nb > (*ab)->a->previous->nb))
		ft_swap_a(ab);
}
