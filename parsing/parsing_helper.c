/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:53 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:32:01 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	contains_only(char *str, int len, int c)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	check_file_extension(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchrr(str, '.'))
		return (0);
	while (str[i] != '.')
		i++;
	if (!(str[i + 1] == 'b' && str[i + 2] == 'e' && str
			[i + 3] == 'r' && str[i + 4] == '\0'))
		return (0);
	return (1);
}

void	increase_values(t_map *map, t_check_chars *checkers, int i, int j)
{
	if (map->data[i][j] == 'C')
		checkers->check_c++;
	else if (map->data[i][j] == 'E')
		checkers->check_e++;
	else if (map->data[i][j] == 'P')
		checkers->check_p++;
}

int	multiple_checks2(t_map *map)
{
	if (!check_map_limit(*map))
	{
		ft_printf("Error\n");
		ft_printf("The map size is too big.\n");
		return (0);
	}
	if (!is_rectangular(*map))
	{
		ft_printf("Error\n");
		ft_printf("The map isn't rectangular.\n");
		return (0);
	}
	return (1);
}

int	multiple_checks(t_map *map)
{
	if (!multiple_checks2(map))
		return (0);
	if (!is_in_setchars(*map))
	{
		ft_printf("Error\n");
		ft_printf("There is wrong characters in the map.\n");
		return (0);
	}
	if (!is_delimited(*map))
	{
		ft_printf("Error\n");
		ft_printf("There map isn't delimited.\n");
		return (0);
	}
	if (!check_chars(map))
	{
		ft_printf("Error\n");
		ft_printf("Some characters are missing ");
		ft_printf("or there are multiple players in the map.\n");
		return (0);
	}
	return (1);
}
