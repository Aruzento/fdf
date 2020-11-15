/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:02:36 by erandal           #+#    #+#             */
/*   Updated: 2020/11/13 17:04:49 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

int		ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}
