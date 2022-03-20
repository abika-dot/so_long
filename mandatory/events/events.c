/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:37 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/20 20:48:30 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

int	check_reach(char **map)
{
	int	i;
	int	j;
	int	index[255];

	i = 0;
	fill(index);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				index['P'] += 1;
			if (map[i][j] == 'Q' || map[i][j] == 'E')
				index['Q'] += 1;
			j++;
		}
		i++;
	}
	if (index['P'] == 0)
		return (1);
	if (index['Q'] == 0)
		return (2);
	return (0);
}

void	check_game(char **map, t_mlx *mlx, int force)
{
	int	state;

	state = check_reach(map);
	if (force == 1)
		state = 3;
	else if (state == 0)
		return ;
	if (state > 0)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->asset.coll.img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->asset.player.img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->asset.run.img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->asset.run_o.img);
		mlx_destroy_image(mlx->mlx_ptr, mlx->asset.wall.img);
		d_free(map);
		free(mlx->map);
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		if (state == 1)
			ft_putstr_fd("LOL, Loser\n", 1);
		else if (state == 2)
			ft_putstr_fd("Congrat's, you Won!!\n", 1);
		exit(0);
	}
}

int	listner(int keycode, t_mlx *mlx)
{
	static int	i;
	char		*n;

	if (!i)
		i = 0;
	n = ft_itoa(i);
	write(1, n, ft_strlen(n));
	write(1, "\n", 1);
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	if (keycode == 1)
		move_up(mlx);
	else if (keycode == 13)
		move_down(mlx);
	else if (keycode == 0)
		move_left(mlx);
	else if (keycode == 2)
		move_right(mlx);
	else if (keycode == 53)
		check_game(mlx->map->map, mlx, 1);
	check_game(mlx->map->map, mlx, 0);
	print_map(mlx, mlx->map);
	free(n);
	i++;
	return (0);
}

int	destroy(t_mlx *mlx)
{
	check_game(mlx->map->map, mlx, 1);
	return (0);
}
