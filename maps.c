/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:26:28 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/24 10:26:32 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*replace "\n" with "\0" throughout the string*/
void ft_remove_n(char *line)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            line[i] = '\0';
        i++;
    }
}

/*creation the map using rows*/

void ft_map_calloc(t_game *game)
{
    if (!game->map.repo)
    {
        game->map.repo = (char **)ft_calloc(MAP_ROWS, sizeof(char *));
        if (!game->map.repo)
            ft_error("failed to allocate memory for map");
    }
}

/*pattern count*/
void    ft_struct_map(char c, t_game *game, int y, int x)
{
    if (ft_strchr(PATT_MAP, c) == NULL)
        ft_error_map("invalid character", game);
    if (c == PATT_FLOOR)
        game->map.floor++;
    if (c == PATT_WALL)
        game->map.walls++;
    if (c == PATT_COLLECTS)
        game->map.collects++;
    if (c == PATT_EXIT)
        game->map.exits++;
    if (c == PATT_PLAYER)
    {
        game->map.player++;
        game->position.y = y;
        game->position.x = x;
    }   
}

/* draw the map on the game window */
void    ft_create_map(t_game *game)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (y < game->map.columns)
    {
        x = 0;
        while (x < game->map.rows)
        {
            mlx_put_image_to_window(game->process, game->window, game->floor.img, x * IMG_B, y * IMG_H);
            ft_put_tile(game, game->map.repo[y][x], x, y);
            x++;
        }
        y++;
    }
}

/* adds tiles based on the character found */
void    ft_put_tile(t_game *game, char tile, int x, int y)
{
    if (tile == '1')
        mlx_put_image_to_window(game->process, game->window, game->wall.img, x * IMG_B, y * IMG_H);
    else if (tile == 'P')
        mlx_put_image_to_window(game->process, game->window, game->player.img, x * IMG_B, y * IMG_H);
    else if (tile == 'C')
        mlx_put_image_to_window(game->process, game->window, game->collectible.img, x * IMG_B, y * IMG_H);
    else if (tile == 'E')
    {
        if (game->map.collects == 0)
            mlx_put_image_to_window(game->process, game->window, game->exit_o.img, x * IMG_B, y * IMG_H);
        else
            mlx_put_image_to_window(game->process, game->window, game->exit_c.img, x * IMG_B, y * IMG_H);
    }
}