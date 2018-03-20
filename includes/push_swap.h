/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/20 18:38:50 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* A SUPPRIMER */
# include <stdlib.h>
# include "ft_printf.h"

typedef struct	s_buf
{
	char 			move[4];
	int				index;
	struct s_buf	*next;
	struct s_buf	*prev;
}				t_buf;

typedef struct	s_stack
{
	char			id;
	int				nb;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_heaps
{
	t_stack			*a;
	t_stack			*b;
	t_buf			*buff;
	int 			count;
	int				min;
	int				max;
	int				a_pval;
	int				a_ppos;
	int				b_pval;
	int				b_ppos;
	int				option_v;
}				t_heaps;

/*
** Read and fill stack
*/
int				ft_read_and_fillstack(int ac, char **av, t_heaps **ab);

/*
** Heaps tools (A and B)
*/
void			ft_heaps_init(t_heaps **ab);
void			ft_heaps_del(t_heaps **ab);
void			ft_heaps_display(t_heaps **ab, unsigned char c, int context);
void			ft_heaps_cpy(t_heaps *dest, t_heaps *src);

/*
** Print moves in a buffer
*/
void			ft_moveappend(t_heaps **ab, char *s);
void			ft_display_lastmove(t_heaps **ab);
void			ft_displaymoves(t_heaps **ab, int display_number_moves);
void			ft_del_lastmove(t_heaps **ab);
void			ft_del_allmoves(t_heaps **ab);

/*
** Stack tools (A or B)
*/
int				ft_stackpush(t_stack **current_link, int new_nb, char id);
int				ft_stackpop(t_stack **stack);
void			ft_stackdisplay(t_stack **s, unsigned char c, int val, int pos);
int				ft_stacklen(t_stack *stack);
void			ft_stackdel(t_stack **stack);

/*
** Motions
*/
void			ft_swap_a(t_heaps **ab, int apply);
void			ft_swap_b(t_heaps **ab, int apply);
void			ft_swap_ab(t_heaps **ab, int apply);
void			ft_push_a(t_heaps **ab, int apply);
void			ft_push_b(t_heaps **ab, int apply);
void			ft_rotate_a(t_heaps **ab, int apply);
void			ft_rotate_b(t_heaps **ab, int apply);
void			ft_rotate_ab(t_heaps **ab, int apply);
void			ft_rrotate_a(t_heaps **ab, int apply);
void			ft_rrotate_b(t_heaps **ab, int apply);
void			ft_rrotate_ab(t_heaps **ab, int apply);
void			ft_reverse_motion(t_heaps **ab, char *move);

typedef struct	s_fct
{
	char		move[4];
	char		rmove[4];
	void		(*f)(t_heaps **ab, int apply);
}				t_fct;

/*
** Errors
*/
void			ft_error(t_heaps **ab, char *precision);

/*
** Sort
*/
void 			ft_sorter(t_heaps **ab, int pivot_pos);

/*
** Pivot
*/
//void			ft_interject_pivot(t_heaps **ab);
void			ft_interject_pivot(t_heaps **ab, t_stack *work);

/*
** Counter tools
*/
int				ft_count_val(t_stack *stack, int val, char *sign);
int				ft_count_bad(t_stack *stack, int pivot, int pos);
int				ft_find_index(t_stack *stack, int nb);

#endif
