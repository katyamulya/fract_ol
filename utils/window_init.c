/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:38:43 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/16 17:32:37 by kdvarako         ###   ########.fr       */
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

void	init_var(t_mlx *mlx, int fractol, double x, double y)
{
	mlx->fractol = fractol;
	mlx->x = x;
	mlx->y = y;
}

void	window_init(int fractol, double x, double y)
{
	t_mlx	mlx;
	int		col;

	mlx.mlx = mlx_init();
	init_var(&mlx, fractol, x, y);
	if (fractol == 1)
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Mandelbrot");
	else
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Julia");
	mlx.img.img = mlx_new_image(mlx.mlx, 1000, 1000);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	col = create_trgb(0, 2, 100, 250);
	my_mlx_pixel_put(&mlx.img, 50, 50, col);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	hook_events(&mlx);
	mlx_loop(mlx.mlx);
}

/*
void	window_init(void)
{
	t_mlx	mlx;

	int y = 100;
	int x;
	int col;
	int b = 255;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Hello!");

	mlx.img.img = mlx_new_image(mlx.mlx,  1000, 1000);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);

	col = create_trgb(0, 2, 100, b);
	while (y <= 350)
	{
		x = 100;
		while (x <= 150)
		{
			my_mlx_pixel_put(&mlx.img, x, y, col);
			mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
			x++;
		}
		if (b == 0)
			b = 255;
		else
			b--;
		col = create_trgb(0, b / 10, b / 10, b);
		y++;
	}
	hook_events(&mlx);
	mlx_loop(mlx.mlx);
}
*/