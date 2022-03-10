/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:10:23 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/10 20:20:05 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
    

int check_file(char *file)
{
    int len;

    if (!file)
        return (ft_putsr_fd("error !\n file variable is empty\n"), 0);
    len = ft_strlen(file) - 4;
    if (ft_strncmp(file + len, ".ber", 4)  == 0)
        return (1);
    ft_putstr_fd("error !\n file doesn't end with .ber \n", 1)
    return (0)        
}
t_list *file_dump(char   *file)
{  
    t_list *map;
    int     fd;

    fd  = open("file", O_RDONLY, 0667);
    if (!fd)
        return (ft_putstr_fd("error \n fd open error\n", 1), NULL);
    map = malloc(sizeof(t_list));
	if (!map)
		return NULL;
   temp = map;
   while(1)
	{
		map->text = get_next_line(fd);
		if (map->text == NULL)
			break ;
		map->next = malloc(sizeof(t_list));
		map = map->next;
		if (!map)
			return (free_list(temp), NULL);
	}
    map = NULL;
    return (temp)
}
char    **map_dump(t_list *dump)
{
    int j;
    int i;
    t_list *temp;
    char    **map;

    temp = dump;
    j = 0;
    i = ft_lstsize(dump);
    if (i <= 0)
        return (ft_putstr_fd("error \n list is empty\n", 1), NULL);
    map = malloc((i +1) * sizeof(char   *));
    if (!map)
        return (free_list(dump), NULL)
    while (j < i)
    {
        map[j] = ft_substr(dump->text, 0, ft_strlen(dump->text) - 1);
        dump = dump->next;
        if (!dump)
            break ;
    }
    return (map);
}
int check_len(char  **map)
{
    int i;
    int j;
    int k;

    i = 1;
    j = ft_strlen(map[0]);
    if (j < 3)
        retun (0);
    while(map[i])
    {
        k = ft_strlen(map[i]);
        if (k != j)
            return(0);
        i++;
    }
    if (i  == j)
        return 0;
    return (1);
}
int check_border(char   **map, int width, int height)
{
    int i;

    i = 0;
    while(map[i])
    {
        if (map[i][0] != '1'|| map[i][width] != '1')
            return (0);
            i++;
    }
    while(map[0][i] && map[height][i])
    {
        if (map[0][i] != '1' || map[height][i] != '1')
        return (0);
        i++;
    }
    return (1);
}

int check_pieces(char   **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (check_len(map) == 0)
        return (d_free(map), 0);
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (exist(map[i][j]) != 1)
                return 0;
            j++;
        }
        i++;
    }
    if (check_border(map, i , j))
        return (d_free(map), 0);
    return (1);
}

char    **check_map(char *file)
{
    char **map;
    t_list *dump;

    if (check_file(file) == 0)
        return (NULL);
    dump = file_dump(file);
    if (!dump)
        return (NULL);
    map = map_dump(dump);
    if (!map)
        return NULL;
    if (check_pieces(map) == 0)
        return (d_free(map), NULL)
    return (map);
}