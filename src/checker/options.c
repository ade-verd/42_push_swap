/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:39:09 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/26 15:26:22 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deal_options_init(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 0);
	if ((*ab)->option_v == 1)
		ft_viewer_init(ab, &(*ab)->winenv);
}

void	ft_deal_options(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 1);
	if ((*ab)->option_v == 1)
		ft_view(ab);
}

void	ft_deal_options_quit(t_heaps **ab)
{
	if ((*ab)->option_v == 1)
		ft_viewer_destroy_quit((*ab)->winenv);
}