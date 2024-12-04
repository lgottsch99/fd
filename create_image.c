/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:12:20 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/04 17:52:13 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
create image
somehow put offset at good location in image
somehow render image using t_list data

STRATEGY
	just start at point WiDTH/2 HEIGHT/2 and see how it goes / POSSIBLE TO GET MIDDLE OF MAP AND PUT IT IN MIDDLE OF IMG????
	count nr of tiles in x and y
	
	calculate a tile size that will fit everything into image (maybe limit= 80% of space?)
	
	MAYBE: get pixel coords for each point first, then draw lines ?
	
	
	plot points onto image
	draw lines between 

typedef struct s_coord {
	int 	x;
	int 	y;
	int 	height;
	s_coord	*next;
} t_coord;

typedef struct	s_data {
	void	*img; //memadress of img
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_fdf {
	void	*mlx; //connection to server
	t_data	*image; //another struct see above
	void	*window;
	t_list	*map;
	int 	size_x; //size map in right 
	int		size_y;
	int		tile_size;

} t_fdf; //big

*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; //pointer to specific pixel in mem, data->addr = starting point of img in mem 

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8)); //go to specific location
	*(unsigned int*)dst = color; //set color to pixel
}

// int		get_tile_size(int nr_x, int nr_y, int zero_x, int zero_y) //TO DO
// {
// 	int	tile_size;

// 	tile_size = 10;
// 	//space for floor map = width pixel x nry pixel 
// 	//find highest and lowest value in map
// 	return (tile_size);
// }

// t_coord	*get_node(char *str, int i, int u) //creates list coord node with correct values assigned
// {
// 	t_coord	*node;

// 	node = (t_coord *)malloc(sizeof(t_coord));
// 	if(!node)
// 	{
// 		ft_printf("error creating coord node\n");
// 		return(NULL);
// 	}
// 		//i = y value
// 		//u = position in tmp = x value
// 		//atoi = height
	
// 	node->y = i;
// 	node->x = u;
// 	node->height = ft_atoi(str);
// 	//ft_printf("height: %i\n", node->height);
// 	node->next = NULL;

// 	return(node);
	
// }

// t_coord	*get_coords(t_list *list, int i) //returns list wit coords for current line
// {//create t_coord liste mit werten for each nr in str
// 	t_coord	*coord_list;
// 	t_coord *node;
// 	t_coord *traverse;
// 	char	*str; 
// 	char	**tmp;
// 	int		u;

// 	coord_list = NULL;
	
// 	str = list->content; //first in list
// 	ft_printf("str to split: %s\n", str);
		
// 	//split + atoi + create coords
// 	tmp = ft_split(str, ' ');
	
// 	node = get_node(tmp[0], i, 0); //first one //MALLOC
// 	if(!node)
// 	{
// 		ft_printf("error malloc 1. node\n");
// 		return(NULL);
// 	}
// 	coord_list = node;
	
// 	u = 1;
// 	while (tmp[u]) //go thru splitted strings +get nodes+ connect to list 
// 	{
// 		traverse = node; //pointer to last node
// 		node = get_node(tmp[u], i, u); //get node with values //MALLOC
// 		traverse->next = node;
		
// 		u++;
// 	}
// 	return (coord_list);
// }


// void	draw_stuff(t_fdf *big, t_coord *coords, t_coord *line_before) //manipulate pixels
// {//inside loop so for one line only
// 	//put points of current line first to try
// 		ft_printf("in draw stuff\n");

// 	t_coord *current; //eig unnoetig
// 	int 	x; //actual pixel address
// 	int 	y; //actual pixel address
// 	t_coord	one_before; //to rem letzten punkt
// 	t_coord up_pix;

// 	current = coords;
// 	while (current)//go through list of points/reihe fuer reihe und punkt f punkt
// 	{
// 		//ft_printf("trying to get pixels\n");
// 		//ft_printf("x coord: %i\n", current->x);
// 		//ft_printf("y coord: %i\n", current->y);

