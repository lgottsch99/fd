#include "fdf.h"
#include <stdio.h>


typedef struct s_coord {
	int x;
	int y;
} 				t_coord;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; //pointer to specific pixel in mem, data->addr = starting point of img in mem 

	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8)); //go to specific location
	*(unsigned int*)dst = color; //set color to pixel
}

int main (void)
{
	void	*mlx;
	t_data	*img;
	void	*window;
	t_coord		*start;
	int	i;
	int color;
	int newcolor;

	img = (t_data *)malloc(sizeof(t_data)); //malloc space for struct
	if (!img)
	{
		printf("malloc error\n");
		return (1);
	}
	start = (t_coord *)malloc(sizeof(t_coord));
	if (!start)
	{
		printf("malloc error\n");
		return (1);
	}

	mlx = mlx_init(); //mlx init returns Null on error
	if (!mlx)
		return 1;
	window = mlx_new_window(mlx, 640, 360, "HII"); //create window
	img->img = mlx_new_image(mlx, 640, 360); //create image
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian); //get img data
	printf("bpp: %i\n", img->bits_per_pixel);
	printf("line length: %i\n", img->line_length);
	printf("endian: %i\n", img->endian);
	//printf("addr: %p\n", img->addr);

	//coordinates
	start->x = 20;
	start->y = 20;
	i = 0;

	//set color
	color = create_color(0, 255, 0, 255); 

	while (i < 100)
	{
		newcolor = add_shade(0 +(i * 0.01), color); 

		my_mlx_pixel_put(img, start->x, start->y + i, newcolor); //manipulate pixels in img
		my_mlx_pixel_put(img, start->x + i, start->y, newcolor); //manipulate pixels in img
		i++;
	}
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(img, start->x + i, start->y + 100, color); //manipulate pixels in img
		my_mlx_pixel_put(img, start->x + 100, start->y + i, color); //manipulate pixels in img
	i++;
	}
	
	mlx_put_image_to_window(mlx, window, img->img, 0, 0);
	mlx_loop(mlx);

	return 0;
}