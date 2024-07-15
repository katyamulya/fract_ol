/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:50:17 by kdvarako          #+#    #+#             */
/*   Updated: 2024/07/15 12:52:32 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	check_dot(char *str)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	count = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			n = i;
			count++;
		}
		i++;
	}
	if (count == 0)
		return ;
	if (count > 1 || (count == 1 && (n == 0 || str[n] == '\0')))
		avaliable_params();
	if (count == 1 && (str[n - 1] >= '0' && str[n - 1] <= '9') && \
			(str[n + 1] >= '0' && str[n + 1] <= '9'))
		return ;
	else
		avaliable_params();
}

void	check_err(char *str)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '+' \
			&& str[i] != '-' && str[i] != '.')
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
				fl = 1;
			else
				avaliable_params();
		}
		i++;
	}
	if (fl == 0)
		avaliable_params();
	check_dot(str);
}

double	after_dot(char *str, int i)
{
	double	n;
	double	k;

	n = 0;
	k = 10;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n + (str[i] - '0') / k;
		k = k * 10;
		i++;
	}
	return (n);
}

double	ft_atod(char *str)
{
	int		i;
	int		sgn;
	double	num;
	int		fl;

	i = 0;
	num = 0;
	sgn = 1;
	fl = 0;
	check_err(str);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		sgn = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		num = num + after_dot(str, i + 1);
	return (num * sgn);
}