// 		//get pixel coords of point above
// 		if (line_before)
// 		{
// 			up_pix.x = line_before->x;
// 			up_pix.y = line_before->y;
// 			up_pix.height = line_before-> height;
// 		}
		
// 	//put pixel 								(CURRENTLY OHNE GUTEN OFFSET POINT !!!)
// 		//points 
// 		x = OFF_X + ((current->x * (big->tile_size/2)) + (current->y * (big->tile_size/2))) - current->height;
// 		y = OFF_Y + ((current->x * big->tile_size) - (current->y * big->tile_size)); //= hoehe
		
// 		ft_printf("corner x coord: %i\n", x);
// 		ft_printf("corner y coord: %i\n", y);
// 		//draw point
// 		my_mlx_pixel_put(big->image, x, y, big->color); //working fine
		
// 		//connect via lines
// 		if (!(current->x == 0 && current->y == 0)) //wenn erster punkt dann keine linie
// 			draw_lines(big, current, one_before, up_pix);

// 		//update one before values 
// 		one_before.x = current->x;
// 		one_before.y = current->y;
// 		one_before.height = current->height;
		
// 		current = current->next;
// 		if (line_before)
// 			line_before = line_before->next; //set them both to point at same x location
// 	}
// }


// void	plot_n_draw(t_fdf *big)
// {
// 	ft_printf("in plot n draw\n");
// 	//t_coord	*last_line; //to keep track of line before to draw lines
// 	int		i;
// 	t_list	*list;
// 	t_coord	*coords;
// 	t_coord *line_before;
// 		//offset = point zero
// 	//for each str in list
// 	line_before = NULL;
// 	//list = big->map;
// 	i = 0;
// 	while(i < big->size_y) //i = nr of list element =
// 	{
// 		ft_printf("traversing list and getting coords\n");

// 		coords = get_coords(list, i); //returns list with coords for current line
// 		// TO DO draw points and lines between last line
// 		draw_stuff(big, coords, line_before); //reihe fuer reihe
		
// 		line_before = coords;
		
// 		list = list->next; //traversing list
// 		i++;
// 	}

// }



int calc_tilesize(t_fdf *big) //ignore height, subject says maps need to be properly formatted only 
{
	int tile_size;
	int fdf_width;
	int fdf_height;
	int w; //for calc + test
	int h;
	//set buffers which should not be painted
		// #define OFF_X 0.2 * HEIGHT //offset point for (0;0) in graphic
		// #define OFF_Y WIDTH/2
		// #define BUF_BOTTOM HEIGHT - OFF_X
		// #define BUF_LEFT 0.2 * WIDTH
		// #define BUF_RIGHT WIDTH - BUF_LEFT

	fdf_width = 0;//update each loop if ok
	fdf_height = 0;
	w = 0;
	h = 0;
	//strategy: start small and make as big as fits
	//calc eddges
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

void	draw_stuff(t_fdf *big)
{
	//pass coord values only (no pix add needed, macht bresenham dann)
	//bresenham(big, current point, point_before) linie wird zwischen zwei punkten gezogen

	t_coord *current;
	t_coord *one_before;
	t_coord *upper;
	int x;
	int y;
	
	current = big->map[0]; //syntax ok?
	one_before = NULL;
	upper = NULL;
	
	//go thru map
		//use ptr to keep track of upper point, and point before
		//pass all of them to draw lines
	x = 0;
	while (x < big->size_x && big->map[x])
	{
		current = big->map[x];
		if(x > 0)
			upper = big->map[x - 1];

		y = 0;
		while (y < big->size_y)
		{
			draw_lines(big, current, one_before, upper);
			one_before = current;
			if(upper)
				upper = upper->next;
			current = current->next; //traverse list
			y++;
		}
		x++;
	}
}

void	create_image(t_fdf	*big)
{
	// calculate a tile size that will fit everything into image
	big->tile_size = calc_tilesize(big);
	ft_printf("tile size is: %i\n", big->tile_size);

	//do sth with colors ///TO DO LATER
	big->color = create_color(0, 0, 255, 255);
	// plot points onto image + draw lines between 
	draw_stuff(big);

}
