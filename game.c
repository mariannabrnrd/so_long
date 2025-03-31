/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:50:42 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/31 10:50:45 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

/* using the functions from the mlx library */
void    ft_run_game(t_game *game)
{
    mlx_loop(game->process);
    mlx_key_hook(game->window, ft_handle_input, game);
    mlx_hook(game->window, 17, 0, ft_close_game, game);
}

/* function for key input */
int     ft_handle_input(int key, t_game *game)
{
    if (key == ESC)
        ft_close_game(game);
    else if (key == UP)
        ft_move_player(game, 0, -1);
    else if (key == DOWN)
        ft_move_player(game, 0, 1);
    else if (key == LEFT)
        ft_move_player(game, -1, 0);
    else if (key == RIGHT)
        ft_move_player(game, 1, 0);
    return (0);
}



