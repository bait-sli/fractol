/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:30:15 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 04:43:04 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "global.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_calcul
{
	int			x;
	int			y;
	int			i;
	t_dec		lx;
	t_dec		ly;
	t_dec		c_r;
	t_dec		c_im;
	t_dec		tmp;
	int			color;
}				t_calcul;

typedef struct	s_image
{
	t_buffer	*img_ptr;
	int			(*data)[WIDTH];
	int			bpp;
	int			endian;
	int			sizeline;
}				t_image;

typedef struct	s_ux
{
	int			julia_lock;
	int			fract_id;
	int			fract_is_interactive;
	int			inner_rgb;
	int			theme;
}				t_ux;

typedef struct	s_env
{
	t_dec		startx;
	t_dec		starty;
	t_buffer	*mlx;
	t_buffer	*win;
	t_image		img;
	t_dec		zoom;
	int			iter;
	int			mouse_x;
	int			mouse_y;
	t_char		r;
	t_char		v;
	t_char		b;
	int			local_r;
	int			local_v;
	int			local_b;
	t_ux		action;
	t_dec		julia_x;
	t_dec		julia_y;
	char		*format;
	t_buffer	*pattern;
	t_buffer	*frame;
	t_buffer	*dark;
	int			ratio;
}				t_env;

typedef struct	s_thinfo
{
	t_env		*env;
	int			ratio;
	t_buffer	*ft_fract;
}				t_thinfo;

int				ft_motion();
int				ft_key(int key, t_env *env);
int				ft_mouse(int key, int x, int y, t_env *env);
void			ft_put_pixel(t_env *s, int c, int x, int y);
void			ft_errors(char *format);
void			ft_stationary_exec(t_thinfo *info);
void			ft_motional_exec(t_thinfo *info);
void			ft_init_params(t_env *env);
void			ft_rending_controler(t_env *env);
void			ft_info(t_env *env, int clr);
int				ft_set_color(t_char a, t_char r, t_char v, t_char b);
int				ft_out_pixel_color(int pixel, t_env *env);
int				ft_inner_pixel_color(t_env *env);
int				ft_check_pos(int x, int y);
void			ft_ux_events(int x, int y, t_env *env);
void			ft_fractal_identity(t_env *env);
void			ft_julia(t_calcul *f, t_env *env);
void			ft_multivers(t_calcul *f, t_env *env);
void			ft_spaceship(t_calcul *f, t_env *env);
void			ft_exponontial(t_calcul *f, t_env *env);
void			ft_biology(t_calcul *f, t_env *env);
void			ft_ring(t_calcul *f, t_env *env);
void			ft_mandelbrot(t_calcul *f);
void			ft_mandelfish(t_calcul *f);
void			ft_burningship(t_calcul *f);
void			ft_ufo(t_calcul *f);
void			ft_love(t_calcul *f);
void			ft_budda(t_calcul *f);

#endif
