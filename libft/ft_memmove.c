/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:12:43 by tclarita          #+#    #+#             */
/*   Updated: 2020/03/23 12:06:43 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*src1;

	dest = (char *)dst;
	src1 = (char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			dest[len] = src1[len];
	}
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	return (dst);
}
