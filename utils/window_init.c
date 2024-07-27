/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:38:43 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/27 12:28:34 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pix;

	pix = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

void	init_var(t_mlx *mlx, int fractol, double x, double y)
{
	mlx->fractol = fractol;
	mlx->x = x;
	mlx->y = y;
	mlx->zoom = 1;
	mlx->movex = 0.0;
	mlx->movey = 0.0;
	mlx->max_i = 50;
	mlx->color = 255;
}

void	window_init(int fractol, double x, double y)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (fractol == 1)
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Mandelbrot");
	else if (fractol == 2)
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Julia");
	else
		mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Burning Ship");
	mlx.img.img = mlx_new_image(mlx.mlx, 1000, 1000);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	init_var(&mlx, fractol, x, y);
	hook_events(&mlx);
	draw_fractol(&mlx);
	mlx_loop(mlx.mlx);
}
