/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:32:30 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:34:07 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_args(int argc)
{
	if (argc > 2)
	{
		ft_printf("Error\n");
		ft_printf("Too many arguments.\n");
		return (0);
	}
	else if (argc < 2)
	{
		ft_printf("Error\n");
		ft_printf("Too few arguments.\n");
		return (0);
	}
	return (1);
}
