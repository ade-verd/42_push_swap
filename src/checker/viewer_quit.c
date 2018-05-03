/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:49:29 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/02 15:27:56 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_viewer_destroy_quit(t_env **env)
{
	if (*env && (*env)->window)
	{
		SDL_DestroyWindow((*env)->window);
		(*env)->window = NULL;
	}
	if (*env && (*env)->render)
	{
		SDL_DestroyRenderer((*env)->render);
		(*env)->render = NULL;
	}
	if (*env)
	{
		free((void*)*env);
		*env = NULL;
	}
	SDL_Quit();
}
