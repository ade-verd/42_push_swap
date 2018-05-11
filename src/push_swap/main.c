/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/11 10:50:02 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_heaps		*ab;
	char		*tab;

	if (ac > 1)
	{
		if (ft_strcmp(av[1], "-h") == 0)
			ft_help();
		ft_heaps_init(&ab);
		ft_read_and_fillstack(ac, av, &ab, &tab);
		ft_sorter(&ab, &ab->a, &ab->b);
		ft_displaymoves(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	while (1)
	{}
	return (0);
}
