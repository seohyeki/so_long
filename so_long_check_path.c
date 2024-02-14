/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:10:21 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 15:09:34 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs_collectible(int pos, char *map, int *cnt, t_game *game)
{
	if (map[pos] == '1' || map[pos] == 'E')
		return ;
	if (map[pos] != 'V')
	{
		if (map[pos] == 'C') //수집품일때
			(*cnt)++;
		map[pos] = 'V'; //빈공간일때
		dfs_collectible(pos - 1, map, cnt, game); //왼쪽
		dfs_collectible(pos + 1, map, cnt, game); //오른쪽
		dfs_collectible(pos - game->map_width, map, cnt, game); //위쪽
		dfs_collectible(pos + game->map_width, map, cnt, game); //아래쪽
	}
}

static void	dfs_exit(int pos, char *map, int *cnt, t_game *game)
{
	if (map[pos] == '1')
		return ;
	if (map[pos] != 'V')
	{
		if (map[pos] == 'E') //출구일때
			(*cnt)++;
		map[pos] = 'V'; //빈공간일때
		dfs_exit(pos - 1, map, cnt, game); //왼쪽
		dfs_exit(pos + 1, map, cnt, game); //오른쪽
		dfs_exit(pos - game->map_width, map, cnt, game); //위쪽
		dfs_exit(pos + game->map_width, map, cnt, game); //아래쪽
	}
} 

int check_valid_path(char *map_original, t_game *game)
{
	char	*map_c;
	char	*map_e;
	int		c_count;
	int		e_count;
	size_t	pos;
	
	pos = 0;
	c_count = 0;
	e_count = 0;
	while (map_original[pos] != 'P')
		pos++;
	map_c = ft_strdup(map_original);
	map_e = ft_strdup(map_original);
	dfs_collectible(pos, map_c, &c_count, game);
	dfs_exit(pos, map_e, &e_count, game);
	free(map_c);
	free(map_e);
	if (c_count != game->c_num || e_count != 1)
		return (0);
	return (1);
}
