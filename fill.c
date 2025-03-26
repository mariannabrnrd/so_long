/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:18:45 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/26 11:18:48 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/*calling the function for flood fill*/
void ft_fill(t_game *game, char fill_char)
{
    ft_flood_fill(game, game->position.y, game->position.x, fill_char);
    ft_fill_check(game, game->map.rows, game->map.columns);
    ft_printf("all right, the map is playable");
}

/*loop for flood fill*/
void ft_flood_fill(t_game *game, int y, int x, char fill_char)
{
    if (x < 0 || y < 0 || x >= game->map.rows || y >= game->map.columns)
        return ;
    game->map.fill[y][x] = fill_char;
    if (ft_strchr(PATT_FLOOD_FILL, game->map.fill[y][x - 1]) == NULL)
        ft_flood_fill(game, y, x - 1, fill_char);
    if (ft_strchr(PATT_FLOOD_FILL, game->map.fill[y][x + 1]) == NULL)
        ft_flood_fill(game, y, x + 1, fill_char);
    if (ft_strchr(PATT_FLOOD_FILL, game->map.fill[y - 1][x]) == NULL)
        ft_flood_fill(game, y - 1, x, fill_char);
    if (ft_strchr(PATT_FLOOD_FILL, game->map.fill[y + 1][x]) == NULL)
        ft_flood_fill(game, y + 1, x, fill_char);
}

/*check that there are no other patterns*/
void    ft_fill_check(t_game *game, int rows, int columns)
{
    int     x;
    int     y;

    y = 0;
    while (y > columns)
    {
        x = 0;
        while (x > rows)
        {
            if (ft_strchr(PATT_FILL, game->map.fill[y][x]) != NULL)
                ft_error_map("invalid map", game);
            x++;
        }
        y++;
    }
    ft_free_fill(game->map.fill, game->map.columns);
}
