/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:18:02 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/13 23:30:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *get_plane(char   *file)
{
    t_map *plane;
    int i;

    i = 0;
    plane = malloc(sizeof(t_map));
    if (!plane)
        return NULL;
    plane->map = get_map(file);
    if(!plane->map)
        return  NULL;
    plane->width = ft_strlen(plane->map[0]);
    while(plane->map[i])
        i++;
    plane->height = i;
    return (plane);
} 
t_img get_image(t_mlx mlx,char    *file)
{
    t_img instance;


    instance.img = mlx_xpm_file_to_image(mlx.mlx_ptr,file, &instance.width, &instance.height);
    return instance;
}
void    print_coll(t_mlx mlx, char **map, t_img coll)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                {
                     mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, coll.img, j *60, i*60);
                }
                j++;
        }
        i++;
    }    
}
void    print_ground(t_mlx mlx, char **map, t_img ground)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,ground.img, j *60, i*60);
            j++;
        }
        i++;
    }    
}
void    print_player(t_mlx mlx, char **map, t_img player)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, player.img, j * 60, i *60);
            j++;
        }
        i++;
    }    
}
void    print_enemy(t_mlx mlx, char **map, t_img enemy)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,enemy.img, j * 60, i * 60);
            j++;
        }
        i++;
    }    
}
void    print_wall(t_mlx mlx, char **map, t_img wall)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,wall.img, j * 60, i * 60);
            j++;
        }
        i++;
    }    
}
void    print_exit(t_mlx mlx, char **map, t_img run)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win,run.img, j * 60, i * 60);
            j++;
        }
        i++;
    }    
}
void    print_map(t_mlx mlx,t_map *plane)
{
            t_img   player;
            t_img   enemy;
            t_img   ground;
            t_img   coll;
            t_img   wall;
            t_img run;
            int i;
            int j;

            wall = get_image(mlx, "asset/wall.xpm");
            player = get_image(mlx, "asset/player/p1.xpm");
            enemy = get_image(mlx, "asset/enemy/e1.xpm");
            ground = get_image(mlx, "asset/ground.xpm");
            coll = get_image(mlx, "asset/collec.xpm");
            run  = get_image(mlx, "asset/exit.xpm");
            print_ground(mlx, plane->map, ground);
            print_wall(mlx, plane->map, wall);
          print_coll(mlx, plane->map, coll);
            print_exit(mlx, plane->map, run);
          print_player(mlx, plane->map, player);
          print_enemy(mlx, plane->map, enemy);
}
int main(int ac, char  **av)
{
    t_map    *plane;
    t_mlx   tot;
    t_img   coll;
    if (ac == 2)
    {
        plane = get_plane(av[1]);
        if (!plane)
            return (0);
        printf("height %d, width %d \n", plane->height, plane->width);
        tot.mlx_ptr = mlx_init();
        tot.mlx_win = mlx_new_window(tot.mlx_ptr, plane->width * 60 , plane->height * 60, "so_long"); 
        print_map(tot, plane);

        mlx_loop(tot.mlx_ptr);

    }
    else
        ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
}