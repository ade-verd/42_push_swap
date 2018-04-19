/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 19:15:54 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_motions_reader(t_heaps **ab)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_moveappend(ab, line);
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_error(ab, "get_next_line");
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
		//ft_displaymoves(&ab, 1);
		ft_heaps_del(&ab);
	}
	else
		ft_error(&ab, 0);
	return (ac);
}
