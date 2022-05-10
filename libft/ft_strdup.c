/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:15:58 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/05 13:37:57 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen((char *)src) + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_strcpy(new_str, (char *)src));
}
