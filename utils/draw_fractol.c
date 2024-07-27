/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:19:21 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/27 15:29:51 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_i_j(t_mlx *mlx)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < mlx->max_i)
	{
		mlx->oldre = mlx->newre;
		mlx->oldim = mlx->newim;
		mlx->newre = (mlx->oldre * mlx->oldre) \
			- (mlx->oldim * mlx->oldim) + mlx->cre;
		mlx->newim = (2 * mlx->oldre * mlx->oldim) + mlx->cim;
		if (((mlx->newre * mlx->newre) + (mlx->newim * mlx->newim)) > 4)
			break ;
		i++;
	}
	return (i);
}

int	calculate_i_m(t_mlx *mlx)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < mlx->max_i)
	{
		mlx->oldre = mlx->newre;
		mlx->oldim = mlx->newim;
		mlx->newre = (mlx->oldre * mlx->oldre) \
			- (mlx->oldim * mlx->oldim) + mlx->cre;
		mlx->newim = (2 * mlx->oldre * mlx->oldim) + mlx->cim;
		if (((mlx->newre * mlx->newre) + (mlx->newim * mlx->newim)) > 4)
			break ;
		i++;
	}
	return (i);
}

void	mandelbrot(t_mlx *mlx, t_pix p)
{
	int		i;
	int		col;

	mlx->newre = 0;
	mlx->newim = 0;
	mlx->oldre = 0;
	mlx->oldim = 0;
	mlx->cre = (p.x * (4.0 / 1000) - 2) / mlx->zoom + mlx->movex;
	mlx->cim = (p.y * (4.0 / 1000) - 2) / mlx->zoom + mlx->movey;
	i = calculate_i_m(mlx);
	col = create_trgb(0, (i % 256), ((i + 50) / 256), 250);
	if (i == mlx->max_i)
		my_mlx_pixel_put(&mlx->img, p.x, p.y, 256);
	else
		my_mlx_pixel_put(&mlx->img, p.x, p.y, col * i);
}

void	julia(t_mlx *mlx, t_pix p)
{
	int		i;
	int		col;

	mlx->cre = mlx->x;
	mlx->cim = mlx->y;
	mlx->newre = (p.x * (4.0 / 1000) - 2) / mlx->zoom + mlx->movex;
	mlx->newim = (p.y * (4.0 / 1000) - 2) / mlx->zoom + mlx->movey;
	i = calculate_i_j(mlx);
	col = create_trgb(0, (i % 256), ((i + 150) / 256), 250);
	if (i == mlx->max_i)
		my_mlx_pixel_put(&mlx->img, p.x, p.y, col * i);
	else
		my_mlx_pixel_put(&mlx->img, p.x, p.y, 256);
}

int	draw_fractol(t_mlx *mlx)
{
	t_pix	p;
	int		i;

	p.x = 0;
	while (p.x < 1000)
	{
		p.y = 0;
		while (p.y < 1000)
		{
			if (mlx->fractol == 1)
				mandelbrot(mlx, p);
			else if (mlx->fractol == 2)
				julia(mlx, p);
			else if (mlx->fractol == 3)
				burning_ship(mlx, p);
			p.y++;
		}
		p.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}
