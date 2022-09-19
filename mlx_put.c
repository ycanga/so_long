/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:54:27 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/16 17:46:33 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_image(t_win *win)
{
	int		width;
	int		height;

	if (win->mapp->map_true == 1)
	{
		width = win->mapp->width * 64;
		height = win->mapp->height * 64;
		win->mlx = mlx_init();
		win->win = mlx_new_window(win->mlx, width, height, "Fire and Water");
		map_argv_put(win);
	}
}

void	map_argv_put(t_win *win)
{
	int		i;
	char	**map;
	int		c;
	int		j;

	i = -1;
	c = 0;
	map = win->mapp->map;
	if (!win->mlxx->chr_pos)
		argv_add_st(win);
	while (++i < win->mapp->height)
	{
		j = -1;
		while (++j <= win->mapp->width)
		{
			if (j == win->mapp->width)
			{
				c = c + 64;
				win->mlxx->size_x = 0;
			}
			else
				put_if_else(win, i, j, c);
		}
	}
}

void	argv_add_st(t_win *win)
{
	if (xpm_control() == 1 && xpm_control_2() == 1)
	{
			win->mlxx->wall = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/wall.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->bg = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/bg.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->ext = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/exit.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->chr = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/fire.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->chr_r = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/fire_r.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->chr_l = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/fire_l.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->chr_b = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/fire_b.xpm", &win->mlxx->x, &win->mlxx->y);
			win->mlxx->coll = mlx_xpm_file_to_image(win->mlx, \
		"./xpm/heart.xpm", &win->mlxx->x, &win->mlxx->y);
		win->mlxx->chr_pos = win->mlxx->chr;
	}
	else
	{
		ft_printf("\033[31mXPM File Error. !\n");
		exit(1);
	}
}

void	put_if_else(t_win *win, int i, int j, int c)
{
	char	**map;

	map = win->mapp->map;
	if (map[i][j] == '1')
		put_argv(win, win->mlxx->wall, win->mlxx->size_x, c);
	else if (map[i][j] == '0')
		put_argv(win, win->mlxx->bg, win->mlxx->size_x, c);
	else if (map[i][j] == 'E')
		put_argv(win, win->mlxx->ext, win->mlxx->size_x, c);
	else if (map[i][j] == 'P')
		put_argv(win, win->mlxx->chr_pos, win->mlxx->size_x, c);
	else if (map[i][j] == 'C')
		put_argv(win, win->mlxx->coll, win->mlxx->size_x, c);
	else
		ft_error(win, 0);
}

void	put_argv(t_win *win, void	*argv, int z, int c)
{
	if (argv == win->mlxx->ext || argv == win->mlxx->coll \
	|| argv == win->mlxx->chr_pos)
		mlx_put_image_to_window(win->mlx, win->win, win->mlxx->bg, z, c);
	mlx_put_image_to_window(win->mlx, win->win, argv, z, c);
	score(win);
	win->mlxx->size_x += 64;
}
