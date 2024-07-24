/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:49:13 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/24 16:15:10 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
/*


void	rescaling(t_mlx *mlx, int x, int y)
{
	mlx->offset_x = (x * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->offset_x \
		- (x * (4.0 / 1000.0) - 2.0) / (mlx->zoom * mlx->zoom_up);
	mlx->offset_y = (y * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->offset_y \
		- (y * (4.0 / 1000.0) - 2.0) / (mlx->zoom * mlx->zoom_up);
}
*/

int	mouse_events(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 4)
	{
		mlx->zoom *= 1.1;
		if (mlx->max_i < 1000)
			mlx->max_i += 10;
	}
	else if (keycode == 5)
	{
		mlx->zoom *= 0.9;
		if (mlx->max_i > 50)
			mlx->max_i -= 10;
	}
	draw_fractol(mlx);
	return (0);
}

int	close_win(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	exit(1);
	return (0);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_win(mlx);
	else if (keycode == 125)
		mlx->movey += 0.01 / mlx->zoom;
	else if (keycode == 126)
		mlx->movey -= 0.01 * mlx->zoom;
	else if (keycode == 124)
		mlx->movex += 0.01 / mlx->zoom;
	else if (keycode == 123)
		mlx->movex -= 0.01 / mlx->zoom;
	draw_fractol(mlx);
	return (0);
}

void	hook_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 4, 0, &mouse_events, mlx);
	mlx_hook(mlx->win, 17, 0, &close_win, mlx);
	mlx_hook(mlx->win, 2, 0, &key_press, mlx);
}
