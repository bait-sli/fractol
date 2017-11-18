/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 04:10:54 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 05:40:17 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_display_and_free(t_env *env, int x, int y, int fo)
{
	char		*tmp;
	int			clr;

	clr = (env->action.theme == 1) ? WHITE_MENU : MENU_COLOR;
	tmp = ft_itoa(fo);
	mlx_string_put(env->mlx, env->win, x, y, clr, tmp);
	free(tmp);
}

static void		ft_joint_thread(pthread_t thread[NB_THREADS])
{
	int			i;

	i = -1;
	while (++i < NB_THREADS)
		pthread_join(thread[i], NULL);
}

static void		ft_print_win(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	if (env->action.theme == 1)
		mlx_put_image_to_window(env->mlx, env->win, env->frame, 0, 0);
	ft_info(env, MENU_COLOR);
}

void			ft_info(t_env *env, int clr)
{
	if (env->action.theme == 1)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->pattern, 1200, 0);
		clr = WHITE_MENU;
	}
	if (env->action.theme == 0)
		mlx_put_image_to_window(env->mlx, env->win, env->dark, 1200, 0);
	mlx_string_put(env->mlx, env->win, 1420, 185, clr, AUTOR);
	ft_display_and_free(env, 1420, 235, env->mouse_x);
	ft_display_and_free(env, 1420, 285, env->mouse_y);
	ft_display_and_free(env, 1420, 335, env->iter);
	ft_display_and_free(env, 1420, 390, env->zoom);
	ft_display_and_free(env, 1615, 515, env->b);
	ft_display_and_free(env, 1615, 590, env->v);
	ft_display_and_free(env, 1615, 662, env->r);
	mlx_string_put(env->mlx, env->win, 1420, 440, clr, env->format);
	mlx_string_put(env->mlx, env->win, 1380, 1135, clr, env->format);
}

void			ft_rending_controler(t_env *env)
{
	pthread_t	th[NB_THREADS];
	t_thinfo	info[NB_THREADS];
	int			t;
	int			i;

	t = 0;
	env->ratio = 0;
	i = -1;
	while (++i < NB_THREADS)
	{
		if (env->action.fract_is_interactive == 1)
			info[i].ft_fract = ft_motional_exec;
		else if (env->action.fract_is_interactive == 0)
			info[i].ft_fract = ft_stationary_exec;
		info[i].env = env;
		info[i].ratio = i * P_RATIO;
		t = pthread_create(&th[i], NULL, (void *)info[i].ft_fract, &info[i]);
	}
	ft_joint_thread(th);
	ft_print_win(env);
}
