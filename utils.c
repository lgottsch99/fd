/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:59:25 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/30 14:49:17 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_x(t_list	*map)
{
	int 	nr;
	char	*tmp;
	char	**split;

	nr = 0;
	//just count length of one str
	tmp = map->content;
	//ft_printf("first map string: %s\n", tmp);
	split = ft_split(tmp, ' ');
	while (split[nr])
		nr++;
	return(nr);
}


int	get_direction(int delta) //bestimme in welche richtung auf achse gehen muss
{
	if (delta < 0)
		return (-1);
	if (delta > 0)
		return (1);
	return (0);
}
