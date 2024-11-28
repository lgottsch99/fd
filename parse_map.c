/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:32:05 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/28 18:04:57 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//parse map and create structure
//int *ptr = array of ptrs to list nodes????

// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;
//  t_list	*map;

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
		
		node = ft_lstnew(trimmed);
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
	ft_lstiter(big->map, print_list);
	
	
	
}
