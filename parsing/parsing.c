/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:55 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:53:49 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(t_map map)
{
	int		i;
	size_t	len_line;

	i = 0;
	len_line = ft_strlen(map.data[0]);
	while (i < map.height)
	{
		if (ft_strlen(map.data[i]) != len_line)
			return (0);
		i++;
	}
	return (1);
}

int	is_in_setchars(t_map map)
{
	int			i;
	int			j;
	const char	components[5] = "10PEC";

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (map.data[i][j])
		{
			if (!ft_strchrr(components, map.data[i][j]))
			{
				if (map.data[i][j] != '\n')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_delimited(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		if (i == 0 || i == map.height - 1)
		{
			if (!contains_only(map.data[i], ft_strlen(map.data[i]), '1'))
				return (0);
		}
		else
		{
			if (map.data[i][0] != '1' || map.data[i]
				[ft_strlen(map.data[i]) - 2] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_chars(t_map *map)
{
	int				i;
	int				j;
	t_check_chars	checkers;

	i = 0;
	checkers.check_c = 0;
	checkers.check_e = 0;
	checkers.check_p = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->data[i][j])
		{
			increase_values(map, &checkers, i, j);
			j++;
		}
		i++;
	}
	if (checkers.check_c == 0 || checkers.check_e == 0 || checkers.check_p == 0)
		return (0);
	if (checkers.check_p > 1)
		return (0);
	map->c_collec = checkers.check_c;
	return (1);
}

int	check_map_limit(t_map map)
{
	if (ft_strlen(map.data
			[0]) > MAP_LIMIT_WIDTH || map.height > MAP_LIMIT_HEIGHT)
		return (0);
	return (1);
}
