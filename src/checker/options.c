/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:39:09 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 15:28:16 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_help(void)
{
	int		i;
	const t_help tab[] = {{ "Usage", "./checker [-h] $ARG [-lscfv] [*.txt]" },
		{ "——————", "" },
		{ "-h", "[Help] displays this help" },
		{ "-l", "[Lines] displays the number of movements" },
		{ "-s", "[Steps] displays details of each stack" },
		{ "-c", "[Color] displays only last movement (desactivated with -s)" },
		{ "-f", "[File] read movements from a *.txt file (specified in args)" },
		{ "-v", "[Viewer] displays a graphical viewer" },
		{ "——————", "" },
		{ "Viewer", "[KEY_UP] Next move" },
		{ "Viewer", "[KEY_DOWN] Previous move" },
		{ "Viewer", "[PAGE_UP] Speed up" },
		{ "Viewer", "[PAGE_DOWN] Speed down" },
		{ "Viewer", "[ESC] Quit" },
		{ 0, 0}};

	i = 0;
	while (tab[i].option)
	{
		ft_printf("%s\t%s\n", tab[i].option, tab[i].details);
		i++;
	}
	exit (0);
}

void	ft_deal_options_init(t_heaps **ab)
{
	if ((*ab)->option_s == 1)
		ft_heaps_display(ab, 'a' + 'b', 0);
	if ((*ab)->option_v == 1 && !(*ab)->winenv)
	{
		if ((*ab)->count > WINH)
			ft_error_sdl(ab, "ft_deal_options_init",
				"Too much $ARGS (max 1024)");
		ft_viewer_init(ab, &(*ab)->winenv);
	}
}

void	ft_option_f_open(t_heaps **ab)
{
	if (!(*ab)->path)
		ft_error(ab, "-f: no [file].txt specified");
	if (((*ab)->fd = ft_open_fd((*ab)->path, O_RDONLY, S_IRUSR)) == -1)
		ft_error(ab, "ft_option_f_open");
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
	if ((*ab)->fd > 2 && ft_close_fd((*ab)->fd) == -1)
		ft_error(ab, "ft_option_f_close");
}
