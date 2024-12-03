/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:01:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/03 19:06:53 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
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
	int		color;

} t_fdf; //big

*/
void	schleife(t_fdf *big, t_line *initializing, t_coord *before_pix);

t_coord	*get_pix_coord(t_fdf *big, t_coord *point)
{
	t_coord *pix;

	pix = (t_coord *)malloc(sizeof(t_coord));
	if (!pix)
	{
		ft_printf("error malloc pix\n");
		return (NULL);
	}
	pix->x = OFF_X + ((point->y * (big->tile_size/2)) + (point->x * (big->tile_size/2)))- point->height;
	pix->y = OFF_Y + ((point->y * big->tile_size) - (point->x * big->tile_size)); // = hoehe
	return (pix);
}

// typedef struct s_line {
// 	int parallel_x;
// 	int	parallel_y;
// 	int	diagonal_x;
// 	int	diagonal_y;
// 	int	delta_slow;
// 	int	delta_fast;
// } t_line;

void	x_fast(int dx, int dy, int richtung_x, int richtung_y, t_line *initializing)
{	
	initializing->parallel_x = richtung_x;
	initializing->diagonal_x = richtung_x;
	initializing->parallel_y = 0;
	initializing->diagonal_y = richtung_y;
	initializing->delta_slow = dy;
	initializing->delta_fast = dx;
}

void	y_fast(int dx, int dy, int richtung_x, int richtung_y, t_line *initializing)
{
	initializing->parallel_x = 0;
	initializing->diagonal_x = richtung_x;
	initializing->parallel_y = richtung_y;
	initializing->diagonal_y = richtung_y;
	initializing->delta_slow = dx;
	initializing->delta_fast = dy;
}

void	bresenham(t_fdf *big, t_coord *current, t_coord *point_before) //always only 2 ppoints needed
{
	ft_printf("in bresenham\n");

	//abstand/ deltas berechnen zwischen altem und neuen punkt (x0 = alter, x1 neuer punkt)
	//current ! -> need actual pix coords here
	int		dx; //abstand
	int		dy;
	int		richtung_x; //richtung bewegung
	int		richtung_y;
	t_coord	*current_pix; //pixel coords
	t_coord	*before_pix;
	t_line	*initializing; //to set data needed to draw line
	
	current_pix = get_pix_coord(big, current);
	// ft_printf("pixel current x: %i\n", current_pix->x);
	// ft_printf("pixel current y: %i\n", current_pix->y);
	before_pix = get_pix_coord(big, point_before);
	// ft_printf("point before pix x: %i\n", before_pix->x);
	// ft_printf("point before pix y: %i\n", before_pix->y);

	//entfernung 2 punkte berechnen = delta
	dx = current_pix->x - before_pix->x;
	dy = current_pix->y - before_pix->y;
	// ft_printf("dx: %i\n", dx);
	// ft_printf("dy: %i\n", dy);

	//bestimme richtung bewegung und bekomme absoluten wert
	richtung_x = get_direction(dx); ///returns -1 oder 1 oder 0
	richtung_y = get_direction(dy);
	if (dx < 0)
		dx = -1 * dx;
	if (dy < 0)
		dy = -1 * dy;
	
	initializing = (t_line *)malloc(sizeof(t_line)); //malloc space for data 
	if (!initializing)
	{
		ft_printf("error malloc initializing\n");
		return;
	}
	//define schnelle richtung (bigger absolute delta) und set values accordingly
	if (dx > dy) //x ist schnelle richtung
		x_fast(dx, dy, richtung_x, richtung_y, initializing);
	else //y ist schnelle richtung
		y_fast(dx, dy, richtung_x, richtung_y, initializing);
	
	schleife(big, initializing, before_pix);
}

void	schleife(t_fdf *big, t_line *initializing, t_coord *before_pix)
{
	//ft_printf("in schleife\n");

	int i; //counting pixel
	int x;
	int y;
	int fehler;

	x = before_pix->x;
	y = before_pix->y;
	fehler = initializing->delta_fast / 2; //ausgang fehler
	//ft_printf("ausgangspunkt gesetzt\n");
	//put pixel at start? //not needed in my case
	if (x < HEIGHT && x > 0 && y < WIDTH && y > 0)
		my_mlx_pixel_put(big->image, x, y, big->color);
	ft_printf("erster punkt gemalt?\n");
	//pixel berechnen und setzen 
	i = 0;
	while (i < initializing->delta_fast)
	{
		//fehler neu berechnen
		fehler = fehler - initializing->delta_slow;
		if (fehler < 0)
		{
			//fehler wider positiv
			fehler = fehler + initializing->delta_fast;
			x = x + initializing->diagonal_x;
			y = y + initializing->diagonal_y;
		}
		else
		{
			x = x + initializing->parallel_x;
			y = y + initializing->parallel_y;
		}
		if (x < HEIGHT && x > 0 && y < WIDTH && y > 0)
			my_mlx_pixel_put(big->image, x, y, big->color);
		i++;
	}
	ft_printf("line drawn\n");
}

void	draw_lines(t_fdf *big, t_coord *current, t_coord *one_before, t_coord *up_pix) //reihe fuer reihe
{
	ft_printf("in draw lines\n");
	
	//check which scenario
	if(current->x == 0)//erste reihe ->nix nach oben
	{
		ft_printf("erste reihe\n");

		if (current->y == 0) //punkt 0/0 nothing to draw
			return;
		else //y position == 0 -> keine linie nach links
			bresenham(big, one_before, current);//go left
	}
	else
	{
		if(current->y == 0) //falls linker rand-> nix nach links
		{
			bresenham(big, up_pix, current); //go up
		}
		else
		{
			bresenham(big, up_pix,  current); //go up
			bresenham(big, one_before, current); //go left
		}
	}
}
