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

#include "so_long.h"

/*basic error*/
void    ft_error(char *mess)
{
    ft_printf("%s\n", mess);
    exit(1);
}

/*error for map*/
void    ft_error_map(char *mess, t_game *game)
{
    ft_free_repo(game->map.repo);
    ft_error(mess);
    exit(1);
}
