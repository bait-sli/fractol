/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 03:55:09 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 03:57:40 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_win_scale(t_env *env)
{
	int			tmp;

	tmp = env->action.fract_id;
	if (env->action.fract_is_interactive == 1)
	{
		env->startx = -2.2;
		env->starty = -2;
	}
	else if (tmp == 9 || tmp == 11)
	{
		env->startx = -2.29;
		env->starty = -1.58;
	}
	else if (tmp == 7)
	{
		env->startx = -2.08;
		env->starty = -0.74;
	}
	else
	{
		env->startx = -2.5;
		env->starty = -2;
	}
}

void			ft_init_params(t_env *env)
{
	env->mouse_x = 0;
	env->mouse_y = 0;
	env->r = 0;
	env->v = 0;
	env->b = 0;
	env->iter = 80;
	env->zoom = 4.2;
	env->julia_x = -0.7;
	env->julia_y = 0.27015;
	env->action.julia_lock = 0;
	env->action.inner_rgb = 0;
	env->local_r = 8;
	env->local_v = 2;
	env->local_b = 1;
	ft_fractal_identity(env);
	ft_init_win_scale(env);
}
