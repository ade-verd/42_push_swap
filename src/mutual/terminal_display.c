/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:41:36 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 17:59:12 by ade-verd         ###   ########.fr       */
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
	int			fd;

	fd = 1;
	if (*ab && (*ab)->buff)
	{
		if (((*ab)->option_f == 1) && (fd = ft_open_fd(OUT_TXT,
					O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
				ft_error(ab, "ft_displaymoves");
		current = (*ab)->buff;
		while (current && current->index > 1)
			current = current->next;
		while (current && current->index > 0)
		{
			ft_dprintf(fd, "%s\n", current->move);
			current = current->prev;
		}
		if (fd != 1)
			ft_printf("output: %s\n", OUT_TXT);
		if (fd != 1 && (ft_close_fd(fd)) == -1)
			ft_error(ab, "ft_displaymoves");
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

void	ft_display_result(t_heaps **ab, int nb_moves)
{
	if (ft_issort((*ab)->a) && !(*ab)->b)
	{
		ft_printf("OK\n");
		if ((*ab)->option_l == 1)
			ft_printf("%d\n", nb_moves);
	}
	else
		ft_printf("KO\n");
}
