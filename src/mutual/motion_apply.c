/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <aurelien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:24:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/29 19:20:22 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_apply_move(t_heaps **ab, char *move)
{
	int 		i;
	const t_fct	tab[] = {{ "sa", "sb", ft_swap_a }, { "sb", "sa", ft_swap_b },
			{ "ss", "ss", ft_swap_ab }, { "pb", "pa", ft_push_b },
			{ "pa", "pb", ft_push_a }, { "rra", "ra", ft_rrotate_a },
			{ "rrb", "rb", ft_rrotate_b }, { "rr", "rr", ft_rrotate_ab },
			{ "ra", "rra", ft_rotate_a }, { "rb", "rrb", ft_rotate_b },
			{ "rrr", "rrr", ft_rotate_ab }, { "", "", 0 }};

	i = 0;
	while (tab[i].move[0])
	{
		if (ft_strcmp(tab[i].move, move) == 0)
		{
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}

void	ft_apply_rmove(t_heaps **ab, char *move)
{
	int 		i;
	const t_fct	tab[] = {{ "sa", "sb", ft_swap_a }, { "sb", "sa", ft_swap_b },
			{ "ss", "ss", ft_swap_ab }, { "pb", "pa", ft_push_b },
			{ "pa", "pb", ft_push_a }, { "rra", "ra", ft_rrotate_a },
			{ "rrb", "rb", ft_rrotate_b }, { "rr", "rr", ft_rrotate_ab },
			{ "ra", "rra", ft_rotate_a }, { "rb", "rrb", ft_rotate_b },
			{ "rrr", "rrr", ft_rotate_ab }, { "", "", 0 }};

	i = 0;
	while (tab[i].rmove[0])
	{
		if (ft_strcmp(tab[i].rmove, move) == 0)
		{
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}
