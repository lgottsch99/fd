/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:12:20 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/07 14:11:18 by lgottsch         ###   ########.fr       */
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
	
	ft_printf("size x; %i\n", big->size_x);
	ft_printf("size y; %i\n", big->size_y);

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
				//ft_printf("before draw lines\n");

			draw_lines(big, current, one_before, upper);
// ft_printf("back from line drawn\n");
			if (current)
				one_before = current;
			if(upper && upper->next)
				upper = upper->next;
			if(current->next)
				current = current->next; //traverse list

			y++;
		}
						// ft_printf("back in outer\n");

		x++;
	}
				// ft_printf("loop done\n");

}

