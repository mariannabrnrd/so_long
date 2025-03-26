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
