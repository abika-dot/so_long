/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:10:23 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/08 23:36:36 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void free_list(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while(!tmp)
	{
		free(data->text);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}

void  check_file(char   *file)
{
    char    *checker;

    checker = ft_strnstr(file, ".ber", 4);
    if (checker[3] == 0)
        return (1);
    ft_putstr_fd("the file doesn't end with '.ber' retry\n", 1);
    return 0;
}

t_data *check_map(char *file)
{
    t_data *map;
    t_data *tmp;

    i = 0;
    if (!check_file(file))
        return NULL;
    map = malloc(sizeof(t_data));
    if (!map)
        return NULL;
    temp = map;
    map->index = 0;
    while(1)
    {
		map->text = get_next_line(0);
        map->lenght = ft_strlen(map->text);
        map->index++;
		if (lines->text == NULL)
            break ;
		map->next = malloc(sizeof(t_data));
		lines = map->next;
		if (!lines)
			return (free_list(temp), NULL);
    }
    check_positions(temp);
    return (temp)
}