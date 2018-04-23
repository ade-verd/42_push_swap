/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:36:28 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/23 13:03:15 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pause()
{
	int continuer = 1;
	SDL_Event event;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}
}

void	ft_viewer(t_heaps **ab)
{
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
	{
		ft_putstr("SDL_Init() Error\n");
		ft_error(ab, SDL_GetError());
	}
	SDL_SetVideoMode(640, 480, 32, SDL__HWSURFACE);
	pause();
	SDL_Quit();
}