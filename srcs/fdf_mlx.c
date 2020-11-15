/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:29:54 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 12:45:26 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_exit(t_fdf *sct)
{
	mlx_destroy_window(sct->mlx_ptr, sct->win_ptr);
	full_free(sct);
	exit(0);
}

void	draw(t_fdf *sct)
{
	draw_map(sct);
	draw_menu(sct);
}

void	deal_key_2(int key, t_fdf *sct)
{
	if (key == 76)
		sct->sel = 0;
	if (key == 69)
		color_increase(sct, 5);
	if (key == 78)
		color_increase(sct, -5);
	if (key == 49)
	{
		sct->color = sct->white;
		color_map(sct);
	}
	if (key == 24 || key == 27)
		zoom_key(key, sct);
	if (key == 126 || key == 125 || key == 124 || key == 123)
		move_key(key, sct);
	if (key == 34)
		sct->iso = (sct->iso) ? 0 : 1;
	if (key == 53)
		mlx_exit(sct);
}

int		deal_key(int key, t_fdf *sct)
{
	if (key == 11 || key == 48)
	{
		color_key(key, sct);
	}
	if (key == 67)
	{
		if (sct->sel == 3)
			sct->sel = 1;
		else
			sct->sel++;
	}
	deal_key_2(key, sct);
	mlx_clear_window(sct->mlx_ptr, sct->win_ptr);
	draw(sct);
	return (0);
}

void	mlx_main(t_fdf *sct)
{
	mlx_ini(sct);
	draw(sct);
	mlx_key_hook(sct->win_ptr, deal_key, sct);
	mlx_loop(sct->mlx_ptr);
}
