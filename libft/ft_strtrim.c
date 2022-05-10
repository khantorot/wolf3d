/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:25:05 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/08 20:25:07 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i])
		i++;
	j = ft_strlen((char *)s) - 1;
	while ((s[j] == '\t' || s[j] == '\n' || s[j] == ' ') && s[j])
		j--;
	if (s[i] == '\0')
	{
		str = ft_strnew(1);
		return (str);
	}
	j = j - i + 1;
	str = ft_strsub(s, i, j);
	return (str);
}
