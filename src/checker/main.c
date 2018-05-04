/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/04 11:25:26 by ade-verd         ###   ########.fr       */
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

void	ft_applymoves_classic(t_heaps **ab)
{
	!*ab || !(*ab)->buff ? ft_error(ab, 0) : none;
//	while ((*ab)->buff && (*ab)->buff->index > 1)
//		(*ab)->buff = (*ab)->buff->next;
	while ((*ab)->buff)
	{
		ft_apply_move(ab, (*ab)->buff->move);
		if ((*ab)->option_s == 1)
			ft_heaps_display(ab, 'a' + 'b', 1);
		if (!(*ab)->buff->prev)
			break ;
		(*ab)->buff = (*ab)->buff->prev;
	}
}

void	ft_applymoves_viewer(t_heaps **ab)
{
//	int		stop_prev;
	int		*sens;

//	stop_prev = 0;
	!*ab || !(*ab)->buff || !(*ab)->winenv ? ft_error(ab, 0) : none;
	while ((*ab)->buff && (*ab)->buff->index > 1)
		(*ab)->buff = (*ab)->buff->next;
	ft_viewer_draw(ab);
	//while ((*ab)->buff && (*ab)->winenv->end != 1)
	while ((*ab)->winenv->end != 1)
	{
		sens = &(*ab)->winenv->sens;
		if (*sens == 1)// && stop_prev == 0)
		{
			ft_apply_move(ab, (*ab)->buff->move);
			ft_viewer_draw(ab);
			(*ab)->buff = *sens == 1 ? (*ab)->buff->prev : (*ab)->buff;
		}
		else if (*sens == -1 && (*ab)->buff->next)
		{
			ft_apply_rmove(ab, (*ab)->buff->move);
			ft_viewer_draw(ab);
			(*ab)->buff = *sens == -1 ? (*ab)->buff->next : (*ab)->buff;
		}
	}
	ft_applymoves_classic(ab);
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
		while (ab->buff && ab->buff->index > 1)
			ab->buff = ab->buff->next;
		ab->winenv ? ft_applymoves_viewer(&ab) : ft_applymoves_classic(&ab);
		ft_display_result(&ab);
		ft_deal_options_quit(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (ac);
}
