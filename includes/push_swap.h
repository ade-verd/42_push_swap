/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 17:17:01 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* A SUPPRIMER */
# include <stdlib.h>
# include "SDL.h"
# include "ft_printf.h"

# define INT_MINI -2147483648
# define INT_MAXI  2147483647

typedef struct	s_buf
{
	char			move[4];
	int				index;
	struct s_buf	*next;
	struct s_buf	*prev;
}				t_buf;

typedef struct	s_stack
{
	char			id;
	int				nb;
	int				index;
	int				sens;
	int				*min;
	int				*max;
	int				*ppos;
	int				*pval;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_heaps
{
	t_stack			*a;
	t_stack			*b;
	t_buf			*buff;
	int				count;
	int				min;
	int				max;
	int				a_min;
	int				a_max;
	int				b_min;
	int				b_max;
	int				a_pval;
	int				a_ppos;
	int				b_pval;
	int				b_ppos;
	int				option_v;
	int				option_l;
	int				option_c;
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
int				ft_stackpush(t_heaps **ab, t_stack **current, int nb, char id);
int				ft_stackpop(t_stack **stack);
void			ft_stackdisplay(t_stack **work, int c);
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
void			ft_pushw(t_heaps **ab, t_stack **work, int apply);
void			ft_swapw(t_heaps **ab, t_stack **work, int apply);
void			ft_rotatew(t_heaps **ab, t_stack **work, int apply);
void			ft_rrotatew(t_heaps **ab, t_stack **work, int apply);

typedef struct	s_fct
{
	char			move[4];
	void 			(*f)(t_heaps **ab, int apply);
} 				t_fct;

/*
** Errors
*/
void			ft_error(t_heaps **ab, char *precision);
void			ft_error_sdl(t_heaps **ab, char *precision, char *precision2);
int				none(void);

/*
** Sort
*/
void			ft_select_sorter(t_heaps **ab, t_stack **work, int n);
void			ft_sorter(t_heaps **ab, t_stack **a, t_stack **b);
//int				ft_place(t_heaps **ab, t_stack *wrk, int toplace_v, int targ_p);
int				ft_placetop(t_heaps **ab, t_stack **wrk, int toplace_v);
void			ft_placetopboth(t_heaps **ab, int b_val, int a_next);
void			ft_place2(t_heaps **ab, t_stack **wrk, int toplacev, int targp);
int				ft_find_bestmove(t_stack **w, t_stack **o);

/*
** Tools: count, find, issort, ...
*/
int				ft_issort(t_stack *stack);
int				ft_issortn(t_stack *stack, int n);
int				ft_countv(t_stack *stack, int val, char *sign);
int				ft_find_index(t_stack *stack, int nb);
int				ft_find_val(t_stack *stack, int index_tofind);
int				ft_find_next(t_stack *stack, int ref);
int				ft_find_prev(t_stack *stack, int ref);
void			ft_find_median(t_stack *stack, int *fst4, int *mdn, int *thd4);
void			ft_find_minmax(t_stack *stack, int *min, int *max, int n);

/*
** Viewer
*/
void			ft_viewer(t_heaps **ab);


#endif
