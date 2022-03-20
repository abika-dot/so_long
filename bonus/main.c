/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:48 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/20 20:40:49 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	check_img(t_assets img)
{
	if (!img.coll.img || !img.enemy.img || !img.run.img)
		return (1);
	if (!img.run_o.img || !img.wall.img)
		return (2);
	if (!img.player.down.img || !img.player.left.img
		|| !img.player.right.img || !img.player.up.img)
		return (3);
	return (0);
}

void	check_total(t_mlx *mlx, t_assets img)
{
	if (check_img(img) != 0)
	{
		write(1, "Error \n images\n", 15);
		d_free(mlx->map->map);
		free(mlx->map);
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		exit(0);
	}
}

int	game_loop(t_mlx *tot)
{
	mlx_clear_window(tot->mlx_ptr, tot->mlx_win);
	print_map(tot, tot->map);
	check_game(tot->map->map, tot, 0);
	if (tot->n)
		mlx_string_put(tot->mlx_ptr, tot->mlx_win, 0, 0, 0xFF, tot->n);
	usleep(1000);
	return (0);
}

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
			60 * tot.map->height / 2, 0xFFF, "press any key to start");
		tot.asset = get_xpms(tot);
		check_total(&tot, tot.asset);
		mlx_hook(tot.mlx_win, 2, 0, listner, &tot);
		mlx_hook(tot.mlx_win, 17, 0, destroy, &tot);
		mlx_loop_hook(tot.mlx_ptr, game_loop, &tot);
		mlx_loop(tot.mlx_ptr);
	}
	else
		ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
}
