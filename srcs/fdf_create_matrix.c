/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:45:11 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 12:07:59 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_num(t_fdf *sct, char *map, int *i)
{
	int		j;
	int		k;
	int		num;
	char	*tmp;

	j = *i;
	while (map[j] && map[j] != ' ' && map[j] != '\t' && map[j] != ',')
		j++;
	tmp = ft_strsub(map, *i, j - *i);
	num = fdf_atoi(sct, tmp);
	ft_strdel(&tmp);
	if (map[j] == ',')
	{
		k = ++j;
		while (map[j] && map[j] != ' ' && map[j] != '\t')
			j++;
		tmp = ft_strsub(map, k, j - k);
		sct->tmp = fdf_atoi_hex(sct, tmp);
		ft_strdel(&tmp);
	}
	*i = j;
	return (num);
}

int		skip_spaces(char *map, int i)
{
	i--;
	while (map[++i])
		if ((map[i] != ' ') && (map[i] != '\t'))
			break ;
	return (i);
}

int		get_coords(t_fdf *sct, char *map)
{
	int i;
	int *tmp;
	int x;

	i = 0;
	x = 0;
	while (map[i])
	{
		i = skip_spaces(map, i);
		if (map[i])
			x++;
		else
			break ;
		if (x > 9999)
			err_exit(sct, "Error");
		tmp = &sct->mtx[sct->mx_y - 1][x - 1];
		*tmp = get_num(sct, map, &i);
		sct->col[sct->mx_y - 1][x - 1] = (sct->tmp) ? sct->tmp : sct->white;
		sct->tmp = 0;
		if (*tmp > 9999 || *tmp < -9999)
			err_exit(sct, "Error");
		sct->max = (sct->max < *tmp) ? *tmp : sct->max;
		sct->min = (sct->min > *tmp) ? *tmp : sct->min;
	}
	return (x);
}
