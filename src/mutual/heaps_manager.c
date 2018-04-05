/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heaps_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:54:35 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/05 16:53:59 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_buffer_init(t_heaps **ab)
{
	if (!((*ab)->buff = (t_buf*)malloc(sizeof(t_buf))))
		ft_error(ab, "malloc");
	(*ab)->buff->index = 0;
}

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
	(*ab)->cut = 0;
}

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

void	ft_heaps_display(t_heaps **ab, unsigned char c, int displaycontext)
{
	char s[2]; 

	if (displaycontext == 1)
	{
		printf("%s%sPress Enter to continue%s", F_BLINKING, F_BLACK, F_NO);
		fgets(s, sizeof s, stdin); 
		//sleep(1);
		ft_display_lastmove(ab);
	}
	if (c == 'a')
	{
		ft_stackdisplay(ab, &(*ab)->a, &(*ab)->b, c);
		ft_putstr("___\n");
	}
	else if (c == 'b')
	{
		ft_stackdisplay(ab, &(*ab)->b, &(*ab)->a, c);
		ft_putstr("___\n");
	}
	else
	{
		ft_stackdisplay(ab, &(*ab)->a, &(*ab)->b, 'a');
		ft_stackdisplay(ab, &(*ab)->b, &(*ab)->a, 'b');
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
			ft_stackpush(&dest, &dest->a, src->a->nb, 'a');
			src->a = src->a->prev;
		}
		if (src->a)
			ft_stackpush(&dest, &dest->a, src->a->nb, 'a');
		while (src && src->b && src->b->next)
			src->b = src->b->next;
		while (src->b && src->b->prev)
		{
			ft_stackpush(&dest, &dest->b, src->b->nb, 'b');
			src->b = src->b->prev;
		}
		if (src->b)
			ft_stackpush(&dest, &dest->b, src->a->nb, 'b');
		dest->a_pval = src->a_pval;
		dest->a_ppos = src->a_ppos;
		dest->b_pval = src->b_pval;
		dest->b_ppos = src->b_ppos;
		dest->min = src->min;
		dest->max = src->max;
	}
}
