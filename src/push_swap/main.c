/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/03 17:54:23 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_heaps		*ab;

	if (ac > 1)
	{
		ft_heaps_init(&ab);
		if (!(ft_read_and_fillstack(ac, av, &ab)))
			return (0);
		ft_heaps_display(&ab, 'a' + 'b', 0);
		ft_nextpivot(&ab->a, 'N');
		printf("ppos: #%d\tpval: %d\n", *ab->a->ppos, *ab->a->pval);
		//ab->a_pval = ft_find_median(ab->a, &ab->a_ppos, ab->a_min, ab->a_max);
		//ft_sorter(&ab, &ab->a, ab->a_ppos);
		ft_heaps_display(&ab, 'a' + 'b', 0);
		ft_displaymoves(&ab, 1);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (0);
}
