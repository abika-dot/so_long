/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:18:02 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/20 20:23:01 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_img	get_image(t_mlx mlx, char *file)
{
	t_img	instance;

	instance.img = mlx_xpm_file_to_image(mlx.mlx_ptr, file,
			&instance.width, &instance.height);
	return (instance);
}

int	check_colectibles(t_map *plane)
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
	while (plane->map[i])
	{
		j = 0;
		while (plane->map[i][j])
		{
			if (plane->map[i][j] == 'C')
				index['C'] += 1;
			j++;
		}
		i++;
	}
	if (index['C'] > 0)
		return (1);
	return (0);
}

t_player	get_image_player(t_mlx mlx)
{
	t_player	imgs;

	imgs.up = get_image(mlx, "asset/player/up.xpm");
	imgs.down = get_image(mlx, "asset/player/down.xpm");
	imgs.right = get_image(mlx, "asset/player/right.xpm");
	imgs.left = get_image(mlx, "asset/player/left.xpm");
	imgs.pos = 0;
	return (imgs);
}

t_assets	get_xpms(t_mlx mlx)
{
	t_assets	imgs;

	imgs.run = get_image(mlx, "asset/exit.xpm");
	imgs.run_o = get_image(mlx, "asset/exit2.xpm");
	imgs.wall = get_image(mlx, "asset/wall.xpm");
	imgs.player = get_image_player(mlx);
	imgs.enemy = get_image(mlx, "asset/enemy/e3.xpm");
	imgs.coll = get_image(mlx, "asset/collec.xpm");
	return (imgs);
}

void	fill(int *index)
{
	int	i;

	i = 0;
	while (i < 255)
	{
		index[i] = 0;
		i++;
	}
}
