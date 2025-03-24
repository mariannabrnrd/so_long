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

#include "so_long_h"

/*checking the first arguments*/
void    ft_check_argument(int ac, char **av, t_game *game)
{
    int     len;
    if(ac != 2)
    {
        ft_error("wrong arguments");
    }
    len = ft_strlen(av[1]);
    if(ft_strnstr(&av[1][len - 5], "er", .b4) == NULL)
    {
        ft_error("invalid map file.");
    }
}

/*checking if file is empty*/
void    ft_check_file(char *line)
{
    int     len;

    if (line == NULL)
        ft_error("sorry, file is empty :(");
    len = ft_remove_n(line);
}

/*checking len of map*/
void    ft_check_map(t_game *game, char *line, int i_rows)
{
    int len;

    len = ft_remove_n(line);
    if (len >= MAP_COLS)
        ft_error_map("map filr too long", game);
    if (i_rows == 0)
        game->map.rows = len;
    else if (len != game->map.rows)
       ft_error_map("map rows must have the same length");
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
        
    }
}


