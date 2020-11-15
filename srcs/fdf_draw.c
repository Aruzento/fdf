/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:35:39 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 13:20:04 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_x_y(double *x1, double *y1, t_fdf *sct)
{
	sct->z1 = sct->mtx[(int)*y1][(int)*x1];
	sct->z2 = sct->mtx[(int)sct->y2][(int)sct->x2];
	sct->col1 = sct->col[(int)*y1][(int)*x1];
	sct->col2 = sct->col[(int)sct->y2][(int)sct->x2];
	if (sct->iso)
	{
		iso(x1, y1, sct->z1, sct);
		iso(&sct->x2, &sct->y2, sct->z2, sct);
	}
	*y1 = *y1 * sct->zoom + 250 + sct->y;
	sct->y2 = sct->y2 * sct->zoom + 250 + sct->y;
	*x1 = *x1 * sct->zoom + 250 + sct->x;
	sct->x2 = sct->x2 * sct->zoom + 250 + sct->x;
	sct->tmpx = *x1;
	sct->tmpy = *y1;
}

void	draw_line(double x1, double y1, int f, t_fdf *sct)
{
	double	persent;
	double	x_step;
	double	y_step;

	sct->x2 = (f) ? x1 : x1 + 1;
	sct->y2 = (f) ? y1 + 1 : y1;
	change_x_y(&x1, &y1, sct);
	x_step = (sct->x2 - x1)
		/ ft_max(ft_abs(sct->x2 - x1), ft_abs(sct->y2 - y1));
	y_step = (sct->y2 - y1)
		/ ft_max(ft_abs(sct->x2 - x1), ft_abs(sct->y2 - y1));
	while ((int)(sct->x2 - sct->tmpx) || (int)(sct->y2 - sct->tmpy))
	{
		if ((sct->tmpx > 1000 && sct->tmpy > 1000)
			|| (sct->tmpx < 0 && sct->tmpy < 0) || (!sct->col1 && !sct->col2))
			return ;
		if (!prs_num(sct->x2 - sct->tmpx, sct->y2 - sct->tmpy, x_step, y_step))
			persent = (sct->tmpx - x1) / (sct->x2 - x1);
		else
			persent = (sct->tmpy - y1) / (sct->y2 - y1);
		mlx_pixel_put(sct->mlx_ptr, sct->win_ptr, sct->tmpx, sct->tmpy,
			change_color(sct->col1, sct->col2, persent));
		sct->tmpx += x_step;
		sct->tmpy += y_step;
	}
}

void	draw_map(t_fdf *sct)
{
	int i;
	int j;

	i = -1;
	while (++i < sct->mx_y - 1)
	{
		j = -1;
		while (++j < sct->mx_x - 1)
		{
			draw_line(j, i, 1, sct);
			draw_line(j, i, 0, sct);
		}
		draw_line(j, i, 1, sct);
	}
	j = -1;
	while (++j < sct->mx_x - 1)
		draw_line(j, i, 0, sct);
	mlx_pixel_put(sct->mlx_ptr, sct->win_ptr, i, j, sct->col[i][j]);
}

void	take_n_put(t_fdf *sct, int y, int x, char *tmp)
{
	int color;

	color = 0xffffff;
	if (y == 15 && x == 95)
		color = 0xcc2222;
	else if (y == 100 && x == 95)
		color = 0x22cc22;
	else if (y == 200 && x == 95)
		color = 0x5555ff;
	mlx_string_put(sct->mlx_ptr, sct->win_ptr, y, x, color, tmp);
	ft_strdel(&tmp);
}

void	draw_menu(t_fdf *sct)
{
	char	*tmp;

	tmp = ft_itoa(sct->zoom);
	take_n_put(sct, 15, 15, ft_strcat(
		ft_strdup("Use '-' or '+' to zoom map. Zoom: x"), tmp));
	ft_strdel(&tmp);
	take_n_put(sct, 15, 35, ft_strdup("Use 'arrows' to move map."));
	take_n_put(sct, 15, 55,
		ft_strdup("Press 'I' to change projection"));
	take_n_put(sct, 15, 75,
		ft_strdup("Press '*' to select color. Then '+' or '-' for change it!"));
	take_n_put(sct, 60, 95, ft_itoa((sct->color >> 16) & 0xff));
	take_n_put(sct, 15, 95, ft_strdup("Red:"));
	take_n_put(sct, 165, 95, ft_itoa((sct->color >> 8) & 0xff));
	take_n_put(sct, 100, 95, ft_strdup("Green:"));
	take_n_put(sct, 260, 95, ft_itoa((sct->color) & 0xff));
	take_n_put(sct, 200, 95, ft_strdup("Blue:"));
	take_n_put(sct, 15, 115,
		ft_strdup("Press 'B' to change white to black!"));
}
