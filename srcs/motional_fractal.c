/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motional_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 03:58:16 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:01:06 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_multivers(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = tan(2 * f->c_r * f->c_im) + env->julia_y;
	f->c_r = f->tmp;
}

void	ft_spaceship(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = cos(2 * f->c_r * f->c_im) + env->julia_y;
	f->c_r = f->tmp;
}

void	ft_exponontial(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = exp(2 * f->c_r * f->c_im) + env->julia_y;
	f->c_r = f->tmp;
}

void	ft_biology(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = sin(2 * f->c_r * f->c_im) + env->julia_y;
	f->c_r = f->tmp;
}

void	ft_ring(t_calcul *f, t_env *env)
{
	f->tmp = f->c_r * f->c_r - f->c_im * f->c_im + env->julia_x;
	f->c_im = log(2 * f->c_r * f->c_im) + env->julia_y;
	f->c_r = f->tmp;
}
