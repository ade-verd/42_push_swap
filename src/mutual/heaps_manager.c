/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 16:35:14 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** void	ft_buffer_init(t_heaps **ab)
** Initialize t_buf*
*/

void	ft_buffer_init(t_heaps **ab)
{
	if (!((*ab)->buff = (t_buf*)malloc(sizeof(t_buf))))
		ft_error(ab, "malloc");
	(*ab)->buff->index = 0;
}

/*
** void	ft_heaps_init(t_heaps **ab)
** Initialize t_heaps*
*/

void	ft_heaps_init(t_heaps **ab)
{
	if (!((*ab) = (t_heaps*)malloc(sizeof(t_heaps))))
		ft_error(ab, "malloc");
	ft_buffer_init(ab);
	(*ab)->a = NULL;
	(*ab)->b = NULL;
	(*ab)->a_pval = 0;
	(*ab)->a_ppos = 0;
	(*ab)->b_pval = 0;
	(*ab)->b_ppos = 0;
	(*ab)->a_min = 0;
	(*ab)->a_max = 0;
	(*ab)->b_min = 0;
	(*ab)->b_max = 0;
	(*ab)->option_l = 0;
	(*ab)->option_v = 0;
	(*ab)->option_c = 0;
	(*ab)->option_f = 0;
	(*ab)->fd = 0;
	(*ab)->path = NULL;
	(*ab)->winenv = NULL;
}

/*
** void	ft_heaps_del(t_heaps **ab)
** Frees everything properly
*/

void	ft_heaps_del(t_heaps **ab)
{
	if (*ab && (*ab)->a)
		ft_stackdel(&(*ab)->a);
	if (*ab && (*ab)->b)
		ft_stackdel(&(*ab)->b);
	ft_del_allmoves(ab);
	if (*ab && (*ab)->buff)
		ft_memdel((void**)&(*ab)->buff);
	if (*ab)
		ft_memdel((void**)ab);
}
