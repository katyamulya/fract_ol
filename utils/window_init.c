/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:38:43 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/15 16:00:25 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pix;

	pix = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	window_init(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	printf("window init\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello!");
	//mlx_loop(mlx);

	img.img = mlx_new_image(mlx,  1000, 1000);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int y = 100;
	int x;
	int col;
	int b = 255;
	col = create_trgb(0, 2, 100, b);
	while (y <= 350)
	{
		x = 100;
		while (x <= 150)
		{
			my_mlx_pixel_put(&img, x, y, col);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			x++;
		}
		if (b == 0)
			b = 255;
		else
			b--;
		col = create_trgb(0, b/10, b/10, b);
		y++;
	}
	//my_mlx_pixel_put(&img, 150, 150, 0x00FF0000);
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
