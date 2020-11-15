/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:59:50 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 12:08:14 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		prs_num(int dx, int dy, int x_st, int y_st)
{
	int		res_x;
	int		res_y;

	if (x_st == 0)
		return (1);
	if (y_st == 0)
		return (0);
	res_x = ft_abs(dx) / x_st;
	res_y = ft_abs(dy) / y_st;
	return ((res_y < res_x) ? 1 : 0);
}

int		fdf_atoi(t_fdf *sct, const char *str)
{
	int			check;
	long long	v;
	int			neg;

	neg = 0;
	v = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		neg = (*(str++) == '-') ? 1 : 0;
	check = *str - '0';
	while (*str && (*str >= '0') && (*str <= '9'))
		v = v * 10 + (*(str++) - 48);
	if ((*str) || (v > 2147483648 || (!neg && v > 2147483647)))
		err_exit(sct, "Error");
	if ((v == 0) && (check != v))
		err_exit(sct, "Error");
	return ((neg) ? v * -1 : v);
}

int		fdf_atoi_hex(t_fdf *sct, const char *str)
{
	int			i;
	long long	v;

	i = 0;
	v = 0;
	if (str[i] != '0' && str[i + 1] != 'x')
		err_exit(sct, "Error");
	i++;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			v = v * 16 + (str[i] - 48);
		else if (str[i] >= 'a' && str[i] <= 'f')
			v = v * 16 + (str[i] - 'a');
		else if (str[i] >= 'A' && str[i] <= 'F')
			v = v * 16 + (str[i] - 'A');
		else
			err_exit(sct, "Error");
	}
	if (str[i] || v > 0xffffff || v == 0)
		err_exit(sct, "Error");
	return (v);
}

void	iso(double *x, double *y, int z, t_fdf *sct)
{
	*x = (*x - *y) * cos(sct->cos);
	*y = (*x + *y) * sin(sct->sin) - z;
}
