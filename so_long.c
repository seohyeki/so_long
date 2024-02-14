/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:36:50 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 14:58:44 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	t_game	game;
	
	if (argc == 2)
	{
		//map 읽고 유효한 map인지 확인하기
		if (!valid_file(argv[1]))
			print_error();
		read_map(argv[1], &game);
		if (!check_valid_map(&game) || !check_valid_path(game.map, &game))
			print_error();
		
		//창 만들고 맵 이미지 띄우기
		game.mlx_ptr = mlx_init();
		game.win_ptr = mlx_new_window(game.mlx_ptr, game.map_width * 64, game.map_height * 64, "so_long");
		game.move = 0; //움직인 횟수 초기화를 어디서 하는게 좋으려나
		set_img_ptr(&game);
		put_img_win(&game);
		
		//key입력받기
		mlx_hook(game.win_ptr, 2, 0, &press_key, &game);
		mlx_hook(game.win_ptr, 17, 0, &close_win, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}

