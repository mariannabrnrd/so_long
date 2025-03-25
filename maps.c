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

#include "so_long_h"

/*replace "\n" with "\0" throughout the string*/
int ft_remove_n(char *line)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            line[i] = '\0';
        i++;
    }
    return (i);
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
        game->map.exit++;
    if (c == PATT_PLAYER)
    {
        game->map.player++;
        game->position.y = y;
        game->position.x = x;
    }   
}

/*copy repo to fill*/
void    ft_cpymap_tofill(t_game *game)
{
    int     i;

    i = 0;
    if (game->map.fill == NULL)
    {
        game->map.fill = (char **)ft_calloc(game->map.columns + 1, sizeof(char *));
        if (!game->map.fill)
            ft_error_map("failed to fill map up", game);
        while (i < game->map.columns)
        {
            game->map.fill[i] = (char *)ft_calloc(game->map.rows + 1, sizeof(char));
            if (!game->map.fill[i])
                ft_error_map("failed to fill map up", game);
            ft_strlcpy(game->map.fill[i], game->map.repo[i], game->map.rows + 1);
            i++;
        }
        game->map.fill[i] = NULL;
    }
}


