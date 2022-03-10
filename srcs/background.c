/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:45:45 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 10:48:39 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_background_helper(t_map *map, t_img *img, t_mlx_data *mlx)
{
	if (map->data[mlx->y][mlx->x] == '1')
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/wall.xpm", &img->size, &img->size);
	if (map->data[mlx->y][mlx->x] == '0')
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/ground.xpm", &img->size, &img->size);
	if (map->data[mlx->y][mlx->x] == 'C')
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/collectible.xpm", &img->size, &img->size);
	if (map->data[mlx->y][mlx->x] == 'E')
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/exit.xpm", &img->size, &img->size);
	if (map->data[mlx->y][mlx->x] == 'P')
	{
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/ground.xpm", &img->size, &img->size);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			img->img, mlx->x * 64, mlx->y * 64);
		img->img = mlx_xpm_file_to_image(mlx->mlx,
				"./textures/player.xpm", &img->size, &img->size);
	}
}

void	draw_background(t_map *map, t_img *img, t_mlx_data *mlx)
{
	mlx->y = 0;
	while (mlx->y < map->height)
	{
		mlx->x = 0;
		while (mlx->x < map->width)
		{
			draw_background_helper(map, img, mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				img->img, mlx->x * 64, mlx->y * 64);
			mlx->x++;
		}
		mlx->y++;
	}
}
