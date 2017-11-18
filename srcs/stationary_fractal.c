/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stationary_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 04:01:22 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:02:09 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burningship(t_calcul *f)
{
	f->tmp = f->lx * f->lx - f->ly * f->ly + f->c_r;
	f->ly = fabs(2 * f->lx * f->ly) + f->c_im;
	f->lx = f->tmp;
}

void	ft_ufo(t_calcul *f)
{
	f->tmp = cos(f->lx * f->lx - f->ly * f->ly) - f->c_im;
	f->ly = 2 * f->lx * f->ly - f->c_r;
	f->lx = f->tmp;
}

void	ft_budda(t_calcul *f)
{
	f->tmp = cos(f->lx * f->lx - f->ly * f->ly) - f->c_im;
	f->ly = sin(2 * f->lx * f->ly) - f->c_r;
	f->lx = f->tmp;
}

void	ft_love(t_calcul *f)
{
	f->tmp = exp(f->lx * f->lx - f->ly * f->ly) - f->c_im;
	f->ly = 2 * f->lx * f->ly - f->c_r;
	f->lx = f->tmp;
}

void	ft_mandelfish(t_calcul *f)
{
	f->tmp = fabs(f->lx * f->lx - f->ly * f->ly) + f->c_r;
	f->ly = 2 * f->lx * f->ly + f->c_im;
	f->lx = f->tmp;
}
