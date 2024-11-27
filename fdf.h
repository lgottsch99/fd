/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:12:04 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/27 19:44:22 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./full_libft/full_libft.h"

#include <math.h> //math fts like sin cos
#include "./mlx_linux/mlx.h" //minilibx for graphics rendering
#include <X11/keysym.h> //defines some keycodes, only needed on linux?
//#include <X.h> //for event macros like KeyPress https://codebrowser.dev/kde/include/X11/X.h.html
#include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 720

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


} t_fdf; //big


//color.c
int		create_color(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//gradient.c
int		add_shade(double distance, int color);
int		get_opposite(int color);

//hooks
int	quit_window(t_fdf *big);
int	destroy_esc(int keycode, t_fdf *big); //int is passed by internal event handler

//map_coord.c
void	parse_map(t_fdf *big, char *argv[]);

//utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif