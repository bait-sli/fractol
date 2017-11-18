/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 04:02:48 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:05:25 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fractal_identity(t_env *env)
{
	char	*collection[12];

	collection[0] = "Mandelbrot";
	collection[1] = "Julia";
	collection[2] = "Burningship";
	collection[3] = "Multivers";
	collection[4] = "Mandelfish";
	collection[5] = "Alchemy";
	collection[6] = "Love";
	collection[7] = "Distortion";
	collection[8] = "UFO";
	collection[9] = "Biology";
	collection[10] = "Budda";
	collection[11] = "Logarithm";
	env->format = collection[env->action.fract_id - 1];
	if (env->action.fract_id % 2 == 0)
		env->action.fract_is_interactive = 1;
	else
		env->action.fract_is_interactive = 0;
}

void		ft_errors(char *format)
{
	ft_putendl(format);
	exit(EXIT_FAILURE);
}

int			ft_check_pos(int x, int y)
{
	if ((x > WIDTH || x <= 0 || y > HEIGHT || y <= 0))
		return (0);
	else
		return (1);
}

void		ft_put_pixel(t_env *s, int c, int x, int y)
{
	s->img.data[y][x] = c;
}
