/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:30:29 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 14:53:10 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}

void	get_player_pos(t_map *map, t_mlx_data *mlx)
{
	mlx->y = 0;
	while (mlx->y < map->height)
	{
		mlx->x = 0;
		while (mlx->x < map->width)
		{
			if (map->data[mlx->y][mlx->x] == 'P')
				return ;
			mlx->x++;
		}
		mlx->y++;
	}
}

int	close_window(t_all_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	free_map(data->map);
	exit (0);
}

int	events_listener(int key_event, t_all_data *data)
{
	if (key_event == 53)
		close_window(data);
	else if ((key_event == 13 || key_event == 126) && data->map->data
		[data->mlx->y - 1][data->mlx->x] != '1')
	{
		moves(data->mlx->x, data->mlx->y - 1, data);
	}
	else if ((key_event == 0 || key_event == 123) && data->map->data
		[data->mlx->y][data->mlx->x - 1] != '1')
	{
		moves(data->mlx->x - 1, data->mlx->y, data);
	}
	else if ((key_event == 2 || key_event == 124) && data->map->data
		[data->mlx->y][data->mlx->x + 1] != '1')
	{
		moves(data->mlx->x + 1, data->mlx->y, data);
	}
	else if ((key_event == 1 || key_event == 125) && data->map->data
		[data->mlx->y + 1][data->mlx->x] != '1')
	{
		moves(data->mlx->x, data->mlx->y + 1, data);
	}
	return (0);
}

void	moves(int x, int y, t_all_data *data)
{
	data->img->img = mlx_xpm_file_to_image(data->mlx->mlx,
			"./textures/ground.xpm", &data->img->size, &data->img->size);
	data->img->img_player = mlx_xpm_file_to_image(data->mlx->mlx,
			"./textures/player.xpm", &data->img->size, &data->img->size);
	data->img->img_collec = mlx_xpm_file_to_image(data->mlx->mlx,
			"./textures/collec.xpm", &data->img->size, &data->img->size);
	data->img->img_exit = mlx_xpm_file_to_image(data->mlx->mlx,
			"./textures/exit.xpm", &data->img->size, &data->img->size);
	if (data->map->data[y][x] == 'E')
	{
		if (data->map->c_collec == 0)
			close_window(data);
	}
	else
	{
		if (data->map->data[data->mlx->y]
			[data->mlx->x] == 'P' && data->map->data[y][x] != 'C')
			in_case_p(data, x, y);
		else if (data->map->data[y][x] == 'C')
		{
			in_case_c(data, x, y);
			data->map->c_collec--;
		}
		end_move(data, x, y);
	}
}
