/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:02:10 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/25 16:54:28 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include <SDL.h>

# define WINW	800
# define WINH	600

# define COLOR_BACKGROUND_L	051, 101, 120, 255
# define COLOR_BACKGROUND_R	000, 146, 162, 255
# define COLOR_BAR			255, 255, 255, 255

typedef struct	s_env
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Rect		background_l;
	SDL_Rect		background_r;
	SDL_Rect		bar;
}				t_env;

void			ft_error_sdl(t_heaps **ab, char *precision, char *precision2);

#endif
