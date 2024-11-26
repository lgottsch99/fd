/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:36:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/26 19:28:36 by Watanudon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
use minilibx for graphics rendering + math.h

image = graphical object representing pixel data, just a block of memory returned and stored in void*
bpp: bits per pixel
	= gibt vor wie viel mem pro pixel benutzt wird, je groesser desto mehr farben kann es geben
		24bpp = rgb, 32 bpp = rgba(a:alpha for transparency)
		in bpp 32 pixel stored in 4bytes/32bits, in bpp24 in 3bytes/24 bits -----> ein channel immer 8 bits (rot, green, blau, (alpha))
endianness: gibt reihenfolge der pixel an und wie sie in mem gespeichert werden
	=wichtig um bild zu kreieren/ daten zu lesen
line length: nr of bytes used to store one row of pixel data
Offset: byte position of a specific pixel within the image data buffer: Example:
	For an image of width 1000 pixels, with 24-bit RGB color (3 bytes per pixel), to access the pixel at row 2, column 500, the offset would be:
	Offset=(1000×3x2)+(500×3)=6000+1500=7500 bytes
	Thus, the pixel at (2, 500) is located 7500 bytes from the start of the image data buffer.
	OR 		int offset = (y * line_length + x * (bits_per_pixel / 8));
color: integer value, each component of the color (red, green, blue, and alpha) is encoded within a fixed number of bits
	A 32-bit integer can hold all of this data in a single number, using the following bitwise layout:
	0xAARRGGBB (in hexadecimal)
	AA alpha channel
	RR red
	...
	0xFF0000FF = ff (255=full)opaque, 0 red, 0 green, ff blue

events + hooks + masks: 
	event = sth happens that we an recognize, 
	mask = filter for event, allows to further specify type of event (often uses bitmasking)
	hook = custom code that will get executed afer certain event
	When an event happens, the corresponding hook is called, and it allows to define custom behavior.
	
???
how to create image (=get pixels) =parse map
what is image data type, how are pixels stored 
what happens if transparency is changed?
which structs to use? the ones from the lib? (probably bc otherwise segfault?-> check window handling)


fdf Strategy:
	open file map
	read from map + create image line for line 
	close file
	open window = hooks
	render image and push to window

clean up: 
	close window, free mem of image, close connection to x server

TO DO 
go thru 42 docs https://harm-smits.github.io/42docs/libs/minilibx/colors.html 
read about isometric projection > find way to to it https://m4nnb3ll.medium.com/fil-de-fer-fdf-the-first-graphical-project-at-42-the-network-5cce69203448 shift using cracy math


*/

/*
typedef struct	s_data {
	void	*img; //memadress of img
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

my crazy huge data struct 
*/
typedef struct s_fdf {
	void	*mlx; //connection to server
	t_data	*image; //another struct see above
	void	*window;


} t_fdf; //big


static t_fdf	*initialize(t_fdf *big) //initialize x connection, img, window
{
	big->mlx = mlx_init();
	if (!big->mlx)
		return NULL;

	big->image = (t_data *)malloc(sizeof(t_data)); //malloc space for image struct
	if (!big->image)
	{
		ft_printf("image malloc error\n");
		return (NULL);
	}
	big->image->img = mlx_new_image(big->mlx, WIDTH, HEIGHT); //create image
	big->image->addr = mlx_get_data_addr(big->image->img, &big->image->bits_per_pixel, &big->image->line_length, &big->image->endian); //get img data
	ft_printf("bpp: %i\n", big->image->bits_per_pixel);
	ft_printf("line length: %i\n", big->image->line_length);
	ft_printf("endian: %i\n", big->image->endian);
	big->window = mlx_new_window(big->mlx, WIDTH, HEIGHT, "FDF"); //create window

	//create pixel 

	mlx_put_image_to_window(big->mlx, big->window, big->image->img, 0, 0);
	return (big);
}

int	main(void)		//(int argc, char *argv[])
{
	t_fdf	*big; //my crazy big struct w everything

	big = (t_fdf *)malloc(sizeof(t_fdf));
	if (!big)
	{
		ft_printf("big malloc fail\n");
		return 1;
	}
	//check if input ok   ---> missing: .fdf file existing? 
	// if (argc != 2) 
	// {
	// 	ft_printf("Usage: ./fdf mapfile.fdf\n");
	// 	return (0);
	// }
	big = initialize(big);
	//hooks();

	mlx_loop(big->mlx);
	return (0);	
}