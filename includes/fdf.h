/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 12:10:15 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 13:43:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "mlx.h"
# include <math.h>

typedef struct	s_fdf
{
	int			mx_x;
	int			mx_y;
	int			mtx[10000][10000];
	int			col[10000][10000];
	int			min;
	int			max;
	int			x;
	int			y;
	char		*line;
	int			color_flag;
	int			tmp;
	int			red;
	int			blue;
	int			green;
	int			color;
	int			white;
	int			sel;
	int			col1;
	int			col2;
	int			z1;
	int			z2;
	double		tmpx;
	double		tmpy;
	double		x2;
	double		y2;
	double		sin;
	double		cos;
	int			zoom;
	int			iso;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

int				get_coords(t_fdf *sct, char *map);
void			color_map(t_fdf *sct);
void			bg_map(t_fdf *sct);
int				change_color(int c1, int c2, double persent);
void			initial(t_fdf *sct);
void			mlx_ini(t_fdf *sct);
void			mlx_main(t_fdf *sct);
int				fdf_atoi(t_fdf *sct, const char *str);
void			err_exit(t_fdf *sct, char *msg);
void			full_free(t_fdf *sct);
void			draw(t_fdf *sct);
void			color_key(int key, t_fdf *sct);
void			draw_map(t_fdf *sct);
void			draw_menu(t_fdf *sct);
int				ft_abs(int a);
void			zoom_key(int key, t_fdf *sct);
void			move_key(int key, t_fdf *sct);
void			color_increase(t_fdf *sct, int inc);
int				prs_num(int dx, int dy, int x_st, int y_st);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
void			iso(double *x, double *y, int z, t_fdf *sct);
int				fdf_atoi_hex(t_fdf *sct, const char *str);
#endif
