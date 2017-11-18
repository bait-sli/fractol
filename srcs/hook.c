/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:48:18 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 02:51:45 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_check_move(int key, t_env *env)
{
	if (key == LEFT)
		env->startx += 0.05 * env->zoom;
	if (key == RIGHT)
		env->startx -= 0.05 * env->zoom;
	if (key == UP)
		env->starty += 0.05 * env->zoom;
	if (key == DOWN)
		env->starty -= 0.05 * env->zoom;
}

int			ft_mouse(int key, int x, int y, t_env *env)
{
	t_dec	posx;
	t_dec	posy;
	t_dec	zoom;

	env->mouse_x = x;
	env->mouse_y = y;
	zoom = 1;
	if (key == ZOOM_IN)
		zoom = 0.85;
	else if (key == ZOOM_OUT)
		zoom = 1.8;
	else
		zoom = 1;
	posx = env->startx + (x) / (t_dec)WIDTH * env->zoom;
	posy = env->starty + (y) / (t_dec)HEIGHT * env->zoom;
	env->zoom *= zoom;
	env->startx = (env->startx - posx) * zoom + posx;
	env->starty = (env->starty - posy) * zoom + posy;
	if (key == UX_UI_KEY)
		ft_ux_events(x, y, env);
	ft_rending_controler(env);
	return (0);
}

int			ft_key(int key, t_env *env)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	if (key == LOCK_JULIA)
		env->action.julia_lock = 1;
	if (key == RESET)
		ft_init_params(env);
	if (key == ADD_ITERATIONS)
	{
		env->iter += 10;
		if (env->iter > MAX_ITER)
			env->iter = MAX_ITER;
	}
	if (key == REMOVE_ITERATIONS)
	{
		env->iter -= 10;
		if (env->iter < MIN_ITER)
			env->iter = MIN_ITER;
	}
	ft_check_move(key, env);
	ft_rending_controler(env);
	return (0);
}

int			ft_motion(int x, int y, t_env *env)
{
	env->mouse_x = x;
	env->mouse_y = y;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT &&\
		env->action.julia_lock == 0 && env->action.fract_is_interactive == 1)
	{
		env->julia_x = env->startx + x / (t_dec)WIDTH * env->zoom;
		env->julia_y = env->starty + y / (t_dec)HEIGHT * env->zoom;
		ft_rending_controler(env);
	}
	ft_info(env, MENU_COLOR);
	return (0);
}
