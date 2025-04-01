/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:50:26 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/31 10:50:29 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*safely loading the photos (and verifying)*/
void    ft_safe_load(t_game *game, t_game_img *tile, char *path)
{
    tile->img = mlx_xpm_file_to_image(game->process, path, &tile->b, &tile->h);
    if (!tile->img)
    {
        ft_printf("Error\nFailed to load images: %s\n", path);
        ft_destroy_images(game);
        ft_error_map(":(", game);
    }
}

/*delete photos to prevent memory leaks*/
void    ft_destroy_images(t_game *game)
{
    if (game->player.img)
        mlx_destroy_image(game->process, game->player.img);
    if (game->floor.img)
        mlx_destroy_image(game->process, game->floor.img);
    if (game->wall.img)
        mlx_destroy_image(game->process, game->wall.img);
    if (game->exit_c.img)
        mlx_destroy_image(game->process, game->exit_c.img);
    if (game->exit_o.img)
        mlx_destroy_image(game->process, game->exit_o.img);
    if (game->collectible.img)
        mlx_destroy_image(game->process, game->collectible.img);
}
