/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 18:36:12 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** int	ft_checkmove(char *line)
** Checks lines readed 
*/

int		ft_checkmove(char *line)
{
	int		i;
	const t_fct	mv[] = {{ "sa", 0 }, { "sb", 0 }, { "ss", 0 }, { "pa", 0 },
			{ "pb", 0 }, { "ra", 0 }, { "rb", 0 }, { "rr", 0 }, { "rra", 0 },
			{ "rrb", 0 }, { "rrr", 0 }, { "", 0 }};

	i = 0;
	while (mv[i].move[0])
	{
		if (ft_strcmp(line, mv[i].move) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*
** int	ft_motions_reader(t_heaps **ab)
** Reads motions
*/

int		ft_motions_reader(t_heaps **ab)
{
	int		ret;
	char	*move;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
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
