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

#include "so_long.h"

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

/*free the fill*/
void    ft_free_fill(char **fill, int cols)
{
    char    **temp;

    if(!fill || !*fill)
        ft_error("map not found");
    temp = fill;
    while (cols > 0 && *temp != NULL)
    {
        free(*temp);
        temp++;
        cols--;
    }
    free(fill);
}