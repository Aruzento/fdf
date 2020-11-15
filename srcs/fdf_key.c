/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 04:57:41 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 12:49:28 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_key(int key, t_fdf *sct)
{
	if (key == 24 && (sct->zoom * 2 >= 0))
		sct->zoom *= 2;
	if (key == 27 && (sct->zoom / 2 > 0))
		sct->zoom /= 2;
}

void	move_key(int key, t_fdf *sct)
{
	if (key == 126)
		sct->y -= 10;
	if (key == 125)
		sct->y += 10;
	if (key == 124)
		sct->x += 10;
	if (key == 123)
		sct->x -= 10;
}

void	color_increase(t_fdf *sct, int inc)
{
	int r;
	int g;
	int b;

	r = (sct->color >> 16) & 0xff;
	g = (sct->color >> 8) & 0xff;
	b = sct->color & 0xff;
	if (sct->sel == 1)
		r += inc;
	else if (sct->sel == 2)
		g += inc;
	else if (sct->sel == 3)
		b += inc;
	r = (r > 255) ? 255 : r;
	r = (r < 0) ? 0 : r;
	g = (g > 255) ? 255 : g;
	g = (g < 0) ? 0 : g;
	b = (b > 255) ? 255 : b;
	b = (b < 0) ? 0 : b;
	sct->color = (r << 16 | g << 8 | b);
	color_map(sct);
}

void	color_key(int key, t_fdf *sct)
{
	if (key == 11)
	{
		sct->white = (sct->white == 0x000000) ? 0xffffff : 0x000000;
		bg_map(sct);
	}
	if (key == 48)
	{
		sct->color_flag = (++sct->color_flag == 4) ? 1 : sct->color_flag;
		if (sct->color_flag == 1)
			sct->color = sct->red;
		else if (sct->color_flag == 2)
			sct->color = sct->green;
		else
			sct->color = sct->blue;
		color_map(sct);
	}
}
