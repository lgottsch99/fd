/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:12:04 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/03 18:58:22 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./full_libft/full_libft.h"
#include <math.h> //math fts like sin cos
#include "./mlx_linux/mlx.h" //minilibx for graphics rendering
#include <X11/keysym.h> //defines some keycodes, only needed on linux?
//#include <X.h> //for event macros like KeyPress https://codebrowser.dev/kde/include/X11/X.h.html
#include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 720
#define OFF_X 0.2 * HEIGHT //offset point for (0;0) in graphic
#define OFF_Y WIDTH/2
#define BUF_BOTTOM HEIGHT - OFF_X
#define BUF_LEFT 0.1 * WIDTH
#define BUF_RIGHT WIDTH - BUF_LEFT

typedef struct	s_data {
	void	*img; //memadress of img
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;


typedef struct s_coord {
	int 	x;
	int 	y;
	int 	height;
	struct s_coord	*next;
} t_coord;


typedef struct s_line {
	int parallel_x;
	int	parallel_y;
	int	diagonal_x;
	int	diagonal_y;
	int	delta_slow;
	int	delta_fast;
} t_line;

typedef struct s_fdf {
	void	*mlx; //connection to server
	t_data	*image; //another struct see above
	void	*window;
	t_coord	**map;
	int 	size_x; //size map in right 
	int		size_y;
	int		highest_height;
	int		tile_size;
	int		color;

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

//parse_map.c
void	parse_map(t_fdf *big, char *argv[]);

//create_image.c
void	create_image(t_fdf	*big);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		calc_tilesize(t_fdf *big); //ignore height, subject says maps need to be properly formatted only 

//draw lines.c
void	draw_lines(t_fdf *big, t_coord *current, t_coord *one_before, t_coord *up_pix); //reihe fuer reihe
t_coord	*get_pix_coord(t_fdf *big, t_coord *point);


//utils.c
int		count_x(t_list	*map);
int		get_direction(int delta); //bestimme in welche richtung auf achse gehen muss
t_coord *getlastcoord(t_coord *coords);
void	add_to_list(t_coord **coords, t_coord *list); //adding to end of list


//free.c
void free_image(t_data *image);
void free_map(t_list *map); //traverses list and frees each node
void free_big(t_fdf *big);
void free_everything(t_fdf *big);



#endif