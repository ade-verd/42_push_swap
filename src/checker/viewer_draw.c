/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:36:28 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/04 14:24:45 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_setuprenderer(t_env *env)
{
	SDL_SetRenderDrawColor(env->render, COLOR_STATUS_BAR);
	SDL_RenderClear(env->render);
	SDL_SetRenderDrawColor(env->render, COLOR_L);
	SDL_RenderFillRect(env->render, &env->background_l);
	SDL_SetRenderDrawColor(env->render, COLOR_R);
	SDL_RenderFillRect(env->render, &env->background_r);
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
		env->stick.y -= env->stick.h;
		cpy = cpy->prev;
	}
}

void	ft_viewer_draw(t_heaps **ab)
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
	SDL_Delay(env->delay);
}
