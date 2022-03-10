/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:55:53 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/03/07 11:34:02 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# define MAP_LIMIT_WIDTH 40
# define MAP_LIMIT_HEIGHT 20

typedef struct s_map
{
	int		width;
	int		height;
	int		c_collec;
	char	**data;
}				t_map;

typedef struct s_check_chars
{
	int	check_e;
	int	check_p;
	int	check_c;
}				t_check_chars;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		n_steps;
}				t_mlx_data;

typedef struct s_img
{
	void	*img;
	void	*img_player;
	void	*img_collec;
	void	*img_exit;
	int		size;
}				t_img;

typedef struct s_all_data
{
	t_mlx_data		*mlx;
	t_map			*map;
	t_img			*img;
}				t_all_data;

/* parsing */
int		is_rectangular(t_map map);
int		is_in_setchars(t_map map);
int		is_delimited(t_map map);
int		check_chars(t_map *map);
int		check_map_limit(t_map map);

/* parsing helper */
int		contains_only(char *str, int len, int c);
int		check_file_extension(char *str);
void	increase_values(t_map *map, t_check_chars *checkers, int i, int j);
int		multiple_checks(t_map *map);

/* checks_args */
int		check_args(int argc);

/* background */
void	draw_background(t_map *map, t_img *img, t_mlx_data *mlx);

/* events */
void	get_player_pos(t_map *map, t_mlx_data *mlx);
int		close_window(t_all_data *data);
int		events_listener(int key_event, t_all_data *data);
void	moves(int x, int y, t_all_data *data);

/* events helper */
void	in_case_p(t_all_data *data, int x, int y);
void	in_case_c(t_all_data *data, int x, int y);
void	end_move(t_all_data *data, int x, int y);

#endif