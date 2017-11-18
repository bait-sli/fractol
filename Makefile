# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 02:27:27 by bait-sli          #+#    #+#              #
#    Updated: 2017/11/18 05:51:34 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = fractol
SRCS_NAME       = main.c\
                  colors.c\
                  global_function.c\
                  hook.c\
                  init_global_params.c\
                  motional_fractal.c\
                  motional_exec.c\
                  stationary_fractal.c\
                  stationary_exec.c\
                  multithread_render.c\
                  user_interface.c

SRCS_PATH       = srcs/
SRCS            = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME        = $(SRCS_NAME:.c=.o)
OBJ_PATH        = obj/
OBJ             = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS           = -Wall -Wextra -Werror -Ofast -march=native
INC             = -I./includes/ -I./libft/ -I./minilibx
LIB             = -L minilibx -lmlx -framework OpenGL -framework AppKit \
                  -L libft -lft\

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C minilibx/ clean
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
