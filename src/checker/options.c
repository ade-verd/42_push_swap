/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:39:09 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 16:12:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deal_options_init(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 0);
	if ((*ab)->option_v == 1 && !(*ab)->winenv)
	{
		if ((*ab)->count > WINH)
			ft_error_sdl(ab, "ft_deal_options_init",
				"Too much $ARGS for the viewer");
		ft_viewer_init(ab, &(*ab)->winenv);
	}
}

void	ft_deal_options_vsc(t_heaps **ab)
{
	char	*move;

	move = (*ab)->buff->move;
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 1);
	else if ((*ab)->option_c == 1)
	{
		ft_printf(" %s%s%s", F_YELLOW, (*ab)->buff->move, F_NO);
		ft_strlen(move) == 2 ? ft_putchar(' ') : none; 
		ft_putstr("\033[4D");
		if (!(*ab)->buff->prev)
			ft_putstr("    ");
		ft_putstr("\033[4D");
	}
	if ((*ab)->option_v == 1 && (*ab)->winenv && (*ab)->winenv->end != 1)
		ft_viewer_draw(ab);
}

void	ft_deal_options_quit(t_heaps **ab)
{
	if ((*ab)->option_v == 1 && (*ab)->winenv)
		ft_viewer_destroy_quit(&(*ab)->winenv);
}
