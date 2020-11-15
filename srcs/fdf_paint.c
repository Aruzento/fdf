/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 02:13:59 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 12:51:32 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mix_color(int c1, int c2, double p)
{
	if (c1 == c2)
		return (c1);
	return ((int)((double)c1 + (c2 - c1) * p));
}

int		change_color(int c1, int c2, double persent)
{
	int r;
	int g;
	int b;

	r = mix_color(((c1 >> 16) & 0xff), ((c2 >> 16) & 0xff), persent);
	g = mix_color(((c1 >> 8) & 0xff), ((c2 >> 8) & 0xff), persent);
	b = mix_color(((c1) & 0xff), ((c2) & 0xff), persent);
	r = (r > 255) ? 255 : r;
	r = (r < 0) ? 0 : r;
	g = (g > 255) ? 255 : g;
	g = (g < 0) ? 0 : g;
	b = (b > 255) ? 255 : b;
	b = (b < 0) ? 0 : b;
	return (r << 16 | g << 8 | b);
}

void	bg_map(t_fdf *sct)
{
	int i;
	int j;

	i = -1;
	while (++i < sct->mx_y)
	{
		j = -1;
		while (++j < sct->mx_x)
			if (sct->mtx[i][j] == sct->min)
				sct->col[i][j] = sct->white;
	}
}

void	color_map(t_fdf *sct)
{
	int i;
	int j;

	i = -1;
	while (++i < sct->mx_y)
	{
		j = -1;
		while (++j < sct->mx_x)
			if (sct->mtx[i][j] == sct->max)
				sct->col[i][j] = sct->color;
			else if (sct->mtx[i][j] == sct->min)
				sct->col[i][j] = sct->white;
			else
				sct->col[i][j] = change_color(sct->white,
					sct->color, (((double)ft_abs(sct->mtx[i][j]))
					/ ((double)ft_abs(sct->max))));
	}
}
