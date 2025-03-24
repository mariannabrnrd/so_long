/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:24:50 by mariaber          #+#    #+#             */
/*   Updated: 2025/03/24 10:24:53 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_h"

/*free the repository*/
void    ft_free_repo(char **repo)
{
    char    **temp;

    if (!repo || !*repo)
        ft_error("map not found");
    temp = repo;
    while (*temp != NULL)
    {
        free(*temp);
        temp++;
    }
    free(repo);
}

/*free the grid*/
void    ft_free_grid(char **grid, int cols)
{
    char    **temp;

    if(!grid || !*grid)
        ft_error("map not found");
    temp = grid;
    while (cols > 0 && *temp != NULL)
    {
        free(*temp);
        temp++;
        cols--;
    }
    free(grid);
}