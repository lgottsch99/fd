/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:36:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/20 19:51:53 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
use minilibx for graphics rendering + math.h

image = graphical object representing pixel data
bpp: bits per pixel
	= gibt vor wie viel mem pro pixel benutzt wird, je groesser desto  mehr farben kann es geben
		24bpp = rgb, 32 bpp = rgba(a:alpha for transparency)
		in bpp 32 pixel stored in 4bytes/32bits, in bpp24 in 3bytes/24 bits -----> ein channel immer 8 bits (rot, green, blau, (alpha))
endianness: gibt reihenfolge der pixel an und wie sie in mem gespeichert werden
	=wichtig um bild zu kreieren/ daten zu lesen

???
how to create image (=get pixels) =parse map
what is image data type, how are pixels stored 

STrategy:
open window
create hooks:
	esc/ x in window to close and end program
	resizing window? - need to re render the image?
	
	
create whole image parsing the map, then send to window???
clean up: 
	close window, free mem of image, close connection to x server


*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init(); //connect to x server
	window = mlx_new_window(mlx, 640, 360, "Test"); //create window
	mlx_loop(mlx); //initiate window rendering
	
}