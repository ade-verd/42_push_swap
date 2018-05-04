/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:39:09 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/04 15:03:34 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deal_options_init(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 0);
	if ((*ab)->option_v == 1 && !(*ab)->winenv)
		ft_viewer_init(ab, &(*ab)->winenv);
}

void	ft_deal_options_vs(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 1);
	if ((*ab)->option_v == 1 && (*ab)->winenv && (*ab)->winenv->end != 1)
		ft_viewer_draw(ab);
}

void	ft_deal_options_quit(t_heaps **ab)
{
	if ((*ab)->option_v == 1 && (*ab)->winenv)
		ft_viewer_destroy_quit(&(*ab)->winenv);
}