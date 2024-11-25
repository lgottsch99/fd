/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:36:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/25 16:57:36 by lgottsch         ###   ########.fr       */
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
read about isometric projection > find way to to it

*/

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf mapfile.fdf\n");
		return (0);
	}
	//open and read from map
		//get coord xyz for each value
		
	return (0);	
}