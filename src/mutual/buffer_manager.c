/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/15 16:14:54 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveappend(t_heaps **ab, char *s)
{
	int 	i;
	t_buff	*new;

	i = 0;
	if (!(new = (t_buff*)malloc(sizeof(t_buff))))
		ft_error(ab, "malloc");
	while (s[i] && (i < 3))
	{
		new->move[i] = s[i];
		i++;
	}
	new->move[i] = '\0';
	new->prev = NULL; 
	new->next = (*ab)->buff;
	if ((*ab)->buff)
		(*ab)->buff->prev = new;
	(*ab)->buff = new;
	ft_heaps_display(ab, 'a' + 'b');
}

void	ft_displaymoves(t_heaps **ab, int display_number_moves)
{
	t_buff		*current;
	int 		nb;
	
	nb = 0;
	if ((*ab) && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current && current->next)
			current = current->next;
		while (current)
		{
			nb++;
			ft_putstr(current->move);
			if (current->prev) //A supprimer
				ft_putstr(", "); //A supprimer
			//ft_putchar('\n'); //A afficher
			current = current->prev;
		}
		ft_putchar('\n'); //A supprimer
	}
	if (display_number_moves == 1)
	{
		ft_putstr("Number of movements: ");
		ft_putnbr(nb);
		ft_putchar('\n');
	}
}

void	ft_display_lastmove(t_heaps **ab)
{
	if ((*ab) && (*ab)->buff)
	{
		ft_putstr((*ab)->buff->move);
		ft_putchar('\t');
		ft_putstr("pivot: ");
		ft_putnbr((*ab)->pivot);
		ft_putchar('\n');
	}
}

void	ft_del_lastmove(t_heaps **ab)
{
	t_buff	*cpy;

	if ((*ab) && (*ab)->buff && (*ab)->buff->next)
	{
		cpy = (*ab)->buff;
		(*ab)->buff = (*ab)->buff->next;
		(*ab)->buff->prev = NULL;
		ft_memdel((void**)&cpy);
	}
	else if ((*ab) && (*ab)->buff)
	{
		cpy = (*ab)->buff;
		(*ab)->buff = NULL;
		ft_memdel((void**)&cpy);
	}
}

void	ft_del_allmoves(t_heaps **ab)
{
	while ((*ab)->buff)
		ft_del_lastmove(ab);
}