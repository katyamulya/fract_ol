/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:49:11 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/16 17:32:28 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# include <stdio.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_mlx{
	void	*mlx;
	void	*win;
	t_data	img;
	int		fractol;
	double	x;
	double	y;
}				t_mlx;

//utils:
int		ft_strcmp(char *s1, char *s2);
void	window_init(int fractol, double x, double y);
void	avaliable_params(void);
double	ft_atod(char *str);
//int		close_win(int keycode, t_mlx *vars);
void	hook_events(t_mlx *mlx);

#endif