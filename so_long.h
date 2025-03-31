/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:16 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/20 11:53:25 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*header*/
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"

/*mlx library*/
# include "mlx/mlx.h"
//# include "mlx/mlx_int.h"

/*library*/
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <math.h>
# include <X11/keysym.h>

/*game path*/
# define MIKU_U "./assets/miku.xpm"
# define COLLECT "./assets/collezionabile.xpm"
# define EXIT_CLOSE "./assets/exit_close.xpm"
# define EXIT_OPEN "./assets/exit_open.xpm"
# define FLOOR "./assets/prato.xpm"
# define WALL "./assets/nuvole.xpm"

/*define*/
# define MAP_B 3200
# define MAP_H 3200
# define IMG_B 32
# define IMG_H 32

# define MAP_ROWS (MAP_H / IMG_H)
# define MAP_COLS (MAP_B / IMG_B)

# define ESC    65307
# define UP     119   //W
# define DOWN   115   //S
# define LEFT   97    //A
# define RIGHT  100   //D

/*pattern*/
# define PATT_MAP           "01EPC"
# define PATT_FILL          "EPC"
# define PATT_FLOOD_FILL    "1X"
# define PATT_FLOOR         48 //ascii di 0
# define PATT_WALL          49 //ascii di 1
# define PATT_COLLECTS      67 //ascii di c
# define PATT_EXIT          69 //ascii di e
# define PATT_PLAYER        80 //ascii di p

/*struct*/
typedef struct s_game_img{
    void    *img;
    int     b;
    int     h;
} t_game_img;

typedef struct s_map{
    char        **repo;
    char        **fill;
    int                 columns;
    int                 rows;
    int                 collects;
    int                 player;
    int                 exits;
    int                 walls;
    int                 floor;
} t_map;

typedef struct s_position{
    int                 y;
    int                 x;
    unsigned int        move;
} t_position;

typedef struct s_game{
    t_map           map;
    t_position      position;
    t_game_img      player;
    t_game_img      floor;
    t_game_img      wall;
    t_game_img      exit_c;
    t_game_img      exit_o;
    t_game_img      collectible;
    void            *process;
    void            *window;
    int             fd;
    int             level;
    int             count;
    int             finish_game;
} t_game;

/*check function*/
void    ft_check_argument(int ac, char **av);
void    ft_check_file(char *line);
void    ft_check_map(t_game *game, char *line, int i_rows);
void    ft_check_wall(int y, int x, t_game *game);
void    ft_check_patt(t_game *game);

/*error function*/
void    ft_error(char *mess);
void    ft_error_map(char *mess, t_game *game);

/*free function*/
void    ft_free_repo(char **repo);
void    ft_free_fill(char **fill, int cols);

/*function for map*/
void ft_remove_n(char *line);
void ft_map_calloc(t_game *game);
void    ft_struct_map(char c, t_game *game, int y, int x);
void    ft_create_map(t_game *game);
void    ft_put_tile(t_game *game, char tile, int x, int y);

/*initialization*/
void ft_init_game(t_game *game);
void ft_init_map(t_game *game);
void    ft_init_layer(t_game *game);
void    ft_init_mlx(t_game *game);
void    ft_init_img(t_game *game);

/*fill function*/
void    ft_cpymap_tofill(t_game *game);
void ft_fill(t_game *game, char fill_char);
void ft_flood_fill(t_game *game, int y, int x, char fill_char);
void    ft_fill_check(t_game *game, int rows, int columns);

/*img function*/
void    ft_safe_load(t_game *game, t_game_img *img, char *path);
void    ft_destroy_images(t_game *game);

/*game function*/
void    ft_run_game(t_game *game);
int     ft_handle_input(int key, t_game *game);

#endif 
