/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:45:23 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/10 14:03:53 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lines(char *file)
{
	int		i;
	int		fd;
	int		ret;
	int		count;
	char	buffer[MAP_LIMIT_WIDTH];

	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = read(fd, buffer, MAP_LIMIT_WIDTH);
	while (ret != 0)
	{
		while (i < ret)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		i = 0;
		ret = read(fd, buffer, MAP_LIMIT_WIDTH);
	}
	close(fd);
	return (count);
}

static int	allocate_map(t_map *map, char *file)
{
	int		fd;
	int		i;

	map->height = count_lines(file);
	if (!map->height)
		return (0);
	map->data = malloc(map->height * sizeof(char *));
	if (!map->data)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		(map->data)[i] = get_next_line(fd);
		if (!((map->data)[i]))
			return (0);
		i++;
	}
	close(fd);
	return (1);
}

int	is_formated(t_map *map, int argc, char **argv)
{
	if (!check_args(argc))
		return (0);
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error\n");
		ft_printf("Wrong extension file\n");
		return (0);
	}
	if (!allocate_map(map, argv[1]))
	{
		ft_printf("Error\n");
		ft_printf("Allocate map failed.\n");
		return (0);
	}
	if (!multiple_checks(map))
		return (0);
	map->width = (int)ft_strlen(map->data[0]) - 1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_map			map;
	t_img			img;
	t_mlx_data		mlx;
	t_all_data		data;

	if (!is_formated(&map, argc, argv))
		return (0);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, map.width * 64,
			map.height * 64, "so_long");
	img.size = 64;
	draw_background(&map, &img, &mlx);
	get_player_pos(&map, &mlx);
	data.mlx = &mlx;
	data.map = &map;
	data.img = &img;
	mlx.n_steps = 0;
	mlx_key_hook(mlx.mlx_win, events_listener, &data);
	mlx_hook(mlx.mlx_win, 17, 0, &close_window, &data);
	mlx_loop(mlx.mlx);
	return (1);
}
