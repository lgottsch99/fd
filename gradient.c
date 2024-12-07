/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:55:28 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/07 13:09:25 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



float	fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

float function(int x, int y, t_coord *before_pix, t_coord *current_pix)
{
	int dx;
	int dy;
	float fraction_value;
	
	dx = current_pix->x - before_pix->x;
	dy = current_pix->y - before_pix->y;
	if (abs(dx) > abs(dy))
		fraction_value = fraction(before_pix->x, current_pix->x, x);
	else
		fraction_value = fraction(before_pix->y, current_pix->y, y);
	return (fraction_value);	
}

int	get_pix_color(t_coord *before_pix, t_coord *current_pix, int x, int y)//color value stored in ->height
{
	//ft_printf("in get pix color\n");
	t_rgb before;
	t_rgb current;
	int new_r;
	int new_g;
	int new_b;
	
	before.r = get_r(before_pix->height);
	before.g = get_g(before_pix->height);
	before.b = get_b(before_pix->height);
	current.r = get_r(current_pix->height);
	current.g = get_g(current_pix->height);
	current.b = get_b(current_pix->height);
		// ft_printf("1\n");

	new_r = before.r + (current.r - before.r) * function(x, y, before_pix, current_pix);
	// if(new_r > 255)
	// 	new_r = 255;
	new_g = before.g + (current.g - before.g) * function(x, y, before_pix, current_pix);
	// if(new_g > 255)
	// 	new_g = 255;
	new_b = before.b + (current.b - before.b) * function(x, y, before_pix, current_pix);
	// if(new_b > 255)
	// 	new_b = 255;
			// ft_printf("2\n");

	return(create_color(0, new_r, new_g, new_b));
}
