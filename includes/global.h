/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 02:29:09 by bait-sli          #+#    #+#             */
/*   Updated: 2017/11/18 05:30:29 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# define NB_THREADS	8
# define P_RATIO 150
# define WIN_W 1688
# define WIN_H 1200
# define WIDTH 1200
# define HEIGHT 1200
# define MAX_ITER 2000
# define MIN_ITER 10
# define MENU_COLOR 0xD88600
# define WHITE_MENU 0x661A6B

# define UX_UI_KEY 1
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define ESC 53
# define RESET 15
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define LOCK_JULIA 37
# define ADD_ITERATIONS 69
# define REMOVE_ITERATIONS 78

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

# define NAME "fractol"
# define AUTOR "bait-sli"
# define WHITE_PATH "srcs/assets/white.xpm"
# define FRAME_PATH "srcs/assets/frame.xpm"
# define DARK_PATH "srcs/assets/black.xpm"
# define PATH_ERROR "USAGE: File or asset not found"
# define ARGS_NBR_ERRORS "USAGE: invalid number of args"
# define WRONG_ARG "USAGE: invalid arg\nMandelbrot: 1\nJulia: 2\nBurningship: 3"
# define MULTI_THREAD_ERROR "USAGE: Multithread errors, check system setting"

typedef double			t_dec;
typedef unsigned char	t_char;
typedef void			t_buffer;

#endif
