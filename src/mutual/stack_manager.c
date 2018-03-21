/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/21 14:08:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackpush(t_heaps **ab, t_stack **current_link, int new_nb, char id)
{
	t_stack		*new_link;

	if (!(new_link = (t_stack*)malloc(sizeof(t_stack))))
	{
		ft_putstr("malloc() error\n");
		return (-1);
	}
	new_link->nb = new_nb;
	if (!(*current_link))
		new_link->index = 1;
	else
	{
		new_link->index = (*current_link)->index + 1;
		(*current_link)->prev = new_link;
	}
	new_link->id = id;
	new_link->ppos = id == 'a' ? &(*ab)->a_ppos : &(*ab)->b_ppos;
	new_link->pval = id == 'a' ? &(*ab)->a_pval : &(*ab)->b_pval;
	new_link->next = *current_link;
	new_link->prev = NULL;
	*current_link = new_link;
	return (0);
}

int		ft_stackpop(t_stack **stack)
{
	int			nb;
	t_stack		*cpy;

	if (!(*stack))
		return (-1);
	cpy = *stack;
	nb = (*stack)->nb;
	*stack = (*stack)->next;
	ft_memdel((void**)&cpy);
	return (nb);
}

void	ft_stackdisplay(t_stack **stack, unsigned char c, int pval, int ppos)
{
	t_stack		*cpy;
	int 		next;

	ft_printf("%c:\t", ft_toupper(c));
	if (*stack)
	{
		cpy = *stack;
		next = cpy->nb;
		ft_putstr("(top) ");
		while (cpy)
		{
			cpy->nb < next ? ft_putstr(F_RED) : ft_putstr(F_CYAN);
			if (cpy->nb == pval && ppos > 0)
				ft_printf("%s%s", F_BOLD, F_UNDERLINE);
			ft_printf("%d%s", cpy->nb, F_NO);
			//ft_printf("[%d #%d]%s", *cpy->pval, *cpy->ppos, F_NO);
			cpy->next ? ft_putstr(", ") : ft_putstr(" (end)\n");
			next = cpy->nb;
			cpy = cpy->next;
		}
	}
	else
		ft_putstr("(null)\n");
}

int		ft_stacklen(t_stack *stack)
{
	int			i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_stackdel(t_stack **stack)
{
	t_stack		*cpy;

	while (*stack)
	{
		cpy = *stack;
		*stack = (*stack)->next;
		ft_memdel((void**)&cpy);
	}
}
