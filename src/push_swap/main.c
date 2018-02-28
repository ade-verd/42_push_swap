/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 18:28:25 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_heaps		*ab;

	if (ac > 1)
	{
		ft_init_heaps(&ab);
		if (!(ft_read_and_fillstack(ac, av, &ab->a)))
			return (0);
		ft_stackdisplay(&stack);
		ft_swap_motion(&stack);
		ft_stackdisplay(&stack);
		ft_swap_motion(&stack);
		ft_stackdisplay(&stack);
		ft_stackdel(&stack);
	}
	else
		ft_error(&stack);
	return (0);
}
