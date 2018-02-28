/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:37:19 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 15:30:40 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* A SUPPRIMER */
# include <stdlib.h>
# include "libft.h"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*previous;

}				t_stack;

/*
** Stack tools
*/
int				ft_stackpush(t_stack **current_link, int new_nb);
int				ft_stackpop(t_stack **stack);
void			ft_stackdisplay(t_stack **stack);

#endif