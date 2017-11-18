/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 03:49:44 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 03:54:36 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_set_color(t_char a, t_char r, t_char v, t_char b)
{
	int		color;

	color = (a * 16711680) + (r * 65536) + (v * 256) + b;
	return (color);
}

static int	ft_random(int a, int b)
{
	int		tmp;
	int		ret;

	tmp = rand();
	ret = tmp % (b - a) + a;
	return (ret);
}

int			ft_out_pixel_color(int pixel, t_env *env)
{
	int		red;
	int		green;
	int		blue;
	int		color;

	red = (pixel * env->local_r) + env->r;
	green = (pixel * env->local_v) + env->v;
	blue = (pixel * env->local_b) + env->b;
	color = ft_set_color(0, red, green, blue);
	return (color);
}

int			ft_inner_pixel_color(t_env *env)
{
	int		red;
	int		green;
	int		blue;
	int		color;

	red = 0;
	green = 0;
	blue = 0;
	if (env->action.inner_rgb == 0)
		blue = ft_random(0, 255);
	if (env->action.inner_rgb == 1)
		green = ft_random(0, 255);
	if (env->action.inner_rgb == 2)
		red = ft_random(0, 255);
	color = ft_set_color(0, red, green, blue);
	return (color);
}
