/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:23:34 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 11:36:41 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initial(t_fdf *sct)
{
	sct->max = -234554332;
	sct->min = 234554324;
	sct->mx_y = 0;
	sct->sel = 0;
	sct->tmp = 0;
	sct->color_flag = 1;
	sct->mx_x = 0;
	sct->sin = 0.8;
	sct->cos = 0.8;
	sct->zoom = 16;
	sct->iso = 0;
	sct->red = 0xff2222;
	sct->blue = 0x2222ff;
	sct->green = 0x22ff22;
	sct->white = 0xffffff;
	sct->tmpx = 0;
	sct->x2 = 0;
	sct->y2 = 0;
	sct->tmpy = 0;
	sct->color = sct->red;
	sct->line = NULL;
}

void	mlx_ini(t_fdf *sct)
{
	sct->mlx_ptr = mlx_init();
	sct->win_ptr = mlx_new_window(sct->mlx_ptr, 1000, 1000, "fdf.erandal");
}
