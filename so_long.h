/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:58:57 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/07 12:08:32 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		collect;
	int		exit;
	int		player;
	int		map_true;
	int		fd;
	char	**map_control;
	int		exit_i;
	int		exit_c;
	int		collect_i;
	int		collect_c;
	int		player_i;
	int		player_c;
}t_map;

typedef struct s_mlx
{
	void	*chr;
	void	*l_chr;
	void	*r_chr;
	void	*b_chr;
	void	*ext;
	void	*wall;
	void	*bg;
	void	*coll;
	int		size;
	int		x;
	int		y;
}t_mlx;

typedef struct s_win
{
	t_map	*mapp;
	t_mlx	*mlxx;
	int		width;
	int		height;
	void	*mlx;
	void	*win;
}t_win;

void	read_map(char *maps, t_win *win);
void	wall_control(t_win *win);
void	map_wall_control(t_win *win);
void	map_argv(t_win *win);
void	map_argv_control(t_win *win);
void	ft_error(t_win *win, int a);
void	free_data(t_win *win);
void	argv_control(t_win *win);
void	map_valid_control(t_win *win);
int		ber_control(char *av);

#endif