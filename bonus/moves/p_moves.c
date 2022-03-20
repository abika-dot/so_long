/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:52:51 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/21 00:04:38 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	move_up(t_mlx *mlx)
{
	int		i;
	int		j;
	char	**m;

	m = mlx->map->map;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'P'
					&& (m[i + 1][j] == '0'
						|| m[i + 1][j] == 'C' || m[i + 1][j] == 'Q'))
			{
				m[i][j] = '0';
				m[i + 1][j] = 'P';
				mlx->asset.player.pos = 0;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_down(t_mlx *mlx)
{
	int		i;
	int		j;
	char	**m;

	m = mlx->map->map;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'P'
					&& (m[i - 1][j] == '0'
						|| m[i - 1][j] == 'C' || m[i - 1][j] == 'Q'))
			{
				m[i][j] = '0';
				m[i - 1][j] = 'P';
				mlx->asset.player.pos = 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_left(t_mlx *mlx)
{
	int		i;
	int		j;
	char	**m;

	m = mlx->map->map;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'P'
					&& (m[i][j - 1] == '0'
						|| m[i][j - 1] == 'C' || m[i][j - 1] == 'Q'))
			{
				m[i][j] = '0';
				m[i][j - 1] = 'P';
				mlx->asset.player.pos = 3;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_right(t_mlx *mlx)
{
	int		i;
	int		j;
	char	**m;

	m = mlx->map->map;
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'P'
					&& (m[i][j + 1] == '0' || m[i][j + 1] == 'C'
						|| m[i][j + 1] == 'Q'))
			{
				m[i][j] = '0';
				m[i][j + 1] = 'P';
				mlx->asset.player.pos = 2;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	change_prefix(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				map[i][j] = 'Q';
				return ;
			}
			j++;
		}
		i++;
	}
}
