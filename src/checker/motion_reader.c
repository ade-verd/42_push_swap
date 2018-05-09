/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 13:37:22 by ade-verd         ###   ########.fr       */
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
