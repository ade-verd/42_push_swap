/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:32:52 by ade-verd          #+#    #+#             */
/*   Updated: 2018/05/04 18:32:33 by ade-verd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sdlquit(t_heaps **ab, t_env *env, int *loop)
{
	*loop = 0;
	env->delay = 0;
	env->sens = 1;
	env->end = 1;
}

void	ft_sdlkeynum(t_heaps **ab, t_env *env, int *loop, int sdlk)
{
	uintmax_t	num;
	int			target_index;
	int			min_mv;
	int			max_mv;

	num = (sdlk - SDLK_0) * 10;
	min_mv = 1;
	max_mv = env->moves;
	if (sdlk == SDLK_HOME)
		target_index = min_mv;
	else if (sdlk == SDLK_END)
		target_index = max_mv;
	else
		target_index = min_mv + (num * (max_mv - min_mv) / 100);
	ft_printf("sdlk:%d\n", sdlk);
	ft_printf("num:%d\n", num);
	ft_printf("target:%d\n", target_index);
	ft_goto_buffindex(ab, target_index, 1);
	env->sens = target_index > (*ab)->buff->index ? 1 : -1;
	*loop = 0;
}

void	ft_sdlkeydown(t_heaps **ab, t_env *env, int *loop)
{
	int		sdlk;

	sdlk = env->event.key.keysym.sym;
	if (sdlk == SDLK_PAGEUP)
		env->delay = env->delay > 2 ? env->delay / 2 : env->delay;
	if (sdlk == SDLK_PAGEDOWN)
		env->delay = env->delay < 256 ? env->delay * 2 : env->delay;
	if (sdlk == SDLK_UP && (*ab)->buff->index < env->moves)
	{
		env->sens = 1;
		*loop = 0;
	}
	if (sdlk == SDLK_DOWN && (*ab)->buff->index > 1)
	{
		env->sens = -1;
		*loop = 0;
	}
	if ((sdlk >= SDLK_0 && sdlk <= SDLK_9)
			|| sdlk == SDLK_HOME || sdlk == SDLK_END)
		ft_sdlkeynum(ab, env, loop, sdlk);
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
			ft_sdlquit(ab, env, &loop);
		else if (env->event.type == SDL_KEYDOWN)
			ft_sdlkeydown(ab, env, &loop);
	}
}
