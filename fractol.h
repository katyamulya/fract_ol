/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:49:11 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/25 12:27:26 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>

# include <stdio.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx{
	void	*mlx;
	void	*win;
	t_data	img;
	int		fractol;
	double	x;
	double	y;
	int		max_i;
	double	zoom;
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	movex;
	double	movey;
	int		color;
}				t_mlx;

typedef struct s_pix{
	int	x;
	int	y;
}				t_pix;

/*
typedef struct s_vars{
	void	*mlx;
	void	*win;
}				t_vars;*/

//utils:
int		ft_strcmp(char *s1, char *s2);
void	window_init(int fractol, double x, double y);
void	avaliable_params(void);
double	ft_atod(char *str);
void	hook_events(t_mlx *mlx);
int		draw_fractol(t_mlx *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	burning_ship(t_mlx *mlx, t_pix p);

#endif