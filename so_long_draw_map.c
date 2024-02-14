/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:56:36 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 14:24:06 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_img_ptr(t_game *game)
{
	int	wid;
	int	hei;

	game->move = 0;
	game->img_ptr_p = mlx_xpm_file_to_image(game->mlx_ptr, "./asset/p.xpm", &wid, &hei);
	game->img_ptr_t = mlx_xpm_file_to_image(game->mlx_ptr, "./asset/t.xpm", &wid, &hei);
	game->img_ptr_w = mlx_xpm_file_to_image(game->mlx_ptr, "./asset/w.xpm", &wid, &hei);
	game->img_ptr_e = mlx_xpm_file_to_image(game->mlx_ptr, "./asset/e.xpm", &wid, &hei);
	game->img_ptr_c = mlx_xpm_file_to_image(game->mlx_ptr, "./asset/c.xpm", &wid, &hei);
}

void	put_img_win(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr_t, x * 64, y * 64);
			if (game->map[x + (y * game->map_width)] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr_w, x * 64, y * 64);
			else if (game->map[x + (y * game->map_width)] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr_c, x * 64, y * 64);
			else if (game->map[x + (y * game->map_width)] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr_e, x * 64, y * 64);
			else if (game->map[x + (y * game->map_width)] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr_p, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
