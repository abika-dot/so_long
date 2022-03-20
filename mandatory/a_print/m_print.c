/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:05:45 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 20:13:18 by ozahir           ###   ########.fr       */
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
}
