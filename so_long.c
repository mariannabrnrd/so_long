/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:56:22 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/20 13:56:28 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_game game;

    ft_check_argument(ac, av);
    game.fd = open(av[1], O_RDONLY);
    if (game.fd < 0 || game.fd == 0)
        ft_error("file not opened");
    ft_init_game(&game);
    ft_init_map(&game);
    ft_init_layer(&game);
    ft_init_mlx(&game);
    ft_create_map(&game);
    ft_run_game(&game);
    ft_printf("funzionaaaa\n");

    return (0);
}
