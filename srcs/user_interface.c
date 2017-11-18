/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 04:19:24 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:30:26 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_outside_colors(int x, int y, t_env *env)
{
	if (x >= 1480 && x <= 1530 && y >= 505 && y <= 550)
		env->b += 5;
	if (x >= 1480 && x <= 1530 && y >= 575 && y <= 620)
		env->v += 5;
	if (x >= 1480 && x <= 1530 && y >= 650 && y <= 695)
		env->r += 5;
	if (x >= 1420 && x <= 1470 && y >= 505 && y <= 550)
		env->b -= 5;
	if (x >= 1420 && x <= 1470 && y >= 575 && y <= 620)
		env->v -= 5;
	if (x >= 1420 && x <= 1470 && y >= 650 && y <= 695)
		env->r -= 5;
}

static void	check_move_and_theme(int x, int y, t_env *env)
{
	if (x >= 1220 && x <= 1265 && y >= 580 && y <= 620)
		env->startx += 0.05 * env->zoom;
	if (x >= 1350 && x <= 1400 && y >= 580 && y <= 620)
		env->startx -= 0.05 * env->zoom;
	if (x >= 1280 && x <= 1330 && y >= 510 && y <= 555)
		env->starty += 0.05 * env->zoom;
	if (x >= 1280 && x <= 1330 && y >= 640 && y <= 690)
		env->starty -= 0.05 * env->zoom;
	if (x >= 1365 && x <= 1385 && y >= 920 && y <= 960)
		env->action.julia_lock = 1;
	if (x >= 1485 && x <= 1515 && y >= 920 && y <= 960)
		env->action.julia_lock = 0;
	if (x >= 1225 && x <= 1280 && y >= 760 && y <= 820)
	{
		if (env->action.theme == 1)
			env->action.theme = 0;
		else
			env->action.theme = 1;
	}
}

static void	check_fractal_diapo(int x, int y, t_env *env)
{
	if (x >= 1525 && x <= 1595 && y >= 1115 && y <= 1185)
	{
		env->action.fract_id += 1;
		if (env->action.fract_id > 12)
			env->action.fract_id = 1;
		ft_init_params(env);
	}
	if (x >= 1295 && x <= 1360 && y >= 1115 && y <= 1185)
	{
		env->action.fract_id -= 1;
		if (env->action.fract_id < 1)
			env->action.fract_id = 12;
		ft_init_params(env);
	}
}

static void	check_inside_color(int x, int y, t_env *env)
{
	if (x >= 1320 && x <= 1400 && y >= 770 && y <= 850)
	{
		env->local_r = 2;
		env->local_v = 8;
		env->local_b = 1;
		env->action.inner_rgb = 2;
	}
	if (x >= 1405 && x <= 1480 && y >= 770 && y <= 850)
	{
		env->local_r = 1;
		env->local_v = 2;
		env->local_b = 8;
		env->action.inner_rgb = 1;
	}
	if (x >= 1485 && x <= 1555 && y >= 770 && y <= 850)
	{
		env->local_r = 8;
		env->local_v = 2;
		env->local_b = 1;
		env->action.inner_rgb = 0;
	}
}

void		ft_ux_events(int x, int y, t_env *env)
{
	check_outside_colors(x, y, env);
	check_move_and_theme(x, y, env);
	check_fractal_diapo(x, y, env);
	check_inside_color(x, y, env);
	if (x >= 1595 && x <= 1660 && y >= 730 && y <= 790)
		exit(0);
	if (x >= 1595 && x <= 1660 && y >= 815 && y <= 880)
		ft_init_params(env);
	if (x >= 1210 && x <= 1355 && y >= 920 && y <= 1090)
	{
		env->action.fract_id = 3;
		ft_init_params(env);
	}
	if (x >= 1360 && x <= 1525 && y >= 965 && y <= 1090)
	{
		env->action.fract_id = 2;
		ft_init_params(env);
	}
	if (x >= 1530 && x <= 1675 && y >= 920 && y <= 1090)
	{
		env->action.fract_id = 1;
		ft_init_params(env);
	}
}
