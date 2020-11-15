/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:20:48 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 13:07:57 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	full_free(t_fdf *sct)
{
	ft_strdel(&sct->line);
	ft_memdel((void **)&sct);
}

void	err_exit(t_fdf *sct, char *msg)
{
	full_free(sct);
	ft_putendl_fd(msg, 2);
	exit(2);
}

void	read_map(t_fdf *sct, char *map)
{
	int		fd;
	int		tmp_x;

	tmp_x = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		err_exit(sct, "Error");
	while ((get_next_line(fd, &sct->line)) > 0)
	{
		if (sct->mx_y++ > 9999)
			err_exit(sct, "Error");
		tmp_x = get_coords(sct, sct->line);
		if (sct->mx_x && tmp_x != sct->mx_x)
			err_exit(sct, "Error");
		else
			sct->mx_x = tmp_x;
		ft_strdel(&sct->line);
	}
	if (!sct->mx_y || !sct->mx_y)
		err_exit(sct, "Error");
	close(fd);
}

int		main(int av, char **ac)
{
	t_fdf *sct;

	if (!(sct = (t_fdf *)malloc(sizeof(t_fdf))))
	{
		ft_putstr_fd("Error", 2);
		exit(2);
	}
	if (av != 2)
		err_exit(sct, "Error");
	initial(sct);
	read_map(sct, ac[1]);
	mlx_main(sct);
	full_free(sct);
	return (0);
}
