/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:58:57 by ycanga            #+#    #+#             */
/*   Updated: 2022/08/29 17:02:47 by ycanga           ###   ########.fr       */
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
	
}t_map;

typedef	struct s_mlx
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

t_win *win;

void	read_map(char *maps);
void	wall_control(void);
void	map_wall_control(void);
void	map_argv(void);

#endif