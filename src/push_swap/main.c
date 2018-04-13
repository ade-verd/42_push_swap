/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/13 18:34:38 by ade-verd         ###   ########.fr       */
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
		//ft_heaps_display(&ab, 'a' + 'b', 0);
		//ft_sorter(&ab, &ab->a, ft_nextpivot(&ab->a, 'N'));
		//ft_sorter(&ab, &ab->a, ab->a->index);
		//ft_mergesorter(&ab, &ab->a, 2);
		//ft_simple_sorter(&ab, &ab->a, ab->a->index);
		//ft_find_median(ab->a);
		ft_sorter(&ab, &ab->a, &ab->b);
		//ft_heaps_display(&ab, 'a' + 'b', 0);
		ft_displaymoves(&ab, 1);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (0);
}
