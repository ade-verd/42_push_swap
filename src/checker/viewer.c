/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:36:28 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/24 12:46:32 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void paupaupause()
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

void	ft_sdl_init(t_heaps **ab)
{
	if ((SDL_Init(SDL_INIT_VIDEO)) == -1)
		ft_error_sdl(ab, "SDL_Init", (char*)SDL_GetError());
}

void	ft_destroy_and_quit(SDL_Window *window)
{
	paupaupause();
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	ft_viewer(t_heaps **ab)
{
	SDL_Window	*window;
	SDL_Surface	*screen;
	SDL_Renderer *renderer;

	ft_sdl_init(ab);
	if (!(window = SDL_CreateWindow("ADV Viewer", SDL_WINDOWPOS_UNDEFINED, 
				SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN)))
		ft_error_sdl(ab, "SDL_CreateWindow", (char*)SDL_GetError());
	if (!(screen = SDL_CreateRGBSurface(0, 800, 600, 32, 0x00FF0000, 0x0000FF00,
								  0x000000FF, 0xFF000000)))
		ft_error_sdl(ab, "SDL_CreateRGBSurface", (char*)SDL_GetError());
	if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)))
		ft_error_sdl(ab, "SDL_CreateRenderer", (char*)SDL_GetError());
	ft_destroy_and_quit(window);
}