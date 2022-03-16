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
void    print_coll(t_mlx *mlx, char **map, t_img coll)
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
                     mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, coll.img, j *60, i*60);
                }
                j++;
        }
        i++;
    }    
}

void    print_player(t_mlx *mlx, char **map, t_img player)
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
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, player.img, j * 60, i *60);
            j++;
        }
        i++;
    }    
}

void    print_wall(t_mlx *mlx, char **map, t_img wall)
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
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,wall.img, j * 60, i * 60);
            j++;
        }
        i++;
    }    
}
void    print_exit(t_mlx *mlx, char **map, t_img run)
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
            if (map[i][j] == 'E' || map[i][j] == 'Q')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,run.img, j * 60, i * 60);
            j++;
        }
        i++;
    }    
}


void now_m(char **map, int i, int j)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    while (map[y])
   {
   x = 0;
     while (map[y][x])
     {
        if (map[y][x] == 'D')
              map[y][x] = '0';
         x++;
       }
       y++;
   }
    map[i][j] = 'D';
}
int switch_place(char  **map, int i, int j)
{   
    int r;
    int state;

    state = 0;
    while (1)
    {
            r = rand() % 10;
        if (r >= 3 && r < 5 && ( map[i][j+ 1] == 'P' ||  map[i][j + 1] == '0'))  //right 
          return (now_m(map, i, j + 1), 0);
        if (r >= 5 && r < 8 && (map[i][j- 1] == 'P' ||  map[i][j - 1] == '0'))  //left 
         return (now_m(map, i , j-1), 0);
       if (r >= 8 && r < 10 && (map[i - 1][j] == 'P' || map[i - 1][j] == '0'))  //up 
       return (now_m(map, i - 1, j), 0);
        
       
          if (r < 3 && (map[i + 1] [j] == 'P' ||  map[i + 1][j] == '0') ) //down
         return (now_m(map, i + 1, j), 0);
        }
    return (0);
}
void    print_enemy(t_mlx *mlx, char **map, t_img enemy)
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
                   mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, enemy.img, j * 60, i * 60);
                   break ;
                }
            j++;
        }
        if (map[i][j] == 'D')
            break ;
        i++;
    }
    switch_place(map, i, j);
}
int check_colectibles(t_map *plane)
{
    int i;
    int j;
    int index[255];

    i = 0;
    while (i < 255)
    {
        index[i] = 0;
        i++;
    }
    i = 0;
    while(plane->map[i])
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
        return 1;
    return 0;
}
t_assets get_xpms(t_mlx mlx)
{       
    t_assets imgs;
    

    imgs.run  = get_image(mlx, "asset/exit.xpm");
    imgs.run_o  = get_image(mlx, "asset/exit2.xpm");

    imgs.wall = get_image(mlx, "asset/wall.xpm");
    imgs.player = get_image(mlx, "asset/player/p1.xpm");
    imgs.enemy = get_image(mlx, "asset/enemy/e2.xpm");
    imgs.coll = get_image(mlx, "asset/collec.xpm");
    return (imgs);
}
int check_collec(char   **map)
{
    int i;
    int j;
    int index[255];

    i = 0;
    while (i < 255)
    {
        index[i] = 0;
        i++;
    }
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                index['C'] += 1;
            j++;
        }
        i++;
    }
    if (index['C'] > 0)
        return 1;
    return 0;
}
void change_prefix(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
              {
                  map[i][j] = 'Q';
                  return ;
              }
            j++;
        }
        i++;
    }
}
void    print_map(t_mlx *mlx,t_map *plane)
{
  if (check_collec(plane->map) == 0)
     { 
        change_prefix(plane->map);
        print_exit(mlx, plane->map, mlx->asset.run_o);
     }
    else
            
                     print_exit(mlx, plane->map, mlx->asset.run);

    print_wall(mlx, plane->map, mlx->asset.wall);
    print_coll(mlx, plane->map, mlx->asset.coll);      
    print_player(mlx, plane->map, mlx->asset.player);
    print_enemy(mlx,plane->map, mlx->asset.enemy);
       
}
void move_up(t_mlx *mlx)
{
    int i;
    int j;
    char    **m;

    m = mlx->map->map;
    i = 0;
    while(m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] == 'P' && (m[i + 1][j] == '0' || m[i + 1][j] == 'C' || m[i + 1][j] == 'Q'))
            {
                m[i][j] = '0';
                m[i + 1][j] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_down(t_mlx *mlx)
{
    int i;
    int j;
    char    **m;

    m = mlx->map->map;
    i = 0;
    while(m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] == 'P' && (m[i - 1][j] == '0' || m[i - 1][j] == 'C' || m[i - 1][j] == 'Q'))
            {
                m[i][j] = '0';
                m[i - 1][j] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_left(t_mlx *mlx)
{
    int i;
    int j;
    char    **m;

    m = mlx->map->map;
    i = 0;
    while(m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] == 'P' &&( m[i][j - 1] == '0' || m[i][j - 1] == 'C' || m[i][j - 1] == 'Q'))
            {
                m[i][j] = '0';
                m[i ][j - 1] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}
void move_right(t_mlx *mlx)
{
    int i;
    int j;
    char    **m;

    m = mlx->map->map;
    i = 0;
    while(m[i])
    {
        j = 0;
        while (m[i][j])
        {
            if (m[i][j] == 'P' && (m[i][j + 1] == '0' || m[i][j + 1] == 'C'|| m[i][j + 1] == 'Q'))
            {
                m[i][j] = '0';
                m[i][j + 1] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}
int check_reach(char    **map)
{
    int i;
    int j;
    int index[255];

    i = 0;
    while (i < 255)
    {
        index[i] = 0;
        i++;
    }
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                index['P'] += 1;
            if (map[i][j] == 'Q' || map[i][j] == 'E')
                index['Q'] += 1;
            j++;
        }
        i++;
    }
    if (index['P'] == 0)
        return 1;
    if (index['Q'] == 0)
    return 2;
    return 0;
}
void check_game(char **map,t_mlx *mlx, int force)
{   
    int state;

    state = check_reach(map);
    if (force == 1)
        state = 3;
    else if (state == 0)
        return ;
    if (state  > 0)
    {
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.coll.img);
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.enemy.img);
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.player.img);
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.run.img);
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.run_o.img);
        // mlx_destroy_image(mlx->mlx_ptr, mlx->asset.wall.img);
        // d_free(map);
        // free(mlx->map);
        // mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
        // if (state == 1)
        //     printf("you lost\n");
        // else if (state == 2) 
        //     printf("you won\n");
        sleep(500);
        exit(0);
    }
}
static	char	*zerorule(char *s)
{
	int	i;

	s = malloc(2 * sizeof(char));
	if (!s)
	{
		return (NULL);
	}
	if (!s)
	{
		return (NULL);
	}	
	i = 0;
	s[i] = '0';
	s[i + 1] = 0;
	return (s);
}

