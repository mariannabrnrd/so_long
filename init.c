/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:25:15 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/24 10:25:17 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*data initialization*/
void ft_init_game(t_game *game)
{
    game->position.x = 0;
    game->position.y = 0;
    game->position.move = 0;
    game->map.columns = 0;
    game->map.rows = 0;
    game->map.collects = 0;
    game->map.player = 0;
    game->map.exits = 0;
    game->map.walls = 0;
    game->map.floor = 0;
    game->map.fill = NULL;
    game->map.repo = NULL;
    game->level = 41;
    game->count = 0;
    game->finish_game = 0;
}

/*map initialization*/
/*rows and columns are inverted*/
void ft_init_map(t_game *game)
{
    char        *line;
    int         i;

    i = 0;
    line = get_next_line(game->fd);
    ft_check_file(line);
    while (line && !(line[0] == '\n'))
    {
        if (i >= MAP_ROWS)
            ft_error_map("map too high", game);
        if (game->map.repo == NULL)
            ft_map_calloc(game);
        ft_check_map(game, line, i);
        ft_strlcpy(game->map.repo[i], line, game->map.rows + 1);
        i++;
        game->map.columns = i;
        free(line);
        line = get_next_line(game->fd);
    }
    free(line);
    close(game->fd);
}

/*layer initialization*/
void    ft_init_layer(t_game *game)
{
    unsigned int    y;
    unsigned int    x;

    y = 0;
    while(game->map.repo[y])
    {
        x = 0;
        while(game->map.repo[y][x])
        {
            ft_struct_map(game->map.repo[y][x], game, y, x);
            ft_check_wall(y, x, game);
            x++;
        }
        y++;
    }
    ft_check_patt(game);
    ft_cpymap_tofill(game);
    ft_fill(game, 'X');
}

/*library mlx initialization*/
void    ft_init_mlx(t_game *game)
{
    game->process = mlx_init();
    if (!game->process)
        ft_error_map("failed to initialize MLX", game);
    ft_init_img(game);
    game->window = mlx_new_window(game->process, game->map.columns * IMG_B, game->map.rows * IMG_H, "so_long");
    if (!game->window)
        ft_error_map("window not initialization", game);
}

/*img initialization*/
void    ft_init_img(t_game *game)
{
    ft_safe_load(game, &game->player, MIKU_U);
    ft_safe_load(game, &game->collectible, COLLECT);
    ft_safe_load(game, &game->exit_c, EXIT_CLOSE);
    ft_safe_load(game, &game->exit_o, EXIT_OPEN);
    ft_safe_load(game, &game->floor, FLOOR);
    ft_safe_load(game, &game->wall, WALL);
}
