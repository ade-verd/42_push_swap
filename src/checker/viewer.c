/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:36:28 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/25 17:00:09 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "viewer.h"

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
	env->background_l.y = 0;
	env->background_l.h = WINH;
	env->background_l.w = WINW / 2;
	env->background_r.x = WINW / 2;
	env->background_r.y = 0;
	env->background_r.h = WINH;
	env->background_r.w = WINW / 2;
}

void	ft_initenv(t_heaps **ab, t_env **env)
{
	if ((SDL_Init(SDL_INIT_VIDEO) == -1))
		ft_error_sdl(ab, "SDL_Init", (char*)SDL_GetError());
	if (!(*env = (t_env*)malloc(sizeof(t_env))))
		ft_error_sdl(ab, "Malloc", "ft_initenv()");
	ft_createwindow(ab, env);
	ft_createrenderer(ab, env);
	ft_init_backgrounds(ab, *env);
}

void	ft_destroy_and_quit(t_env *env)
{
	if (env && env->window)
	{
		SDL_DestroyWindow(env->window);
		env->window = NULL;
	}
	if (env && env->render)
	{
		SDL_DestroyRenderer(env->render);
		env->render = NULL;
	}
	if (env)
		ft_memdel((void**)&env);
	SDL_Quit();
}

void	ft_setuprenderer(t_env *env)
{
	SDL_SetRenderDrawColor(env->render, COLOR_BACKGROUND_L);
	SDL_RenderClear(env->render);

	SDL_SetRenderDrawColor(env->render, COLOR_BACKGROUND_R);
	SDL_RenderFillRect(env->render, &env->background_r);
	SDL_RenderPresent(env->render);
}

void	ft_render(t_env *env)
{
	SDL_RenderClear(env->render);
	SDL_RenderPresent(env->render);
}

void	ft_viewer(t_heaps **ab)
{
	t_env	*env;

	ft_initenv(ab, &env);


	ft_setuprenderer(env);
	//ft_render(env);
	SDL_Delay(10000);
	ft_destroy_and_quit(env);
}
