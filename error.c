/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:08:38 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/20 14:08:42 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_h"

void    ft_error(char *mess)
{
    ft_printf("%s\n", mess);
    exit(1);
}

void    ft_error_map(char *mess, t_game *game)
{
    int         i;
    char        **temp;

    i = 0;
    ft_free_map(game->map.repo);
    if (game->map.fill)
        ft_free_grid(game->map.grid, game->map.columns);
    ft_error(mess);
    exit(1);
}
