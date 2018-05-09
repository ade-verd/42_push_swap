/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:24:17 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 19:21:18 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** void	ft_apply_move(t_heaps **ab, char *move)
** Applies move
*/

void	ft_apply_move(t_heaps **ab, char *move)
{
	int			i;
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
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}

/*
** void	ft_apply_rmove(t_heaps **ab, char *move)
** Applies reverse move
*/

void	ft_apply_rmove(t_heaps **ab, char *move)
{
	int			i;
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
			tab[i].f(ab, 0);
			return ;
		}
		i++;
	}
}

/*
** void	ft_applymoves_classic(t_heaps **ab)
** Applies every movements of the buffer without viewer and user command
*/

void	ft_applymoves_classic(t_heaps **ab)
{
	!*ab ? ft_error(ab, 0) : none;
	if (ft_issort((*ab)->a) && !(*ab)->b)
		return ;
	while ((*ab)->buff)
	{
		ft_apply_move(ab, (*ab)->buff->move);
		ft_deal_options_vsc(ab);
		if (!(*ab)->buff->prev)
			break ;
		(*ab)->buff = (*ab)->buff->prev;
	}
}

/*
** void	ft_applymoves_viewer(t_heaps **ab)
** Applies movements of the buffer with viewer and user command
*/

void	ft_applymoves_viewer(t_heaps **ab)
{
	int		*sens;

	!*ab || !(*ab)->buff || !(*ab)->winenv ? ft_error(ab, 0) : none;
	while ((*ab)->buff && (*ab)->buff->index > 1)
		(*ab)->buff = (*ab)->buff->next;
	ft_viewer_draw(ab);
	while ((*ab)->winenv->end != 1)
	{
		sens = &(*ab)->winenv->sens;
		if (*sens == 1)
		{
			ft_apply_move(ab, (*ab)->buff->move);
			ft_deal_options_vsc(ab);
			if ((*ab)->buff->prev && *sens == 1)
				(*ab)->buff = (*ab)->buff->prev;
		}
		else if (*sens == -1)
		{
			ft_apply_rmove(ab, (*ab)->buff->move);
			ft_deal_options_vsc(ab);
			if ((*ab)->buff->next && *sens == -1)
				(*ab)->buff = (*ab)->buff->next;
		}
	}
	ft_applymoves_classic(ab);
}
