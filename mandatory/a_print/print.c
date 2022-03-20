/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:57:41 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/20 20:47:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_coll(t_mlx *mlx, char **map, t_img coll)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					coll.img, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	print_player(t_mlx *mlx, char **map, t_img player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					player.img, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	print_wall(t_mlx *mlx, char **map, t_img wall)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					wall.img, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	print_exit(t_mlx *mlx, char **map, t_img run)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'Q')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
					run.img, j * 60, i * 60);
			j++;
		}
		i++;
	}
}
