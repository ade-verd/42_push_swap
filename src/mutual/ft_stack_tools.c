/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 13:46:27 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stackpush(t_stack **current_link, int new_nb)
{
	t_stack		*new_link;

	if (!(new_link = (t_stack*)malloc(sizeof(t_stack))) || !(*current_link))
		return (-1);
	new_link->nb = new_nb;
	new_link->previous = current_link;
	return (0);
}

int		ft_stackpop(t_stack **stack)
{
	int 	nb;

	if (!(*stack))
		return (-1);
	nb = (*stack)->nb;
	(*stack)->nb = (*stack)->previous->nb;
	(*stack)->previous = (*stack)->previous->previous;
	ft_memdel((void**)&(*stack)->previous);
	return (nb);
}

void	ft_stackdisplay(t_stack **stack)
{
	t_stack		*copy;

	if (*stack)
	{
		copy = *stack;
		while (copy)
		{
			ft_putnbr(copy->nb);
			ft_putchar('\n');
			copy = copy->previous;
		}
	}
	else
		ft_putstr("(null)\n");
}