static char	*nbr(char *s, long nbr, int i)
{
	int		a;
	int		b;
	long	c;

	a = i + 1;
	c = nbr;
	if (c < 0)
	{
		s[0] = '-';
		c *= -1;
	}
	while (c)
	{
		b = c % 10;
		c = c / 10;
		s[i] = b + 48;
		i--;
	}
	s[a] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*at;
	int		c;
	int		i;

	at = NULL;
	i = 0;
	c = n;
	if (c == 0)
		return (zerorule(at));
	while (c)
	{
		c = c / 10;
		i++;
	}
	if (n < 0)
	{
		i++;
	}
	at = malloc(i * sizeof(char) + 1);
	if (!at)
		return (NULL);
	at = nbr(at, (long)n, i - 1);
	return (at);
}
int listner(int keycode, t_mlx *mlx)
{   
    static int i;
    char *n;
    
    if (!i)
         i = 0;
    n = ft_itoa(i);
    
    mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
    if (keycode == 1) //up
        move_up(mlx);
    else if (keycode == 13) //down
        move_down(mlx);
    else if (keycode == 0 ) //left
        move_left(mlx);
    else if (keycode == 2) //right
        move_right(mlx);
    else if (keycode == 53) //quite
        check_game(mlx->map->map,mlx, 1);
    check_game(mlx->map->map,mlx, 0);

     print_map(mlx, mlx->map);
     mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 0, 0, 0xFF, n);
    free(n);
        i++;
        return 0;
}
int destroy(t_mlx *mlx)
{
    check_game(mlx->map->map,mlx, 1);
    return 0;
}
int main(int ac, char  **av)
{
    t_mlx   tot;
    if (ac == 2)
    {
        tot.map = get_plane(av[1]);
        if (!tot.map->map)
            return (0);
        tot.mlx_ptr = mlx_init();
        tot.mlx_win = mlx_new_window(tot.mlx_ptr, tot.map->width * 60 , tot.map->height * 60, "so long"); 
        mlx_string_put(tot.mlx_ptr, tot.mlx_win,50 * tot.map->width  /2, 60 *tot.map->height /2, 0xFFF, "press ay key to start");

        tot.asset =  get_xpms(tot);
        mlx_hook(tot.mlx_win,2 , 1L<<0, listner, &tot);
        mlx_hook(tot.mlx_win,17 , 1L<<0, destroy, &tot);

       mlx_loop(tot.mlx_ptr);

    }
    else
        ft_putstr_fd("Usage: ./so_long map.ber\n", 1);
}