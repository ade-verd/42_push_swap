/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:24:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/19 17:36:31 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_motion(t_heaps *ab, char *move)
{
	int			i;
	const t_fct	tab[] = { { "sa", "sb", ft_swap_b },
	{ "sb", "sa", ft_swap_a },
	{ "ss", "ss", ft_swap_ab },
	{ "pa", "pb", ft_push_b },
	{ "pb", "pa", ft_push_a },
	{ "ra", "rra", ft_rrotate_a },
	{ "rb", "rrb", ft_rrotate_b },
	{ "rr", "rrr", ft_rrotate_ab },
	{ "rra", "ra", ft_rotate_a },
	{ "rrb", "rb", ft_rotate_b },
	{ "rrr", "rr", ft_rotate_ab },
	{ "", "", 0 }
	};

	i = 0;
	while (tab[i].move[0])
	{
		if (ft_strcmp(tab[i].move, move) == 0)
		{
			tab[i].f(ab, 0);
			printf("%s%s%s\t", "\033[0;31m",tab[i].rmove, "\033[0m");
			fflush(stdout);
			ft_heaps_display(ab, 'a' + 'b');
			return ;
		}
		i++;
	}
}