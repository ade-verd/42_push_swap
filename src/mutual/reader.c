/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:38:06 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/11 10:55:06 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** int	ft_isnumber(char *str, int *nb)
** Checks if str is a number and an integer
*/

int		ft_isnumber(char *str, int *nb)
{
	int		i;

	i = 0;
	*nb = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atointmax(str) < INT_MINI || ft_atointmax(str) > INT_MAXI)
		return (0);
	*nb = ft_atoi(str);
	return (1);
}

/*
** int	ft_nb_exists(t_stack *a, int nb)
** Checks duplicates numbers
*/

int		ft_nb_exists(t_stack *a, int nb)
{
	t_stack	*cpy;

	if (a)
	{
		cpy = a;
		while (cpy)
		{
			if (cpy->nb == nb)
				return (1);
			cpy = cpy->next;
		}
	}
	return (0);
}

/*
** void	ft_ab_minmax(t_heaps **ab, int nb)
** Actualizes min and max values
*/

void	ft_ab_minmax(t_heaps **ab, int nb)
{
	if (*ab && !(*ab)->a)
	{
		(*ab)->min = nb;
		(*ab)->max = nb;
	}
	else if (*ab)
	{
		if (nb < (*ab)->min)
			(*ab)->min = nb;
		if (nb > (*ab)->max)
			(*ab)->max = nb;
	}
}

/*
** void	ft_check_n_push(t_heaps **ab, char *str)
** Checks arguments. Reads and pushe numbers on the stack. Reads options
*/

void	ft_check_n_push(t_heaps **ab, char *str)
{
	int		nb;
	int		isnum;

	isnum = 0;
	if (ft_isnumber(str, &nb))
	{
		isnum = 1;
		ft_nb_exists((*ab)->a, nb) == 1 ? ft_error(ab, 0) : none;
		ft_ab_minmax(ab, nb);
		ft_stackpush(ab, &(*ab)->a, nb, 'a');
	}
	if (str[0] == '-' && ft_strchr(str, 'l'))
		(*ab)->option_l = 1;
	if (str[0] == '-' && ft_strchr(str, 'v'))
		(*ab)->option_v = 1;
	if (str[0] == '-' && ft_strchr(str, 's'))
		(*ab)->option_s = 1;
	else if (str[0] == '-' && ft_strchr(str, 'c'))
		(*ab)->option_c = 1;
	if (str[0] == '-' && ft_strchr(str, 'f'))
		(*ab)->option_f = 1;
	ft_strstr(str, ".txt") ? (*ab)->path = str : (*ab)->path;
	if (!isnum && !(*ab)->option_l && !(*ab)->option_v && !(*ab)->option_s
		&& !(*ab)->option_c && !(*ab)->option_f && !(*ab)->path)
		ft_error(ab, 0);
}

/*
** void	ft_read_and_fillstack(int ac, char **av, t_heaps **ab, char **tab)
** Reads arguments and fill stack
*/

void	ft_read_and_fillstack(int ac, char **av, t_heaps **ab, char **tab)
{
	int		i;
	int		ischecker;

	if (!(*ab))
		ft_error(ab, "read_and_fillstack");
	ischecker = ft_strcmp(av[0], "checker") == 0 ? 1 : 0;
	while (ac > 1)
	{
		ac--;
		i = ft_countwords(av[ac], ' ');
		tab = ft_strsplit(av[ac], ' ');
		while (--i >= 0)
			ft_check_n_push(ab, tab[i]);
		ft_freetab_strsplit(tab);
	}
	if (!(*ab)->a)
		ft_error(ab, 0);
	(*ab)->a_min = (*ab)->min;
	(*ab)->a_max = (*ab)->max;
	(*ab)->count = (*ab)->a->index;
}
