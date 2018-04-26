/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/26 17:11:58 by ade-verd         ###   ########.fr       */
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

void	ft_apply_moves(t_heaps **ab)
{
	int			i;
	const t_fct	tab[] = {{"sa", ft_swap_a}, {"sb", ft_swap_b}, 
					{"ss", ft_swap_ab}, {"pa", ft_push_a}, {"pb", ft_push_b}, 
					{"ra", ft_rotate_a}, {"rb", ft_rotate_b}, 
					{"rra", ft_rrotate_a},{"rrb", ft_rrotate_b}, 
					{"rr", ft_rotate_ab}, {"rrr", ft_rrotate_ab}, {"", 0}};

	if (!*ab || !(*ab)->buff)
		ft_error(ab, 0);
	while ((*ab)->buff && (*ab)->buff->index > 1)
		(*ab)->buff = (*ab)->buff->next;
	while ((*ab)->buff)
	{
		i = 0;
		while (tab[i].move[0])
		{
			if (ft_strcmp(tab[i].move, (*ab)->buff->move) == 0)
				tab[i].f(ab, 0);
			i++;
		}
		ft_deal_options(ab);
		if (!(*ab)->buff->prev)
			break ;
		(*ab)->buff = (*ab)->buff->prev;
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
		ft_apply_moves(&ab);
		ft_result(&ab);
		//ft_displaymoves(&ab, 1);
		//ft_heaps_display(&ab, 'a' + 'b', 0);
		ft_deal_options_quit(&ab);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (ac);
}
