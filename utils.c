/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:59:25 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/07 14:22:31 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int calc_tilesize(t_fdf *big) //ignore height, subject says maps need to be properly formatted only 
{
	int tile_size;
	int fdf_width;
	int fdf_height;
	int w; //for calc + test
	int h;

	fdf_width = 0;//update each loop if ok
	fdf_height = 0;
	w = 0;
	h = 0;
	tile_size = 1;
	while((w < BUF_RIGHT) && (h < BUF_BOTTOM))
	{
		w = BUF_LEFT + big->size_y * (tile_size * 2);
		h = OFF_X + big->size_x * (tile_size);
		if ((w < BUF_RIGHT) && (h < BUF_BOTTOM))
		{
			fdf_width = w;
			fdf_height = h;
			tile_size++;
		}
	}
	return (tile_size);
}

int count(char *s)//count words in s = y elements
{
	// ft_printf("list: %s\n", s);
	int i;
	int		nr;
 	
	nr = 0;
	i = 0;
	while (s[i])
	{
		// ft_printf("s[i]: %c\n", s[i]);
		if (s[i] == ' ')
			i++;
		else
		{
			nr++;
			while(s[i] != ' ' && s[i])
				i++;
		}
	}
	return(nr);
}

// int		count_x(t_list	*map)
// {
// 	int 	nr;
// 	char	*tmp;
// 	char	**split;

// 	nr = 0;
// 	//just count length of one str
// 	tmp = map->content;
// 	//ft_printf("first map string: %s\n", tmp);
// 	split = ft_split(tmp, ' ');
// 	while (split[nr])
// 	{
// 		free(split[nr]);
// 		nr++;		
// 	}
// 	free(split);
// 	return(nr);
// }


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
