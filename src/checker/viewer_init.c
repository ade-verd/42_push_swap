/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:27:21 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/07 13:04:48 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_createwindow(t_heaps **ab, t_env **env)
{
	if (!*env)
		ft_error_sdl(ab, "ft_createwindow", "!env");
	(*env)->window = SDL_CreateWindow("ADV Viewer", SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED, WINW, WINH, SDL_WINDOW_SHOWN);
	if (!(*env)->window)
		ft_error_sdl(ab, "SDL_CreateWindow", (char*)SDL_GetError());
}

void	ft_createrenderer(t_heaps **ab, t_env **env)
{
	if (!*env)
		ft_error_sdl(ab, "ft_createrenderer", "!env");
	(*env)->render = SDL_CreateRenderer((*env)->window, -1,
						SDL_RENDERER_ACCELERATED);
	if (!(*env)->render)
		ft_error_sdl(ab, "SDL_CreateRenderer", (char*)SDL_GetError());
}

void	ft_init_backgrounds(t_heaps **ab, t_env *env)
{
	if (!env)
		ft_error_sdl(ab, "ft_init_backgrounds", "!env");
	env->background_l.x = 0;
	env->background_l.y = 0 + STATUS_BAR;
	env->background_l.h = WINH - STATUS_BAR;
	env->background_l.w = WINW / 2;
	env->background_r.x = WINW / 2;
	env->background_r.y = 0 + STATUS_BAR;
	env->background_r.h = WINH - STATUS_BAR;
	env->background_r.w = WINW / 2;
}

void	ft_viewer_init(t_heaps **ab, t_env **env)
{
	if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1))
		ft_error_sdl(ab, "SDL_Init", (char*)SDL_GetError());
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		ft_error_sdl(ab, "Malloc", "ft_initenv()");
	ft_createwindow(ab, env);
	ft_createrenderer(ab, env);
	ft_init_backgrounds(ab, *env);
	(*env)->moves = (*ab)->buff->index;
	(*env)->play = 0;
	(*env)->delay = 16;
	(*env)->sens = 1;
	(*env)->end = 0;
}