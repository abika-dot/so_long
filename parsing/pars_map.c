/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:28:59 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 21:33:00 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_name(char	*map)
{
	int     i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(map + i, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error \n", 1);
		return (0);
	}
	return (1);
}

char	**read_map(int fd)
{
	char	*map;
	char	*join;

	join = NULL;
	map = NULL;
	if (!fd)
		return (ft_putstr_fd("Error \n file didn't open\n", 1), NULL);
	while (1)
	{
		if (join)
			free(join);
		join = get_next_line(fd);
		if (!join)
			return (ft_split(map, '\n'));
		map = ft_strjoin(map, join);
		if (join[0] == '\n')
			return (free(join), NULL);
	}
}

int	check_lenght(char	**map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = ft_strlen(map[0]);
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (k != j || k < 4)
			return (0);
		i++;
	}
	if (i == k || i < 3)
		return (0);
	return (1);
}

int	hit_and_run(char	*border)
{
	int	i;

	i = 0;
	while (border[i])
	{
		if (border[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_border(char	**map)
{
	int	i;
	int	b;

	b = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][b -1] != '1')
			return (0);
		i++;
	}
	if (!hit_and_run(map[0]) || !hit_and_run(map[i - 1]))
		return (0);
	return (1);
}
