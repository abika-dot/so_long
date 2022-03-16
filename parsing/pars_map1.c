/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:07:49 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 23:47:41 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*get_plane(char *file)
{
	t_map	*plane;
	int		i;

	i = 0;
	plane = malloc(sizeof(t_map));
	if (!plane)
		return (NULL);
	plane->map = get_map(file);
	if (!plane->map)
		return (NULL);
	plane->width = ft_strlen(plane->map[0]);
	while (plane->map[i])
		i++;
	plane->height = i;
	return (plane);
}

int	chara(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'D')
		return (1);
	return (0);
}

int	characters(int *index)
{
	int	i;

	i = 0;
	while (i < 255)
	{
		if (index[i] != 0)
		{
			if (chara(i) == 0)
				return (0);
		}
		i++;
	}
	if (index['P'] != 1 || index['C'] < 1 || index['E'] < 1 || index['D'] < 1)
		return (0);
	return (1);
}

int	should_exist(char **map)
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
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			index[(unsigned char) map[i][j]] += 1;
			j++;
		}
		i++;
	}
	return (characters(index));
}

char	**get_map(char *file)
{
	char	**map;

	if (check_name(file) == 0)
		return (ft_putstr_fd("name doesn't end with .ber\n", 1), NULL);
	map = read_map(open(file, O_RDONLY));
	if (!map)
		return (NULL);
	if (check_lenght(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix lenght\n", 1), NULL);
	if (check_border(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix the borders\n", 1), NULL);
	if (should_exist(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix positions\n", 1), NULL);
	return (map);
}
