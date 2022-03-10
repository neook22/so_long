/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:53:35 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:55:22 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr_unsigned;

	if (n < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * n);
		ft_putchar_fd('-', fd);
	}
	else
		nbr_unsigned = (unsigned int)n;
	if (nbr_unsigned >= 10)
	{
		ft_putnbr_fd(nbr_unsigned / 10, fd);
		ft_putnbr_fd(nbr_unsigned % 10, fd);
	}
	else
		ft_putchar_fd(nbr_unsigned + '0', fd);
}
