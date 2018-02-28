/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 17:40:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] && !ft_strchr("0123456789+-", str[i])) 
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int 	ft_read_and_fillstack(int ac, char **av, t_stack **stack)
{
	while (ac > 1)
	{
		ac--;
		if (ft_isnumber(av[ac]))
			ft_stackpush(stack, ft_atoi(av[ac]));
		else
			ft_error(stack);
	}
	return (1);
}