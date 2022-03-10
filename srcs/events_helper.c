/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:35:21 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:45:19 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	in_case_p(t_all_data *data, int x, int y)
{
	data->map->data[y][x] = 'P';
	data->map->data[data->mlx->y][data->mlx->x] = '0';
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win, data->img->img,
		data->mlx->x * 64, data->mlx->y * 64);
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win, data->img->img_player, x * 64, y * 64);
}

void	in_case_c(t_all_data *data, int x, int y)
{
	data->map->data[y][x] = 'P';
	data->map->data[data->mlx->y][data->mlx->x] = '0';
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->img->img, data->mlx->x * 64, data->mlx->y * 64);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->img->img_player, x * 64, y * 64);
}

void	end_move(t_all_data *data, int x, int y)
{
	data->mlx->x = x;
	data->mlx->y = y;
	data->mlx->n_steps++;
	ft_printf("number of steps: %d\n", data->mlx->n_steps);
}
