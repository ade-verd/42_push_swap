/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/15 13:27:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackpush(t_stack **current_link, int new_nb, char id)
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
		new_link->index = (*current_link)->index + 1;
	new_link->id = id;
	new_link->next = *current_link;
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

void	ft_stackdisplay(t_stack **stack, unsigned char c)
{
	t_stack		*cpy;
	int 		next;

	ft_putchar(ft_toupper(c));
	ft_putstr(":\t");
	if (*stack)
	{
		cpy = *stack;
		next = cpy->nb;
		ft_putstr("(top) ");
		while (cpy)
		{
			cpy->nb < next ? ft_putstr("\033[31m") : ft_putstr("\033[36m");
			ft_putnbr(cpy->nb);
			ft_putstr("\033[0m");
			if (cpy->next)
				ft_putstr(", ");
			next = cpy->nb;
			cpy = cpy->next;
		}
		ft_putstr(" (end)\n");
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
