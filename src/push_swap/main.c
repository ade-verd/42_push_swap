/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:28:18 by ade-verd          #+#    #+#             */
/*   Updated: 2018/02/28 17:01:14 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] && !ft_strchr("0123456789+-", str[i])) 
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);

}

/*void	ft_error(t_stack **stack)
{
	void	 	*copy;

	ft_putstr("Error\n");
	while(*stack)
	{
		copy = *stack;
		ft_memdel(());
	}
	exit (0);

}*/

int 	ft_read_and_fillstack(int ac, char **av, t_stack **stack)
{
	while (ac > 1)
	{
		ac--;
		if (ft_isnumber(av[ac]))
			ft_stackpush(stack, ft_atoi(av[ac]));
		else
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack		*stack;

	stack = NULL;
	if (ac > 1)
	{
		if (!(ft_read_and_fillstack(ac, av, &stack)))
			return (0);
		ft_stackdisplay(&stack);
		ft_stackpush(&stack, 100000);
		ft_stackdisplay(&stack);
		ft_stackpop(&stack);
		ft_stackdisplay(&stack);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
