/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 18:28:13 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_heaps(t_heaps **ab)
{
	if (!(*ab = (t_heaps*)malloc(sizeof(t_heaps))))
	{
		ft_putstr("Error\n");
		exit (0);
	}
	(*ab)->a = NULL;
	(*ab)->b = NULL;
}

int		ft_stackpush(t_stack **current_link, int new_nb)
{
	t_stack		*new_link;

	if (!(new_link = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	new_link->nb = new_nb;
	new_link->previous = *current_link;
	*current_link = new_link;
	return (0);
}

int		ft_stackpop(t_stack **stack)
{
	int 		nb;
	t_stack		*cpy;

	if (!(*stack))
		return (-1);
	cpy = *stack;
	nb = (*stack)->nb;
	*stack = (*stack)->previous;
	ft_memdel((void**)&cpy);
	return (nb);
}

void	ft_stackdisplay(t_stack **stack)
{
	t_stack		*cpy;

	if (*stack)
	{
		ft_putstr("Heap:\t(top) ");
		cpy = *stack;
		while (cpy)
		{
			ft_putnbr(cpy->nb);
			if (cpy->previous)
				ft_putstr(", ");
			cpy = cpy->previous;
		}
		ft_putstr(" (end)\n");
	}
	else
		ft_putstr("(null)\n");
}

int		ft_stacklen(t_stack *stack)
{
	int 		i;

	i = 0;
	while(stack)
	{
		stack = stack->previous;
		i++;
	}
	return (i);
}

void	ft_stackdel(t_stack **stack)
{
	t_stack	 	*cpy;

	while(*stack)
	{
		cpy = *stack;
		*stack = (*stack)->previous;
		ft_memdel((void**)&cpy);
	}
}
