/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:12:50 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/05 16:18:07 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*cur;

	cur = s1;
	while (*cur != '\0')
	{
		cur++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*cur = *s2;
		cur++;
		s2++;
		n--;
	}
	*cur = '\0';
	return (s1);
}
