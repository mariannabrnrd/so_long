/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:00:24 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/20 14:00:27 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checking the first arguments*/
void    ft_check_argument(int ac, char **av)
{
    int     len;
    if(ac != 2)
    {
        ft_error("wrong arguments");
    }
    len = ft_strlen(av[1]);
    if(ft_strnstr(&av[1][len - 4], ".ber", 4) == NULL)
    {
        ft_error("invalid map file.");
    }
}

/*checking if file is empty*/
void    ft_check_file(char *line)
{
    if (line == NULL)
        ft_error("sorry, file is empty :(");
    ft_remove_n(line);
}

/*checking len of map*/
void    ft_check_map(t_game *game, char *line, int i_rows)
{
    int len;

    ft_remove_n(line);
    len = ft_strlen(line);
    if (len >= MAP_COLS)
        ft_error_map("map filr too long", game);
    if (i_rows == 0)
        game->map.rows = len;
    else if (len != game->map.rows)
       ft_error_map("map rows must have the same length", game);
}

/*checking if the walls enclose the map*/
void    ft_check_wall(int y, int x, t_game *game)
{
    if (game->map.repo == NULL || game->map.columns == 0)
        ft_error_map("error map", game);
    if (game->map.repo[0][x] != '1' || game->map.repo[y][0] != '1')
        ft_error_map("the walls do not enclose the map", game);
    if (game->map.columns - 1 >= 0)
    {
        if (game->map.repo[game->map.columns - 1][x] != '1')
            ft_error_map("the wall do not enclose the map", game);
    }
    if (game->map.rows - 1 >= 0)
    {
        if (game->map.repo[y][game->map.rows-1] != '1')
            ft_error_map("the wall do not enclose the map", game);
    }
}

/*pattern checking*/
void    ft_check_patt(t_game *game)
{
    if (!game->map.walls || game->map.walls < 12)
        ft_error_map("map does not have enough walls", game);
    if (game->map.collects < 1 || game->map.collects > 100)
        ft_error_map("collecitbles must be between 1 and 100", game);
    if (!game->map.player || game->map.player > 1)
        ft_error_map("map requires only one a player", game);
    if (!game->map.exits || game->map.exits > 1)
        ft_error_map("map requires only one a exits", game);
}


