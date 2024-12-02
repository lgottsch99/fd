/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:50 by lgottsch          #+#    #+#             */
/*   Updated: 2024/12/02 17:18:00 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
fts to free malloced mem

typedef struct	s_data {
	void	*img; //memadress of img
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data; //inside big only

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
*/



void free_image(t_data *image)
{
	if (image->img)
		free(image->img);
	if (image->addr)
		free(image->addr);
}

void free_map(t_list *map) //traverses list and frees each node
{
	t_list	*tmp;
	
	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp);
	}
}

void free_big(t_fdf *big)
{
	
	if(big->image && big->mlx)
	{
		mlx_destroy_image(big->mlx, big->image);
		//free_image(big->image); //? needed? 
		free(big->image);
	}
	if (big->window && big->mlx)
	{
		mlx_destroy_window(big->mlx, big->window);
		free(big->window);
	}

	if (big->map)
	{
		free_map(big->map); //frees whole map
		free(big->map);
	}
	
	if(big->mlx)
	{
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
	//	free(big); //frees rest? necessary? big is stacked
	}
	exit(1);
}