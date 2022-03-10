/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:55:39 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:55:40 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrr(const char *s, int c)
{
	char	*s_bis;

	s_bis = (char *)s;
	while (*s_bis)
	{
		if (*s_bis == (char)c)
			return (1);
		s_bis++;
	}
	if (*s_bis == (char)c)
		return (1);
	return (0);
}
