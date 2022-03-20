/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:45 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/20 20:44:06 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(t_mlx *mlx, t_map *plane)
{
	if (check_collec(plane->map) == 0)
	{
		change_prefix(plane->map);
		print_exit(mlx, plane->map, mlx->asset.run_o);
	}
	else
		print_exit(mlx, plane->map, mlx->asset.run);
	print_wall(mlx, plane->map, mlx->asset.wall);
	print_coll(mlx, plane->map, mlx->asset.coll);
	print_player(mlx, plane->map, mlx->asset.player);
	print_enemy(mlx, plane->map, mlx->asset.enemy);
}

void	print_s_player(t_mlx *mlx, int i, int j, t_player player)
{
	if (player.pos == 1)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			player.up.img, j * 60, i * 60);
	else if (player.pos == 0)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			player.down.img, j * 60, i * 60);
	else if (player.pos == 3)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			player.left.img, j * 60, i * 60);
	else if (player.pos == 2)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			player.right.img, j * 60, i * 60);
}

int	check_collec(char **map)
{
	int	i;
	int	j;
	int	index[255];

	i = 0;
	while (i < 255)
	{
		index[i] = 0;
		i++;
	}
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				index['C'] += 1;
			j++;
		}
		i++;
	}
	if (index['C'] > 0)
		return (1);
	return (0);
}
