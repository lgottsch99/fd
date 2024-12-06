/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:50 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/06 20:39:16 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
TO DO
adjust to new map structure (t_coord ** array of T_coord *lists)

typedef struct s_rgb {
	int r;
	int g; 
	int b;
} t_rgb;


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
	int		max_color;
} t_fdf; //big

*/



void free_image(t_data *image)
{
	if (image->img)
		free(image->img);
	if (image->addr)
		free(image->addr);
}

// void free_map(t_list *map) //traverses list and frees each node
// {
// 	t_list	*tmp;
	
// 	while (map)
// 	{
// 		tmp = map;
// 		map = map->next;
// 		free(tmp);
// 	}
// }

void free_coord_list(t_coord *nodes)
{
			ft_printf("in free coord list\n");

	t_coord *tmp;
	
	while(nodes)
	{
		tmp = nodes;
		nodes = nodes->next;
		free(tmp);
	}
}

void free_map(t_coord	**map, int size)
{
			ft_printf("in free map\n");

	int i;
	t_coord *tmp;

	i = 0;
	while (i < size)//go thru array of ptrs
	{
		tmp = map[i];
		free_coord_list(tmp);//free each node in list
		i++;
	}
}

// typedef struct s_fdf {
// 	void	*mlx; //connection to server
// 	t_data	*image; //another struct see above
// 	void	*window;
// 	t_coord	**map;
// 	int 	size_x; //size map in right 
// 	int		size_y;
// 	int		highest_height;
// 	int		tile_size;
// 	int		color;
// 	int		max_color;
// } t_fdf; //big

void free_big(t_fdf *big)
{
		ft_printf("in free big\n");

	if(big->image && big->mlx && big->image->img)
	{
		ft_printf("freeing image\n");

		mlx_destroy_image(big->mlx, big->image->img);
		free(big->image);
	}
	if (big->window && big->mlx)
	{
				ft_printf("freeing window\n");
	ft_printf("big->mlx: %p\n", big->mlx);
ft_printf("big->window: %p\n", big->window);

		mlx_destroy_window(big->mlx, big->window);
		//free(big->window);
	}
	if (big->map)
	{
		ft_printf("freeing map\n");

		free_map(big->map, big->size_x); //frees whole map
		free(big->map); //free ptr array
	}
	
	if(big->mlx)
	{
		ft_printf("freeing mlx\n");

		mlx_destroy_display(big->mlx);
		free(big->mlx);
	}

}

void free_everything(t_fdf *big)
{
	
	ft_printf("in freeing\n");

	if (big)
	{
		free_big(big); //frees stuff inside big
		//free(big); //frees rest? necessary? big is stacked
	}
	exit(1);
}