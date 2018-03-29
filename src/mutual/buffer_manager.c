/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:35:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/29 18:35:24 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveappend(t_heaps **ab, char *s)
{
	int 	i;
	t_buf	*new;

	i = 0;
	if (!(new = (t_buf*)malloc(sizeof(t_buf))))
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
	{
		new->index = (*ab)->buff->index + 1;
		(*ab)->buff->prev = new;
	}
	else
		new->index = 1;
	(*ab)->buff = new;
	if ((*ab)->option_v == 1)
		ft_heaps_display(ab, 'a' + 'b', 1);
	else
	{
		if ((*ab)->buff->next)
			ft_putstr("\033[3D");
		ft_printf("%sLast: %s%s%s \n", F_UP, F_YELLOW, (*ab)->buff->move, F_NO);
	}
}

void	ft_displaymoves(t_heaps **ab, int display_number_moves)
{
	t_buf		*current;

	if (*ab && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current && current->index > 1)
			current = current->next;
		while (current && current->index > 0)
		{
			if (current->prev) // A supprimer
				ft_printf("%s, ", current->move); // A supprimer
			else // A supprimer
				ft_printf("%s\n", current->move);
			current = current->prev;
		}
	}
	if (display_number_moves == 1)
		ft_printf("Number of movements: %d\n", (*ab)->buff->index);
}

void	ft_display_lastmove(t_heaps **ab)
{
	if (*ab && (*ab)->buff && ((*ab)->a_ppos > 0 || (*ab)->b_ppos > 0))
	{
		ft_putstr((*ab)->buff->move);
		if ((*ab)->a && (*ab)->a_ppos > 0)
			ft_printf("\tPivot_A: %d #%d", (*ab)->a_pval, (*ab)->a_ppos);
		if ((*ab)->b && (*ab)->b_ppos > 0)
			ft_printf("\tPivot_B: %d #%d", (*ab)->b_pval, (*ab)->b_ppos);
		ft_putchar('\n');
	}
}

void	ft_del_lastmove(t_heaps **ab)
{
	t_buf	*cpy;
	char	move[4];

	if (*ab && (*ab)->buff && (*ab)->buff->next)
	{
		ft_strcpy(move, (*ab)->buff->move);
		cpy = (*ab)->buff;
		(*ab)->buff = (*ab)->buff->next;
		(*ab)->buff->prev = NULL;
		ft_memdel((void**)&cpy);
	}
	else if (*ab && (*ab)->buff)
	{
		ft_strcpy(move, (*ab)->buff->move);
		cpy = (*ab)->buff;
		ft_memdel((void**)&cpy);
	}
}

void	ft_del_allmoves(t_heaps **ab)
{
	while ((*ab)->buff && (*ab)->buff->index > 0)
		ft_del_lastmove(ab);
}