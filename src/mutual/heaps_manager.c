/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/19 19:15:46 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_buffer_init(t_heaps *ab)
{
	if (!(ab->buff = (t_buf*)malloc(sizeof(t_buf))))
		ft_error(ab, "malloc");
	ab->buff->index = 0;
}

void	ft_heaps_init(t_heaps **ab)
{
	if (!((*ab) = (t_heaps*)malloc(sizeof(t_heaps))))
		ft_error((*ab), "malloc");
	ft_buffer_init((*ab));
	(*ab)->a = NULL;
	(*ab)->b = NULL;
}

void	ft_heaps_del(t_heaps *ab)
{
	if (ab && ab->a)
		ft_stackdel(ab->a);
	if (ab && ab->b)
		ft_stackdel(ab->b);
	ft_del_allmoves(ab);
	if (ab && ab->buff)
		ft_memdel((void**)&ab->buff);
	if (ab)
		ft_memdel((void**)&ab);
}

void	ft_heaps_display(t_heaps *ab, unsigned char c)
{
	ft_display_lastmove(ab);
	if (c == 'a')
	{
		ft_stackdisplay(ab->a, c);
		ft_putstr("___\n");
	}
	else if (c == 'b')
	{
		ft_stackdisplay(ab->b, c);
		ft_putstr("___\n");
	}
	else
	{
		ft_stackdisplay(ab->a, 'a');
		ft_stackdisplay(ab->b, 'b');
		ft_putstr("___\n");
	}
}

void	ft_heaps_cpy(t_heaps *dest, t_heaps *src)
{
	if (src && dest)
	{
		while (src && src->a && src->a->next)
			src->a = src->a->next;
		while (src->a && src->a->prev)
		{
			ft_stackpush(dest->a, src->a->nb, 'a');
			src->a = src->a->prev;
		}
		if (src->a)
			ft_stackpush(dest->a, src->a->nb, 'a');
		while (src && src->b && src->b->next)
			src->b = src->b->next;
		while (src->b && src->b->prev)
		{
			ft_stackpush(dest->b, src->b->nb, 'b');
			src->b = src->b->prev;
		}
		if (src->b)
			ft_stackpush(dest->b, src->a->nb, 'b');
		dest->a->p_val = src->a->p_val;
		dest->a->p_pos = src->a->p_pos;
		dest->b->p_val = src->b->p_val;
		dest->b->p_pos = src->b->p_pos;
		dest->min = src->min;
		dest->max = src->max;
	}
}
