/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:32:05 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/29 19:27:48 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//parse map and create structure
//int *ptr = array of ptrs to list nodes????

// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;
// 	t_list	*map;
// 	int 	size_x; //size map in right 
// 	int		size_y;
// 	int		tile_size;

// } t_fdf; //big

void	print_list(void *node) //testing only
{
	ft_printf("content: %s\n", (char *)node);
}

static t_list	*create_list(int fd, t_list *list)
{
	char 	*trimmed;
	char	*line;
	t_list 	*node;
	
	while (1)
	{
//1. read line from map
		line = get_next_line(fd); 
		if(!line) //eof
		{
			ft_printf("eof reached\n");
			break;
		}
		trimmed = ft_strtrim(line, "\n");
		//ft_printf("trimmed: %s\n", trimmed);
		free(line);
		
		node = ft_lstnew(trimmed); //MALLOC!!
		//ft_printf("node content: %s\n", node ->content);
		ft_lstadd_back(&list, node);
	}
	return (list);
}


void	parse_map(t_fdf *big, char *argv[])
{
	t_list *list;
	int		fd;
	
	list = NULL;
	
	//open file
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error opening map\n");
		return;
	}
	list = create_list(fd, list);
	big->map = list;
	list = NULL;
	
	ft_lstiter(big->map, print_list); //test onlzy
	
// count nr of tiles in x and y //map = list of char strs
	big->size_x = count_x(big->map);
	ft_printf("nr x: %i\n", big->size_x);
	big->size_y = ft_lstsize(big->map);
	ft_printf("nr y: %i\n", big->size_y);
}
