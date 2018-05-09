/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 14:37:51 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_goto_buffindex(t_heaps **ab, int target_index, int applymove)
{
	int		sns;

	!*ab || !(*ab)->buff ? ft_error(ab, 0) : none;
	sns = target_index > (*ab)->buff->index ? 1 : -1;
	while ((*ab)->buff && (*ab)->buff->index != target_index)
	{
		if (applymove == 1 && sns > 0)
			ft_apply_move(ab, (*ab)->buff->move);
		if (applymove == 1 && sns < 0)
			ft_apply_rmove(ab, (*ab)->buff->move);
		if ((sns > 0 && !(*ab)->buff->prev) || (sns < 0 && !(*ab)->buff->next))
			break ;
		(*ab)->buff = sns > 0 ? (*ab)->buff->prev : (*ab)->buff->next;
	}
}

int		main(int ac, char **av)
{
	t_heaps		*ab;
	int			nb_moves;
	char		*tab;

	if (ac > 1)
	{
		ft_heaps_init(&ab);
		ft_read_and_fillstack(ac, av, &ab, &tab);
		if (ab->option_f == 1)
			ft_option_f_open(&ab);
		if ((nb_moves = ft_motions_reader(&ab)))
		{
			ft_deal_options_init(&ab);
			ft_goto_buffindex(&ab, 1, 0);
			ab->winenv ? ft_applymoves_viewer(&ab) : ft_applymoves_classic(&ab);
		}
		ft_display_result(&ab, nb_moves);
		ft_deal_options_quit(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (ac);
}
