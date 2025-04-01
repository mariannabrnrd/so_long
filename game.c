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
    //ft_printf("inizio\n");
    
    mlx_key_hook(game->window, ft_handle_input, game);
    //ft_printf("input\n");
    mlx_hook(game->window, 17, 0, ft_close_game, game);
    //ft_printf("exit\n");
    
    mlx_loop(game->process);
    //ft_printf("process\n");

}

/* function for key input */
int     ft_handle_input(int key, t_game *game)
{
    if (key == ESC)
        ft_close_game(game);
    else if (key == UP)
        ft_move_player(game, -1, 0);
    else if (key == DOWN)
        ft_move_player(game, 1, 0);
    else if (key == LEFT)
        ft_move_player(game, 0, -1);
    else if (key == RIGHT)
        ft_move_player(game, 0, 1);
    return (0);
}

/*close the game*/
int     ft_close_game(t_game *game)
{
    if (game->window)
        mlx_destroy_window(game->process, game->window);
    if (game->process)
        mlx_destroy_display(game->process);
    free(game->process);
    ft_error_map("close game", game);
    ft_destroy_images(game);
    exit(0);
}

/*function for move the player*/
void    ft_move_player(t_game *game, int y, int x)
{
    int     new_y;
    int     new_x;

    new_y = game->position.y + y;
    new_x = game->position.x + x;
    if (game->map.repo[new_y][new_x] == '1')
        return;
    if (game->map.repo[new_y][new_x] == 'C')
    {
        game->map.collects--;
        game->map.repo[new_y][new_x] = '0';
    }
    if (game->map.repo[new_y][new_x] == 'E' && game->map.collects == 0)
        ft_win(game);
    if (game->map.repo[new_y][new_x] == 'E' && game->map.collects > 0)
        return;
    game->map.repo[game->position.y][game->position.x] = '0';
    game->map.repo[new_y][new_x] = 'P';
    game->position.y = new_y;
    game->position.x = new_x;
    game->position.move++;
    //ft_printf("mossa: %u\n", game->position.move);
    ft_create_map(game);
}

/*if u win*/
void    ft_win(t_game *game)
{
    ft_printf("Congratulation!! U WIN \n");
    ft_printf("mosse totali: %u\n", game->position.move);
    ft_close_game(game);
}

