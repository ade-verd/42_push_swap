/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:40:30 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/19 13:56:17 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushw(t_heaps **ab, t_stack **work, int apply)
{
	(*work)->id == 'a' ? ft_push_b(ab, apply) : ft_push_a(ab, apply);
}

void	ft_swapw(t_heaps **ab, t_stack **work, int apply)
{
	(*work)->id == 'a' ? ft_swap_a(ab, apply) : ft_swap_b(ab, apply);
}

void	ft_rotatew(t_heaps **ab, t_stack **work, int apply)
{
	(*work)->id == 'a' ? ft_rotate_a(ab, apply) : ft_rotate_b(ab, apply);
}

void	ft_rrotatew(t_heaps **ab, t_stack **work, int apply)
{
	(*work)->id == 'a' ? ft_rrotate_a(ab, apply) : ft_rrotate_b(ab, apply);
}
