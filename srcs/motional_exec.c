/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motional_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:52:07 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 03:01:37 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_get_global_scale(t_calcul *f, t_env *env)
{
	f->c_r = env->startx + f->x / (t_dec)WIDTH * env->zoom;
	f->c_im = env->starty + f->y / (t_dec)HEIGHT * env->zoom;
	f->i = -1;
}

void			ft_julia(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = 2 * f->c_r * f->c_im + env->julia_y;
	f->c_r = f->tmp;
}

static void		ft_define_fractal(t_calcul *f, t_env *env)
{
	if (env->action.fract_id == 2)
		ft_julia(f, env);
	if (env->action.fract_id == 4)
		ft_multivers(f, env);
	if (env->action.fract_id == 6)
		ft_spaceship(f, env);
	if (env->action.fract_id == 8)
		ft_exponontial(f, env);
	if (env->action.fract_id == 10)
		ft_biology(f, env);
	if (env->action.fract_id == 12)
		ft_ring(f, env);
}

void			ft_motional_exec(t_thinfo *fo)
{
	t_calcul	f;

	f.y = fo->ratio - 1;
	while (++f.y < (fo->ratio + P_RATIO))
	{
		f.x = -1;
		while (++f.x < HEIGHT)
		{
			ft_get_global_scale(&f, fo->env);
			while (++f.i < fo->env->iter && f.c_r * f.c_r + f.c_im * f.c_im < 4)
				ft_define_fractal(&f, fo->env);
			if (f.i < fo->env->iter && ft_check_pos(f.x, f.y))
			{
				f.color = ft_out_pixel_color(f.i, fo->env);
				ft_put_pixel(fo->env, f.color, f.x, f.y);
			}
			else if (ft_check_pos(f.x, f.y))
			{
				f.color = ft_inner_pixel_color(fo->env);
				ft_put_pixel(fo->env, f.color, f.x, f.y);
			}
		}
	}
}
