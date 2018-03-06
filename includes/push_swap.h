/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/03/06 13:24:22 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* A SUPPRIMER */
# include <stdlib.h>
# include "libft.h"

typedef struct	s_buff
{
	char 			move[4];
	struct s_buff	*next;
}				t_buff;

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*previous;

}				t_stack;

typedef struct	s_heaps
{
	t_stack			*a;
	t_stack			*b;
	int 			count_a;
	int 			count_b;

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
void			ft_heaps_display(t_heaps **ab, unsigned char c);

/*
** Stack tools (A or B)
*/
int				ft_stackpush(t_stack **current_link, int new_nb);
int				ft_stackpop(t_stack **stack);
void			ft_stackdisplay(t_stack **stack, unsigned char c);
int				ft_stacklen(t_stack *stack);
void			ft_stackdel(t_stack **stack);

/*
** Motions
*/
void			ft_swap_a(t_stack **stack);
void			ft_swap_b(t_stack **stack);
void			ft_swap_ab(t_heaps **ab);
void			ft_push_a(t_heaps **ab);
void			ft_push_b(t_heaps **ab);
void			ft_rotate_a(t_stack **stack);
void			ft_rotate_b(t_stack **stack);
void			ft_rotate_ab(t_heaps **ab);
void			ft_rrotate_a(t_stack **stack);
void			ft_rrotate_b(t_stack **stack);
void			ft_rrotate_ab(t_heaps **ab);

/*
** Errors
*/
void			ft_error(t_heaps **ab);

#endif
