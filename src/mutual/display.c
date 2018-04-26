/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:41:36 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/26 15:00:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_heaps_display(t_heaps **ab, unsigned char c, int context)
{
	if (context == 1)
		ft_display_lastmove(ab);
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

void	ft_stackdisplay(t_stack **work, int c)
{
	t_stack		*cpy;
	int			next;

	ft_printf("%c:\t", ft_toupper(c));
	if (*work)
	{
		cpy = *work;
		next = cpy->nb;
		ft_putstr("(top) ");
		while (cpy)
		{
			if (cpy->sens == 1)
				cpy->nb < next ? ft_putstr(F_RED) : ft_putstr(F_CYAN);
			else
				cpy->nb > next ? ft_putstr(F_RED) : ft_putstr(F_CYAN);
			if (cpy->nb == *cpy->pval && *cpy->ppos > 0)
				ft_printf("%s%s", F_BOLD, F_UNDERLINE);
			ft_printf("%d%s", cpy->nb, F_NO);
			cpy->next ? ft_putstr(", ") : ft_putstr(" (bottom)\n");
			next = cpy->nb;
			cpy = cpy->next;
		}
	}
	else
		ft_putstr("(null)\n");
}

void	ft_displaymoves(t_heaps **ab)
{
	t_buf		*current;

	if (*ab && (*ab)->buff)
	{
		current = (*ab)->buff;
		while (current && current->index > 1)
			current = current->next;
		while (current && current->index > 0)
		{
			ft_printf("%s\n", current->move);
			current = current->prev;
		}
	}
}

void	ft_display_lastmove(t_heaps **ab)
{
	if (*ab && (*ab)->buff)
	{
		ft_putstr((*ab)->buff->move);
		ft_putchar('\n');
	}
}
