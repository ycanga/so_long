/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:58:57 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/16 17:33:38 by ycanga           ###   ########.fr       */
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
	char	**valid_map;
	int		collect;
	int		exit;
	int		player;
	int		map_true;
	int		fd;
	int		collect_count;
	int		exit_count;
	char	*count;
	int		walk_count;
	int		player_i;
	int		player_j;
}t_map;

typedef struct s_mlx
{
	void	*chr_pos;
	void	*chr;
	void	*chr_r;
	void	*chr_l;
	void	*chr_b;
	void	*ext;
	void	*wall;
	void	*bg;
	void	*coll;
	int		size_x;
	int		size_y;
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
int		free_data(t_win *win);
void	argv_control(t_win *win);
void	argv_env_control_2(t_win *win, int i, int j);
void	argv_env_control(t_win *win);
void	ber_control(char *av, t_win *win);
void	mlx_put_image(t_win *win);
void	map_argv_put(t_win *win);
void	put_if_else(t_win *win, int i, int j, int c);
int		ft_key(int keycode, t_win *win);
void	valid_map_copy(t_win *win, int i, int j);
void	valid_map_control(t_win *win, int i, int j);
void	valid_map_control_2(t_win *win, int i, int j);
void	put_argv(t_win *win, void	*argv, int z, int c);
void	walk(t_win *win, int keycode);
void	move_up(t_win *win);
void	move_down(t_win *win);
void	move_left(t_win *win);
void	move_right(t_win *win);
int		xpm_control(void);
int		xpm_control_2(void);
void	score(t_win *win);
void	argv_add_st(t_win *win);

#endif