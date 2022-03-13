/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:04:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/13 19:48:05 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "get_next_line.h"
#include <mlx.h>
#define BUFFER_SIZE 42

typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *mlx_win;
} t_mlx;

typedef struct s_img
{
    void    *img;
    int     width;
    int     height;
} t_img;

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
} t_map;

int check_name(char	*map);
char	**read_map(int fd);
int check_lenght(char	**map);
int hit_and_run(char	*border);
int check_border(char	**map);
int chara(char	c);
int characters(int	*index);
int should_exist(char	**map);
char	**get_map(char	*file);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split(char const *s, char c);
char    **d_free(char   **str);
#endif
