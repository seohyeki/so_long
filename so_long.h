/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:58:30 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 15:00:58 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr_p;
	void	*img_ptr_t;
	void	*img_ptr_w;
	void	*img_ptr_e;
	void	*img_ptr_c;
	char	*map;
	size_t 	map_width;
	size_t	map_height;
	int		move;
	int		c_cnt;
	int		c_num;
}	t_game;

int		valid_file(char *file_name);
void	print_error(void);
void	read_map(char *filename, t_game *game);
int		check_valid_map(t_game *game);
int 	check_valid_path(char *map_original, t_game *game);
void	set_img_ptr(t_game *game);
void	put_img_win(t_game *game);
int		press_key(int keycode, t_game *game);
int		close_win(t_game *game);

#endif