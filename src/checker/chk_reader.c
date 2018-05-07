/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 19:39:14 by ade-verd         ###   ########.fr       */
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
	ft_printf("fd:%d\n", (*ab)->fd);
	while ((ret = get_next_line((*ab)->fd, &move)) > 0)
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

/*
** cf. mutual/reader.c
*/

void	ft_read_n_fillstack_chk(int ac, char **av, t_heaps **ab, char **tab)
{
	int		i;

	if (!(*ab))
		ft_error(ab, "read_and_fillstack");
	while (ac > 1)
	{
		ac--;
		i = ft_countwords(av[ac], ' ');
		tab = ft_strsplit(av[ac], ' ');
		while (--i >= 0)
		{
			ft_printf("%s\n", tab[i]);
			if ((*ab)->option_f == 1 && ft_strstr(tab[i], ".txt"))
			{
				ft_printf("On est là\n");
				ft_option_f_open(ab, tab[i]);
			}
			else
				ft_check_n_push(ab, tab[i]);
		}
		ft_freetab_strsplit(tab);
	}
	if (!(*ab)->a)
		ft_error(ab, 0);
	(*ab)->a_min = (*ab)->min;
	(*ab)->a_max = (*ab)->max;
	(*ab)->count = (*ab)->a->index;
}
