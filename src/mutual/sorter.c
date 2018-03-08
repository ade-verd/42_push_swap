/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:24:56 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/08 12:32:20 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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