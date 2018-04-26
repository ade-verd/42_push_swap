/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:36:28 by ade-verd          #+#    #+#             */
/*   Updated: 2018/04/26 18:50:46 by ade-verd         ###   ########.fr       */
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
	(*env)->play = 0;
}

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
	//(*ab)->option_v = 0;
	//(*ab)->winenv = NULL;
	SDL_Quit();
}

void	ft_setuprenderer(t_env *env)
{
	SDL_SetRenderDrawColor(env->render, COLOR_STATUS_BAR);
	SDL_RenderClear(env->render);

	SDL_SetRenderDrawColor(env->render, COLOR_L);
	SDL_RenderFillRect(env->render, &env->background_l);

	SDL_SetRenderDrawColor(env->render, COLOR_R);
	SDL_RenderFillRect(env->render, &env->background_r);
//	SDL_RenderPresent(env->render);
}

void	ft_draw_stick(t_stack *stack, t_env *env)
{
	env->stick.x = stack->id == 'a' ? 0 : WINW / 2;
	if ((env->stick.w = stack->nb * (WINW / 2) / (env->max - env->min)) == 0)
		env->stick.w = 0.2 * (WINW / 2) / (env->max - env->min);
	SDL_SetRenderDrawColor(env->render, COLOR_STICK);
	SDL_RenderFillRect(env->render, &env->stick);
}

void	ft_draw_stack(t_heaps *ab, t_stack *stack, t_env *env)
{
	t_stack	*cpy;

	if (!ab || !stack)
		return ;
	cpy = stack;
	env->min = ab->min;
	env->max = ab->max;
	env->stick.h = (WINH - STATUS_BAR) / ab->count;
	env->stick.y = WINH - env->stick.h;
	while (cpy && cpy->index > 1)
		cpy = cpy->next;
	while (cpy)
	{
		ft_draw_stick(cpy, env);
		/*ft_printf("id:%c\t", cpy->id);
		ft_printf("nb:%d\t", cpy->nb);
		ft_printf("x:%d\t", env->stick.x);
		ft_printf("y:%d\t", env->stick.y);
		ft_printf("h:%d\t", env->stick.h);
		ft_printf("w:%d\n", env->stick.w);*/
		env->stick.y -= env->stick.h;
		cpy = cpy->prev;
	}
}

void	ft_manage_events(t_heaps **ab, t_env *env)
{
	int		loop;

	loop = 1;
	while (loop)
	{
		env->play = 0 ? SDL_WaitEvent(&env->event) : SDL_PollEvent(&env->event);
		if (env->event.type == SDL_QUIT
			|| env->event.key.keysym.sym == SDLK_ESCAPE)
		{
			loop = 0;
			ft_viewer_destroy_quit(&(*ab)->winenv);
		}
	}
}

void	ft_view(t_heaps **ab)
{
	t_env	*env;

	if (!*ab || !(*ab)->winenv)
		ft_error_sdl(ab, "ft_viewer", "!ab->winenv");
	env = (*ab)->winenv;
	ft_setuprenderer(env);
	if ((*ab)->a)
		ft_draw_stack(*ab, (*ab)->a, env);
	if ((*ab)->b)
		ft_draw_stack(*ab, (*ab)->b, env);
	SDL_RenderPresent(env->render);
	ft_manage_events(ab, env);
	//SDL_Delay(16);
}
