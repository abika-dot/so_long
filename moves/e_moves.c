/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:55:27 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 20:48:51 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	now_m(char **map, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'D')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
	map[i][j] = 'D';
}

int	switch_place(char **map, int i, int j)
{
	int	r;
	int	state;

	state = 0;
	while (1)
	{
		r = rand() % 10;
		if (r >= 3 && r < 5 && (map[i][j + 1] == 'P' || map[i][j + 1] == '0'))
			return (now_m(map, i, j + 1), 0);
		if (r >= 5 && r < 8 && (map[i][j - 1] == 'P' || map[i][j - 1] == '0'))
			return (now_m(map, i, j - 1), 0);
		if (r >= 8 && r < 10 && (map[i - 1][j] == 'P' || map[i - 1][j] == '0'))
			return (now_m(map, i - 1, j), 0);
		if (r < 3 && (map[i + 1][j] == 'P' || map[i + 1][j] == '0'))
			return (now_m(map, i + 1, j), 0);
	}
	return (0);
}
