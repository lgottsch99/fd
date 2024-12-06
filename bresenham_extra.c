/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:59:37 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/06 17:01:06 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_direction(int delta) //bestimme in welche richtung auf achse gehen muss
{
	if (delta < 0)
		return (-1);
	if (delta > 0)
		return (1);
	return (0);
}