/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:02:08 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/27 19:58:13 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h> //defines some keycodes
//#include <X.h> //for event macros like KeyPress https://codebrowser.dev/kde/include/X11/X.h.html

//??
// how to specify which key to press?

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	quit_window(t_vars window)
{
	mlx_destroy_window(window.mlx, window.win);

	return 0;
}

int	destroy_esc(int keycode, t_vars window) //int is passed by internal event handler
{
	//ft_printf("keycode: %i\n", keycode);
	if(keycode == XK_Escape) //defined in header
	{
		mlx_destroy_window(window.mlx, window.win);
		free(window.mlx);

		//free necerray stuff
	}
	return 0;
}
//SEG FAULT COMING FROM Passing by value, not operating on ptr/exact mem location 
int main(void)
{
	t_vars	*window;

	window = (t_vars *)malloc(sizeof(t_vars));
	if (! window)
		return (1);

	window->mlx = mlx_init();
	if (!window->mlx)
		return (1);
	window->win = mlx_new_window(window->mlx, 640, 360, "testest");
	if (!window->win)
	{
		free(window-> mlx);
		return (1);
	}
	
	mlx_hook(window->win, 2, 1L<<0, destroy_esc, &window); //pressing ESC key destroys window
	mlx_hook(window->win, 17, 1L<<0, quit_window, &window); //window closing when x is clicked
	mlx_loop(window->mlx);

}