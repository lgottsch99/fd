/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:26:26 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/06 15:26:47 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
add_shade is a function that accepts a double (distance) and a int (color) as 
arguments, 0 will add no shading to the color, whilst 1 will make the color 
completely dark. 0.5 will dim it halfway, and .25 a quarter way.
double = floating point
*/
int	add_shade(double distance, int color)
{
	int	t;
	int r;
	int g;
	int b;

	//get single color values
	//change value individually using distance
	t = get_t(color) * (1 - distance);
	r = get_r(color) * (1 - distance);
	g = get_g(color) * (1 - distance);
	b = get_b(color) * (1 - distance);

	//create new int
	return (create_color(t, r, g, b));
}

/*
get_opposite is a function that accepts a int (color) as argument and that 
will invert the color accordingly.
Colour inversion is the colour left over when you deduct one RGB value from 255, 
which is the highest RGB value you can have.
*/
int	get_opposite(int color)
{
	int t;
	int r;
	int g;
	int b;

	t = 255 - get_t(color);
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_color(t, r, g, b));
}
