/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:54:27 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/12 13:09:04 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_argv(t_win *win, void	*argv, int z, int c)
{
	if (argv == win->mlxx->ext || argv == win->mlxx->coll \
	|| argv == win->mlxx->chr || \
	argv == win->mlxx->chr_r || argv == win->mlxx->chr_l \
	|| argv == win->mlxx->chr_b)
		mlx_put_image_to_window(win->mlx, win->win, win->mlxx->bg, z, c);
	mlx_put_image_to_window(win->mlx, win->win, argv, z, c);
	win->mlxx->size_x += 64;
}

void	argv_add_st(t_win *win)
{
	win->mlxx->x = 64;
	win->mlxx->y = 64;
	win->mlxx->wall = mlx_xpm_file_to_image(win->mlx, \
"./xpm/wall.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->bg = mlx_xpm_file_to_image(win->mlx, \
"./xpm/bg.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->ext = mlx_xpm_file_to_image(win->mlx, \
"./xpm/su.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->chr = mlx_xpm_file_to_image(win->mlx, \
"./xpm/ates.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->chr_r = mlx_xpm_file_to_image(win->mlx, \
"./xpm/ates.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->chr_l = mlx_xpm_file_to_image(win->mlx, \
"./xpm/ates.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->chr_b = mlx_xpm_file_to_image(win->mlx, \
"./xpm/ates.xpm", &win->mlxx->x, &win->mlxx->y);
	win->mlxx->coll = mlx_xpm_file_to_image(win->mlx, \
"./xpm/heart.xpm", &win->mlxx->x, &win->mlxx->y);
}

void	map_argv_put(t_win *win) // buraya yollanacak yeni map
{
	int		i;
	char	**map;
	int		c;
	int		j;

	i = 0;
	c = 0;
	argv_add_st(win);
	map = win->mapp->map;
	while (i < win->mapp->height)
	{
		j = 0;
		while (j <= win->mapp->width)
		{
			if (j == win->mapp->width)
			{
				c = c + 64;
				win->mlxx->size_x = 0;
			}
			else
				put_if_else(win, i, j, c);
			j++;
		}
		i++;
	}	
}

void	put_if_else(t_win *win, int i, int j, int c)
{
	char	**map;

	win->mlxx->chr_pos = win->mlxx->chr;
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
}

void	mlx_put_image(t_win *win)
{
	int		width;
	int		height;

	if (win->mapp->map_true == 1)
	{
		win->mlx = mlx_init();
		width = win->mapp->width * 64;
		height = win->mapp->height * 64;
		win->win = mlx_new_window(win->mlx, width, height, "Ates ve Su");
		map_argv_put(win);
	}
}
