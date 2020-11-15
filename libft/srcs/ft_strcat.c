/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:03 by erandal           #+#    #+#             */
/*   Updated: 2020/11/14 13:45:22 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		j;
	char	*res;

	if (!(dest) || (!src))
		return (0);
	res = ft_strnew(ft_strlen(dest) + ft_strlen(src));
	i = -1;
	j = -1;
	while (dest[++i])
		res[i] = dest[i];
	while (src[++j])
		res[i++] = src[j];
	res[i] = '\0';
	ft_strdel(&dest);
	return (res);
}
