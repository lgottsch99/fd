/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:32:05 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/27 19:55:54 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//parse map and create structure
//int *ptr = array of ptrs to list nodes????

// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;


// } t_fdf; //big


void	parse_map(t_fdf *big, char *argv[])
{
	char 	*ptr; // make a list? , then connect gnl+split result to each node
	char	**tmp;
	int		fd;
	
	//open file
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error opening map\n");
		return;
	}
	//do this until ptr = null/eof
		//each time malloc new 
	ptr = get_next_line(fd); //1.
	tmp = ft_split(ptr, ' '); //2.

	ft_printf("line: %s\n", ptr);
	int i;
	i = 0;
	while (tmp[i])
	{
		ft_printf("%s\n", tmp[i]);
		i++;
	}

}