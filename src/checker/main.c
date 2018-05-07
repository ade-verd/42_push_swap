/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 14:18:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checkmove(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	if (ft_strcmp(line, "sb") == 0)
		return (1);
	if (ft_strcmp(line, "ss") == 0)
		return (1);
	if (ft_strcmp(line, "ra") == 0)
		return (1);
	if (ft_strcmp(line, "rb") == 0)
		return (1);
	if (ft_strcmp(line, "rr") == 0)
		return (1);
	if (ft_strcmp(line, "rra") == 0)
		return (1);
	if (ft_strcmp(line, "rrb") == 0)
		return (1);
	if (ft_strcmp(line, "rrr") == 0)
		return (1);
	if (ft_strcmp(line, "pa") == 0)
		return (1);
	if (ft_strcmp(line, "pb") == 0)
		return (1);
	return (0);
}

int		ft_motions_reader(t_heaps **ab)
{
	int		ret;
	char	*move;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while ((ret = get_next_line(0, &move)) > 0)
	{
		if (ft_strstr(move, "Error"))
		{
			ft_printf("%s\n", move);
			ft_error(ab, "NO");
		}
		if (!ft_checkmove(move))
			ft_error(ab, 0);
		ft_moveappend(ab, move);
		ft_strdel(&move);
		nb++;
	}
	if (ret < 0)
		ft_error(ab, "get_next_line");
	return (nb);
}

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

	if (ac > 1)
	{
		ft_heaps_init(&ab);
		if (!(ft_read_and_fillstack(ac, av, &ab)))
			return (0);
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
