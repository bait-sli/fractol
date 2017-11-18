/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stationary_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 03:48:48 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 03:49:26 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_get_global_scale(t_calcul *f, t_env *env)
{
	f->c_r = env->startx + (f->x) / (t_dec)WIDTH * env->zoom;
	f->c_im = env->starty + (f->y) / (t_dec)HEIGHT * env->zoom;
	f->i = -1;
	f->lx = 0;
	f->ly = 0;
}

void			ft_mandelbrot(t_calcul *f)
{
	f->tmp = f->lx * f->lx - f->ly * f->ly + f->c_r;
	f->ly = 2 * f->lx * f->ly + f->c_im;
	f->lx = f->tmp;
}

static void		ft_define_fractal(t_calcul *f, t_env *env)
{
	if (env->action.fract_id == 1)
		ft_mandelbrot(f);
	if (env->action.fract_id == 3)
		ft_burningship(f);
	if (env->action.fract_id == 5)
		ft_mandelfish(f);
	if (env->action.fract_id == 7)
		ft_love(f);
	if (env->action.fract_id == 9)
		ft_ufo(f);
	if (env->action.fract_id == 11)
		ft_budda(f);
}

void			ft_stationary_exec(t_thinfo *fo)
{
	t_calcul	f;

	f.y = fo->ratio - 1;
	while (++f.y < (fo->ratio + P_RATIO))
	{
		f.x = -1;
		while (++f.x < HEIGHT)
		{
			ft_get_global_scale(&f, fo->env);
			while (f.lx * f.lx + f.ly * f.ly < 4 && ++f.i < fo->env->iter)
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
