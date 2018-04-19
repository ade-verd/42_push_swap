/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 12:45:05 by ade-verd         ###   ########.fr       */
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
	new_link->index = !*current_link ? 1 : (*current_link)->index + 1;
	if (*current_link)
		(*current_link)->prev = new_link;
	new_link->id = id;
	new_link->sens = id == 'a' ? 1 : 0;
	new_link->ppos = id == 'a' ? &(*ab)->a_ppos : &(*ab)->b_ppos;
	new_link->pval = id == 'a' ? &(*ab)->a_pval : &(*ab)->b_pval;
	new_link->min = id == 'a' ? &(*ab)->a_min : &(*ab)->b_min;
	new_link->max = id == 'a' ? &(*ab)->a_max : &(*ab)->b_max;
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
