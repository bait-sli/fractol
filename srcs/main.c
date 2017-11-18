/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 04:05:41 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:10:30 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_parse_assets(t_env *env)
{
	int			w;
	int			h;

	if (!(env->pattern = mlx_xpm_file_to_image(env->mlx, WHITE_PATH, &w, &h)))
		ft_errors(PATH_ERROR);
	if (!(env->frame = mlx_xpm_file_to_image(env->mlx, FRAME_PATH, &w, &h)))
		ft_errors(PATH_ERROR);
	if (!(env->dark = mlx_xpm_file_to_image(env->mlx, DARK_PATH, &w, &h)))
		ft_errors(PATH_ERROR);
}

static void		init_params(t_env *env, int format)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, NAME);
	env->img.img_ptr = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img.data = (int (*)[])mlx_get_data_addr(env->img.img_ptr,\
					&(env->img.bpp), &(env->img.sizeline), &(env->img.endian));
	env->action.fract_id = format;
	ft_init_params(env);
	ft_parse_assets(env);
	env->action.theme = 0;
}

int				main(int ac, char **av)
{
	t_env		env;

	if (ac != 2)
		ft_errors(ARGS_NBR_ERRORS);
	if (ft_strcmp(av[1], "1") != 0 && ft_strcmp(av[1], "2")\
			!= 0 && ft_strcmp(av[1], "3") != 0)
		ft_errors(WRONG_ARG);
	init_params(&env, ft_atoi(av[1]));
	ft_rending_controler(&env);
	mlx_hook(env.win, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion, &env);
	mlx_mouse_hook(env.win, ft_mouse, &env);
	mlx_hook(env.win, KEY_PRESS, KEY_PRESS_MASK, ft_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
