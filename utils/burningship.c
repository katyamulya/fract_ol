/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:27:04 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/27 15:27:34 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_i_bs(t_mlx *mlx)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < mlx->max_i)
	{
		mlx->oldre = fabs(mlx->newre);
		mlx->oldim = fabs(mlx->newim);
		mlx->newre = (mlx->oldre * mlx->oldre) \
			- (mlx->oldim * mlx->oldim) + mlx->cre;
		mlx->newim = 2 * (mlx->oldre * mlx->oldim) + mlx->cim;
		if (((mlx->newre * mlx->newre) + (mlx->newim * mlx->newim)) > 4)
			break ;
		i++;
	}
	return (i);
}

void	burning_ship(t_mlx *mlx, t_pix p)
{
	int		i;
	int		col;

	mlx->newre = 0;
	mlx->newim = 0;
	mlx->oldre = 0;
	mlx->oldim = 0;
	mlx->cre = (p.x * (4.0 / 1000) - 2) / mlx->zoom + mlx->movex;
	mlx->cim = (p.y * (4.0 / 1000) - 2) / mlx->zoom + mlx->movey;
	i = calculate_i_bs(mlx);
	col = create_trgb(0, (i % 256), ((i + 150) / 256), 230);
	if (i == mlx->max_i)
		my_mlx_pixel_put(&mlx->img, p.x, p.y, 0);
	else
		my_mlx_pixel_put(&mlx->img, p.x, p.y, col * i);
}
