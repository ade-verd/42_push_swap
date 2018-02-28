/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 19:51:12 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_heaps_init(t_heaps **ab)
{
	if (!(*ab = (t_heaps*)malloc(sizeof(t_heaps))))
	{
		ft_putstr("Error\n");
		exit (0);
	}
	(*ab)->a = NULL;
	(*ab)->b = NULL;
}

void	ft_heaps_del(t_heaps **ab)
{
	ft_stackdel(&(*ab)->a);
	ft_stackdel(&(*ab)->b);
	ft_memdel((void**)ab);
}

void	ft_heaps_display(t_heaps **ab, unsigned char c)
{
	if (c == 'a')
	{
		ft_stackdisplay(&(*ab)->a, c);
		ft_putstr("___\n");
	}
	else if (c == 'b')
	{
		ft_stackdisplay(&(*ab)->b, c);
		ft_putstr("___\n");
	}
	else
	{
		ft_stackdisplay(&(*ab)->a, 'a');
		ft_stackdisplay(&(*ab)->b, 'b');
		ft_putstr("___\n");
	}
}
