/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:36:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/22 18:13:25 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
use minilibx for graphics rendering + math.h

image = graphical object representing pixel data
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
	
???
how to create image (=get pixels) =parse map
what is image data type, how are pixels stored 
what happens if transparency is changed?

Strategy:
open window
create hooks:
	esc/ x in window to close and end program
	resizing window? - need to re render the image?
	
	
create whole image parsing the map, then send to window???
clean up: 
	close window, free mem of image, close connection to x server

TO DO 
go thru 42 docs https://harm-smits.github.io/42docs/libs/minilibx/colors.html
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; //pointer to specific pixel in mem, data->addr = starting point of img in mem 

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8)); //go to specific location
	*(unsigned int*)dst = color; //set color to pixel
}


int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init(); //connect to x server
	window = mlx_new_window(mlx, 640, 360, "Test"); //create window
	mlx_loop(mlx); //initiate window rendering
	
}