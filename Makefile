# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:38:57 by seohyeki          #+#    #+#              #
#    Updated: 2024/02/14 14:30:59 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long
LIBFT = libft.a
LIBFT_DIR = libft
MLX_DIR = mlx/mlx_opengl
SRCS = 	so_long.c \
		so_long_utils.c \
		so_long_read_map.c \
		so_long_check_map.c \
		so_long_check_path.c \
		so_long_draw_map.c \
		so_long_press_key.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lz

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) ./
	cc -L$(MLX_DIR) $(CFLAGS) $(MLXFLAGS) $(LIBFT) -o $@ $^

%.o : %.c
	cc $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean :
	rm -f $(OBJS)
	make fclean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME) $(LIBFT)

re :
	make fclean
	make all

.PHONY : all clean fclean re