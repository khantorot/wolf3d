/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:46:41 by tclarita          #+#    #+#             */
/*   Updated: 2019/09/07 18:11:46 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isupper11(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_islower11(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int		ft_isalpha(int c)
{
	if (ft_islower11(c) || ft_isupper11(c))
		return (1);
	return (0);
}
