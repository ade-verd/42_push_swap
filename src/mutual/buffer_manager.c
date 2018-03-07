/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/07 14:16:35 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveappend(t_heaps **ab, char *s)
{
	int 	i;
	t_buff	*new;
	t_buff	*current;

	i = 0;
	if (!(new = (t_buff*)malloc(sizeof(t_buff))))
		ft_error(ab, "malloc");
	while (s[i] && (i < 3))
	{
		new->move[i] = s[i];
		i++;
	}
	new->move[i] = '\0';
	new->next = NULL;
	current = (*ab)->buff;
	if (current)
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		(*ab)->buff = new;
}

void	ft_displaymoves(t_heaps **ab)
{
	t_buff		*current;
	
	if ((*ab) && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current)
		{
			ft_putstr(current->move);
			ft_putchar('\n');
			current = current->next;
		}
	}
}

void	ft_display_lastmove(t_heaps **ab)
{
	t_buff		*current;
	
	if ((*ab) && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current && current->next)
			current = current->next;
		if (current)
		{
			ft_putstr(current->move);
			ft_putchar('\n');
		}
	}
}

void	ft_del_lastmove(t_heaps **ab)
{
	t_buff		*current;
	
	if ((*ab) && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current && current->next && current->next->next)
			current = current->next;
		if (current->next)
		{
			ft_memdel((void**)&current->next);
			current->next = NULL;
		}
		else if (current)
		{
			ft_memdel((void**)&current);
			(*ab)->buff = NULL;
		}
	}
}

void	ft_del_allmoves(t_heaps **ab)
{
	while ((*ab)->buff)
		ft_del_lastmove(ab);
}