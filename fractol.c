/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:46:44 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/16 17:30:07 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	double	x;
	double	y;

	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		window_init(1, 0.0, 0.0);
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		x = ft_atod(argv[2]);
		y = ft_atod(argv[3]);

		window_init(2, x, y);
	}
	else
		avaliable_params();
	return (0);
}
