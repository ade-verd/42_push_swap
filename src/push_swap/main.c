/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/07 12:38:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		ft_heaps_display(ab, 'a' + 'b');
**		ft_heaps_display(ab, 'a');
**		ft_heaps_display(ab, 'b');
**		ft_swap_a(ab);
**		ft_swap_b(ab);
**		ft_swap_ab(ab);
**		ft_push_a(ab);
**		ft_push_b(ab);
**		ft_rotate_a(ab);
**		ft_rotate_b(ab);
**		ft_rotate_ab(ab);
**		ft_rrotate_a(ab);
**		ft_rrotate_b(ab);
**		ft_rrotate_ab(ab);
*/

void	ft_motions(t_heaps **ab)
{
	ft_heaps_display(ab, 'a' + 'b');
	ft_push_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_push_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_push_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_push_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_push_a(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_rrotate_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_rrotate_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_rrotate_b(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_rrotate_ab(ab);
	ft_heaps_display(ab, 'a' + 'b');
	ft_del_allmoves(ab);
	ft_rrotate_ab(ab);
	ft_heaps_display(ab, 'a' + 'b');
}

int		main(int ac, char **av)
{
	t_heaps		*ab;

	if (ac > 1)
	{
		ft_heaps_init(&ab);
		if (!(ft_read_and_fillstack(ac, av, &ab)))
			return (0);
		ft_motions(&ab);
		ft_displaymoves(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (0);
}
