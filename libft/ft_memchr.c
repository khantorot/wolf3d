/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:42:47 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/08 13:40:37 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str;

	str = (const unsigned char *)s;
	while (n)
	{
		if ((unsigned char)c == *str)
			return ((void *)str);
		n--;
		str++;
	}
	return (NULL);
}
