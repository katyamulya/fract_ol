/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avaliable_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:50:34 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/25 14:45:58 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	avaliable_params(void)
{
	ft_putstr_fd("Error. Please enter correct data, use the list below:\n", 1);
	write(1, "\n", 1);
	ft_putstr_fd("----------------------Fractals:-----------------------\n", 1);
	ft_putstr_fd("	- mandelbrot\n", 1);
	ft_putstr_fd("	- julia <x> <y> / example: x:-0.7 y:0.27015\n", 1);
	ft_putstr_fd("	- burning_ship\n", 1);
	ft_putstr_fd("------------------------------------------------------\n", 1);
	write(1, "\n", 1);
	exit(1);
}
