/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:12:10 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/11 19:35:08 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	surrounded_by_wall(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		if (j == 0 && game->map[i] != '1') //첫줄인데 1이 아님
			return (0);
		else if (j == (game->map_height - 1) && game->map[i] != '1') //마지막줄인데 1이 아님
			return (0);
		else if (i % game->map_width == 0 && game->map[i] != '1') //중간줄인데 줄의 첫번째가 1이 아님
			return (0);
		else if ((i % game->map_width) == (game->map_width - 1) && game->map[i] != '1') //중간줄인데 줄의 마지막이 1이 아님
			return (0);
		i++;
		if (i % game->map_width == 0)
			j++;
	}
	return (1);
}

static int	count_c_p_e(t_game *game)
{
	size_t	i;
	int		e_num;
	int		p_num;

	i = 0;
	e_num = 0;
	p_num = 0;
	game->c_cnt = 0;
	game->c_num = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
			game->c_num++;
		else if (game->map[i] == 'P')
			p_num++;
		else if (game->map[i] == 'E')
			e_num++;
		else if (game->map[i] != '0' && game->map[i] != '1')
			return (0);
		i++;
	}
	if (game->c_num < 1 || p_num != 1 || e_num != 1)
		return(0);
	return (1);
}

int	check_valid_map(t_game *game)
{
	if (game->map_width < 3 || game->map_height < 3) //적어도 width 3이상 && height 3이상이어야 함
		return (0);
	if (!surrounded_by_wall(game)) //벽으로 둘러쌓여있는지
		return (0);
	if (!count_c_p_e(game)) //수집품 1개이상, 출구 1개, 시작지점 1개, 01EPC아닌거 있는지
		return (0);
	return (1);
}
