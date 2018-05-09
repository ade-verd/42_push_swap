/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:02:10 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 14:33:07 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include <SDL.h>

# define WINW				1024
# define WINH				1024
# define STATUS_BAR			0

# define COLOR_L			051, 101, 120, 255
# define COLOR_R			000, 146, 162, 255
# define COLOR_STICK		181, 234, 255, 255

typedef struct	s_env
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Event		event;
	SDL_Rect		background_l;
	SDL_Rect		background_r;
	SDL_Rect		stick;
	int				min;
	int				max;
	int				moves;
	int				play;
	int				delay;
	int				sens;
	int				end;
}				t_env;

#endif
