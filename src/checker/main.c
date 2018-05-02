/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/02 11:05:21 by ade-verd         ###   ########.fr       */
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

void	ft_motions_reader(t_heaps **ab)
{
	int		ret;
	char	*move;
	int		i;

	i = 0;
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
	}
	if (ret < 0)
		ft_error(ab, "get_next_line");
}

void	ft_buff_prevnext(t_heaps **ab)
{
	if ((*ab)->winenv && (*ab)->winenv->back == 1 && (*ab)->buff->next->index > 1)
	{
		//ft_apply_reverse_motion(ab);
		(*ab)->winenv->back = 0;
		ft_deal_options(ab);
		(*ab)->buff = (*ab)->buff->next;
	}
	else
		(*ab)->buff = (*ab)->buff->prev;
}

void	ft_buffloop_applymoves(t_heaps **ab)
{
	!*ab || !(*ab)->buff ? ft_error(ab, 0) : none;
	while ((*ab)->buff && (*ab)->buff->index > 1)
		(*ab)->buff = (*ab)->buff->next;
	while ((*ab)->buff)
	{
		ft_apply_move(ab, (*ab)->buff->move);
		//ft_deal_options(ab);
		if (!(*ab)->buff->prev)
			break ;
		(*ab)->buff = (*ab)->buff->prev;
		//ft_buff_prevnext(ab);
	}
}

void	ft_result(t_heaps **ab)
{
	if (ft_issort((*ab)->a) && !(*ab)->b)
	{
		ft_printf("OK\n");
		if ((*ab)->option_l == 1)
			ft_printf("%d\n", (*ab)->buff->index);
	}
	else
		ft_printf("KO\n");
}

int		main(int ac, char **av)
{
	t_heaps		*ab;

	if (ac > 1)
	{
		ft_heaps_init(&ab);
		if (!(ft_read_and_fillstack(ac, av, &ab)))
			return (0);
		ft_motions_reader(&ab);
		ft_deal_options_init(&ab);
		ft_buffloop_applymoves(&ab);
		ft_result(&ab);
		ft_deal_options_quit(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (ac);
}
