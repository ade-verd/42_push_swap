/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:24:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/02 16:26:52 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_apply_move(t_heaps **ab, char *move)
{
	int 		i;
	const t_fct	tab[] = {{ "sa", ft_swap_a }, { "sb", ft_swap_b },
			{ "ss", ft_swap_ab },
			{ "pa", ft_push_a }, { "pb", ft_push_b },
			{ "ra", ft_rotate_a }, { "rb", ft_rotate_b },
			{ "rr", ft_rotate_ab },
			{ "rra", ft_rrotate_a }, { "rrb", ft_rrotate_b },
			{ "rrr", ft_rrotate_ab }, { "", 0 }};

	i = 0;
	while (tab[i].move[0])
	{
		if (ft_strcmp(tab[i].move, move) == 0)
		{
			ft_printf("%s\t", (*ab)->buff->move);
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}

void	ft_apply_rmove(t_heaps **ab, char *move)
{
	int 		i;
	const t_fct	tab[] = {{ "sa", ft_swap_a }, { "sb", ft_swap_b },
			{ "ss", ft_swap_ab },
			{ "pa", ft_push_b }, { "pb", ft_push_a },
			{ "ra", ft_rrotate_a }, { "rb", ft_rrotate_b },
			{ "rr", ft_rrotate_ab },
			{ "rra", ft_rotate_a }, { "rrb", ft_rotate_b },
			{ "rrr", ft_rotate_ab }, { "", 0 }};

	i = 0;
	while (tab[i].move[0])
	{
		if (ft_strcmp(tab[i].move, move) == 0)
		{
			ft_printf("%s_R\t", (*ab)->buff->move);
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}
