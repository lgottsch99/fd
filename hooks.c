/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:37 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/06 19:09:35 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;
// t_list	*map;

// } t_fdf; //big

int	quit_window(t_fdf *big)
{
			ft_printf("x window\n");

	// mlx_destroy_window(big->mlx, big->window);
	free_everything(big);
	exit (0);
}

int	destroy_esc(int keycode, t_fdf *big) //int is passed by internal event handler
{
	ft_printf("esc window\n");
	//ft_printf("keycode: %i\n", keycode);
	if(keycode == XK_Escape) //defined in header
	{
		free_everything(big);
		//free necesarray stuff
	}
	exit(0);
}
