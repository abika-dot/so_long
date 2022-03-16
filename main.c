/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:48 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 21:45:01 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int ac, char **av)
{
	t_mlx	tot;

	if (ac == 2)
	{
		tot.map = get_plane(av[1]);
		if (tot.map == NULL)
			return (0);
		tot.mlx_ptr = mlx_init();
		tot.mlx_win = mlx_new_window(tot.mlx_ptr, tot.map->width * 60,
				tot.map->height * 60, "so long");
		mlx_string_put(tot.mlx_ptr, tot.mlx_win, 50 * tot.map->width / 2,
			60 * tot.map->height / 2, 0xFFF, "press ay key to start");
		tot.asset = get_xpms(tot);
		mlx_hook(tot.mlx_win, 2, 1L << 0, listner, &tot);
		mlx_hook(tot.mlx_win, 17, 1L << 0, destroy, &tot);
		mlx_loop(tot.mlx_ptr);
	}
	else
		ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
}
