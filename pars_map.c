/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:28:59 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/13 20:32:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_name(char	*map)
{
	int i;

	i = ft_strlen(map) - 4;
	if (ft_strncmp(map + i, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error \n", 1);
		return 0;
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
		join = get_next_line(fd);
		if (!join)
			return (ft_split(map, '\n'));
		map = ft_strjoin(map,join);
        if (join[0] == '\n')
            return (free(join), NULL);
	}
}
int check_lenght(char	**map)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = ft_strlen(map[0]);
	j = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
			j++;
		if (k != j || k < 4)
			return 0;
		i++;
	}
    if (i == k || i < 3)
     return 0;
	return(1);
}

int hit_and_run(char	*border)
{
	int i;

	i = 0;
	while (border[i])
	{
		if (border[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_border(char	**map)
{
	int i;
    int b;
    
    b = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1'||  map[i][b -1] != '1' )
			return (0);
		i++;
	}
	if (!hit_and_run(map[0]) || !hit_and_run(map[i - 1]))
		return (0);
	return 1;
}
int chara(char	c)
{
	if (c == '1' || c== '0' || c == 'E' || c== 'P' || c== 'C' || c == 'D')
		return 1;
	return 0;
}
int characters(int	*index)
{
	int i;

	i = 0;
	while (i < 255)
	{
		if (index[i] != 0)
		{
			if (chara(i) == 0)
				return 0;
		}
		i++;
	}
	if (index['P'] != 1 || index['C'] < 1 || index['E'] < 1  || index['D'] < 1)
		return (0);
	return (1);
}
int should_exist(char	**map)
{
	int	i;
	int	j;
	int index[255];

	i = 0;
    while(i < 255)
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
char	**get_map(char	*file)
{
	char	**map;

	if (check_name(file) == 0)
		return (ft_putstr_fd("name doesn't end with .ber\n", 1), NULL);
	map = read_map(open(file, O_RDONLY));
	if (!map)
		return (NULL);
	if(check_lenght(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix lenght\n", 1), NULL);
	if (check_border(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix the borders\n", 1), NULL);
	if ( should_exist(map) == 0)
		return (d_free(map), ft_putstr_fd("Error\nfix positions\n", 1), NULL);
    return (map);
}
