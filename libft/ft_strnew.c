/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:38:08 by tclarita          #+#    #+#             */
/*   Updated: 2020/10/22 13:36:22 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	int		i;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
