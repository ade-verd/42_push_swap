/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:32:52 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/09 14:26:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sdlquit(t_env *env, int *loop)
{
	*loop = 0;
	env->delay = 0;
	env->sens = 1;
	env->end = 1;
}

void	ft_sdlkeydown(t_heaps **ab, t_env *env, int *loop)
{
	int		sdlk;

	sdlk = env->event.key.keysym.sym;
	if (sdlk == SDLK_PAGEUP)
		env->delay = env->delay > 2 ? env->delay / 2 : env->delay;
	else if (sdlk == SDLK_PAGEDOWN)
		env->delay = env->delay < 256 ? env->delay * 2 : env->delay;
	else if (sdlk == SDLK_UP && (*ab)->buff->index < env->moves)
	{
		env->sens = 1;
		*loop = 0;
	}
	else if (sdlk == SDLK_DOWN && (*ab)->buff->index > 1)
	{
		env->sens = -1;
		*loop = 0;
	}
}

void	ft_manage_events(t_heaps **ab, t_env *env)
{
	int		loop;

	loop = 1;
	while (loop)
	{
		SDL_PollEvent(&env->event);
		if (env->event.type == SDL_QUIT
			|| env->event.key.keysym.sym == SDLK_ESCAPE)
			ft_sdlquit(env, &loop);
		else if (env->event.type == SDL_KEYDOWN)
			ft_sdlkeydown(ab, env, &loop);
	}
}
