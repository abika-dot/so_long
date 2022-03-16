/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:04:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/16 22:00:03 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include <mlx.h>
# define BUFFER_SIZE 42

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_assets
{
	t_img	wall;
	t_img	player;
	t_img	enemy;
	t_img	coll;
	t_img	run;
	t_img	run_o;
	int		state;
}	t_assets;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		*map;
	t_assets	asset;
}	t_mlx;

void		print_map(t_mlx *mlx, t_map *plane);
void		print_coll(t_mlx *mlx, char **map, t_img coll);
void		print_player(t_mlx *mlx, char **map, t_img player);
void		print_wall(t_mlx *mlx, char **map, t_img wall);
void		print_exit(t_mlx *mlx, char **map, t_img run);
void		print_enemy(t_mlx *mlx, char **map, t_img enemy);
int			check_collec(char **map);
int			check_reach(char **map);
void		check_game(char **map, t_mlx *mlx, int force);
int			listner(int keycode, t_mlx *mlx);
int			destroy(t_mlx *mlx);
t_img		get_image(t_mlx mlx, char *file);
int			check_colectibles(t_map *plane);
t_assets	get_xpms(t_mlx mlx);
char		**d_free(char **str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(char *s, char c);
char		*ft_itoa(int n);
void		now_m(char **map, int i, int j);
int			switch_place(char **map, int i, int j);
void		move_up(t_mlx *mlx);
void		move_down(t_mlx *mlx);
void		move_left(t_mlx *mlx);
void		move_right(t_mlx *mlx);
void		change_prefix(char **map);
int			check_name(char	*map);
char		**read_map(int fd);
int			check_lenght(char	**map);
int			hit_and_run(char	*border);
int			check_border(char	**map);
t_map		*get_plane(char *file);
int			chara(char c);
int			should_exist(char **map);
char		**get_map(char *file);

#endif
