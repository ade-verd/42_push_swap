/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:59:02 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 18:14:58 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Help push_swap and checker
*/

void	ft_help_ps(void)
{
	int		i;
	const t_help tab[] = {{ "Usage", "./push_swap [-h] $ARG [-f] [*.txt]" },
		{ "——————", "" },
		{ "-h", "[Help] displays this help" },
		{ "-f", "[File] writes movements to *.txt file (if specified)" },
		{ "", "If no output file is specified, the file will be output.txt" },
		{ 0, 0}};

	i = 0;
	while (tab[i].option)
	{
		ft_printf("%s\t%s\n", tab[i].option, tab[i].details);
		i++;
	}
}

void	ft_help_chk(void)
{
	int		i;
	const t_help tab[] = {{ "Usage", "./checker [-h] $ARG [-lscfv] [*.txt]" },
		{ "——————", "" },
		{ "-h", "[Help] displays this help" },
		{ "-l", "[Lines] displays the number of movements" },
		{ "-s", "[Steps] displays details of each stack" },
		{ "-c", "[Color] displays only last movement (desactivated with -s)" },
		{ "-f", "[File] reads movements from a *.txt file (specified in args)" },
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
}

void	ft_help(void)
{
	ft_help_ps();
	ft_putchar('\n');
	ft_help_chk();
	exit (0);
}