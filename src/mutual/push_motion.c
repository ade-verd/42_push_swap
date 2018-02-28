/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:48:51 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 18:08:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_swap_motion(t_stack **stack)
{
	if (ft_stacklen(*stack) > 1)
		ft_swap(&(*stack)->nb, &(*stack)->previous->nb);
}

void 	ft_2swap_motion(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(&(*stack_a)->nb, &(*stack_a)->previous->nb);
	ft_swap(&(*stack_b)->nb, &(*stack_b)->previous->nb);
}