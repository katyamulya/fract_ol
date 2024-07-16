/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:49:13 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/16 17:37:50 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	/*
	Keycode ESC = 53
	*/
	if (keycode == 53)
		close_win(mlx);
	return (0);
}

int mouse_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 4)
		printf("Scroll up\n");
	if (keycode == 5)
		printf("Scroll down\n");
	return (0);
}

void	hook_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx->win, 17, 1L << 2, close_win, &mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, &mlx);
}
