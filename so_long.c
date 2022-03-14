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

int *rand_enemy_move(int *p, char   **map)
{
    int r;

    r = rand() % 10;
    printf("%d " , r %10);
    while (1)
    {
        if (r < 3 && map[p[0] + 1] [p[1]] == '0') //down
            {
                p[0] += 1;
                break ;
            }
        if (r >= 3 && r < 6 && map[p[0]][p[1] + 1] == '0')  //right 
            {
                p[1] += 1;
                break; 
            }
        if (r >= 6 && r < 8 && map[p[0]][p[1] - 1] == '0')  //left 
            {
                p[1] -= 1;
                break; 
            }
        if (r >= 8 && r < 10 && map[p[0] - 1][p[1]] == '0')  //up 
            {
                p[0] -= 1;
                break; 
            }
            r = rand() % 10;
    }
    return p;
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
            if (map[i][j] == 'D')
                {
                    mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, enemy.img, j * 60, i * 60);

                }
            j++;
        }
        i++;
    }    
}

void    print_map(t_mlx mlx,t_map *plane)
{
           t_img   player;
           t_img   coll;
           t_img   wall;
            t_img run;
            t_img enemy;


            wall = get_image(mlx, "asset/wall.xpm");
            player = get_image(mlx, "asset/player/p1.xpm");
           enemy = get_image(mlx, "asset/enemy/e2.xpm");
           coll = get_image(mlx, "asset/collec.xpm");
           run  = get_image(mlx, "asset/exit.xpm");
            printf("%p\n", enemy.img);
            print_wall(mlx, plane->map, wall);
         print_coll(mlx, plane->map, coll);
           print_exit(mlx, plane->map, run);
        print_enemy(mlx,plane->map, enemy);
        print_player(mlx, plane->map, player);
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
        tot.mlx_ptr = mlx_init();
        tot.mlx_win = mlx_new_window(tot.mlx_ptr, plane->width * 60 , plane->height * 60, "so_long"); 
        print_map(tot, plane);

        mlx_loop(tot.mlx_ptr);

    }
    else
        ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
}