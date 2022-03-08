/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:03:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/08 23:26:57 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int main (int ac, char	**av)
{
    t_map  *map;

    if(ac == 2)
    {
        map = check_map(av[1]);
        if (!map)
            return (0);

    }   
    else
        ft_putstr_fd("Usage: ./so_long map.ber\n"1); 
}
