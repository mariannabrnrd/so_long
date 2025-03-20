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

void    check_argument(int ac, char **av, t_game *game)
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
