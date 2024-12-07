/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:32:05 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/07 13:23:30 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord **create_coord_list_ptrs(t_fdf *big);
t_coord *create_coord(int x, int y, char *str);
void	add_to_list(t_coord **coords, t_coord *list); //adding to end of list
void	fill_coords(t_fdf *big, t_list *list, t_coord **coords);



// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;
// 	t_coord	**map;
// 	int 	size_x; //size map in right 
// 	int		size_y;
// 	int		highest_height;
// 	int		tile_size;
// 	int		color;

// } t_fdf; //big


void	print_list(void *node) //testing only
{
	ft_printf("content: %s\n", (char *)node);
}

static t_list	*create_list(t_fdf *big, int fd, t_list *list)
{
	char 	*trimmed;
	char	*line;
	t_list 	*node;

	trimmed = NULL;
	line = NULL;
	node = NULL;
	while (1)//1. read line from map
	{
		line = get_next_line(fd);//malloc
		if(!line) //eof
		{
			ft_printf("eof reached\n");
			break;
		}
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if(!trimmed)
		{
			free_list(list);
			free_everything(big);
		}
		node = ft_lstnew(trimmed); //MALLOC!!
		if (!node)
		{
			free(trimmed);
			free_list(list);
			free_everything(big);
		}
		ft_lstadd_back(&list, node);
		node = NULL;
		trimmed = NULL;
	}
	return (list);
}

t_coord **create_coord_list_ptrs(t_fdf *big)
{
	//malloc space for coord_list ptrs
	int		i;
	t_coord **coord_list;

	coord_list = (t_coord **)malloc(sizeof(t_coord *) * big->size_x);
	if (!coord_list)
	{
		ft_printf("error malloc coord list\n");
		free_everything(big);
	}
	i = 0;
	while(i < big->size_x) //initialization needed for mem mgmt
	{
		coord_list[i] = NULL;
		i++;
	}
	return (coord_list);
}

void	fill_coords(t_fdf *big, t_list *list, t_coord **coords)
{	
	int	x;
	int	y;
	char **split;
	t_coord **tmp;
	t_coord *node; //pointer to new nodes 
	
	tmp = coords;
	x = 0;
	//ft_printf("size x: %i\n", big->size_x);
	while (x < big->size_x)	//for each node in list: (pos here = x value)
	{
		//ft_printf("list content: %s\n", (char *)list->content);
		//create single list of t_coords with values and add to coords
		split = ft_split((char *)list->content, ' '); //split content of one str to get single strs
		y = 0;
		while (y < big->size_y && split[y])//for each str : (position here = y value)
		{
			// ft_printf("str to create node for: %s\n", split[y]);
			// ft_printf("current x: %i\n", x);
			node = create_coord(x, y, split[y]);//atoi to get int value (=height)
			if(!node)
			{
				free_map(coords, x);
				free_everything(big);
			}
			free(split[y]);
			// ft_printf("spplit freed\n");
			// ft_printf("x val: %i\n", x);
			// ft_printf("y val: %i\n", y);
			add_to_list(&(coords[x]), node);
			ft_printf("added\n");
			node = NULL;
			y++;
		}
		free(split);
		split = NULL;
		tmp++;//move coords ptr in array to next list
		list = list->next;
		x++;
	}
	tmp = NULL;
}

t_coord *create_coord(int x, int y, char *str)
{
	//ft_printf("create coord for str: %s\n", str);
	t_coord *coord;
	//malloc struct node
	coord =(t_coord *)malloc(sizeof(t_coord));
	if (!coord)
	{
		ft_printf("error malloc coord node\n");
		return (NULL);
	}
	//fill w values
	coord->y = y;
	coord->x = x;
	coord->height = ft_atoi(str);
	coord->next = NULL;
	//ft_printf("created coord\n");
	return (coord);
}



void	parse_map(t_fdf *big, char *argv[]) //read and create map structure
{
	t_list  *list;
	t_coord **coords; //pointer to final mapped values
	int		fd;
	
	list = NULL;
	//open file
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("error opening map\n");
		free_everything(big);
	}
	list = create_list(big, fd, list);
	//ft_lstiter(list, print_list); //test onlzy
	// count nr of tiles in x and y //map = list of char strs
	big->size_x = ft_lstsize(list); //count nr elements in y direction
	ft_printf("nr x: %i\n", big->size_x);

	ft_printf("list: %s\n", list->content);

	big->size_y = count(list->content);
	ft_printf("nr y: %i\n", big->size_y);


	//create array of t_coord *ptrs (= array of pointers to lists)
	coords = create_coord_list_ptrs(big); //malloc array of pointers
	//ft_printf("created array of coord ptrs\n");
	fill_coords(big, list, coords); //fill with list and values
	ft_printf("filled everything w values\n");
	
	free_list(list); //list not needed anymore
	big->map = coords;
}

