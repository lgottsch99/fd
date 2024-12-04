/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:59:25 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/04 16:59:23 by lgottsch         ###   ########.fr       */
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
	{
		free(split[nr]);
		nr++;		
	}
	free(split);
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

void	add_to_list(t_coord **coords, t_coord *list)//sometimes segfault (ex basictest.fdf)
{
		//ft_printf("in add to list\n");

	t_coord *last;

	if(coords)
	{
		if(*coords)//will be null first time
		{
			//ft_printf("in if\n");
			last = getlastcoord(coords);
			//ft_printf("address last: %p\n", last);

			//ft_printf("nr in last node in list: %i\n", last->height);
			if (last)
				last->next = list;
		}
		else //= first run
			*coords = list;
	}
	//ft_printf("added to list\n");
}

t_coord *getlastcoord(t_coord **coords)
{
				//ft_printf("in get last\n");
	t_coord *tmp;

	if (coords && *coords)
	{
		//ft_printf("in if\n");

		tmp = *coords;
		while (tmp->next)
		{
			//ft_printf("in loop\n");
			tmp = tmp->next;
		}
		return (tmp);
	}
	return (NULL);
}
