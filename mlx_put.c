/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:54:27 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/10 13:08:22 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_argv(t_win *win, void	*argv, int z, int c)
{
	if (argv == win->mlxx->ext || argv == win->mlxx->coll \
	|| argv == win->mlxx->chr)
	{
		mlx_put_image_to_window(win->mlx, \
		win->bg, argv, z, c);
		mlx_put_image_to_window(win->mlx, \
		win->win, argv, z, c);
		win->mlxx->size_x += 64;
	}
	else
	{
		mlx_put_image_to_window(win->mlx, \
		win->win, argv, z, c);
		win->mlxx->size_x += 64;
	}
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
	win->mlxx->coll = mlx_xpm_file_to_image(win->mlx, \
"./xpm/heart.xpm", &win->mlxx->x, &win->mlxx->y);
}

void	map_argv_put(t_win *win)
{
	int		i;
	int		j;
	char	**map;
	void	*bg;
	// int		z;
	int		c;

	bg = win->mlxx->bg;
	j = 0;
	win->mlxx->size_x = 0;
	c = 0;
	argv_add_st(win);
	map = win->mapp->map;
	i = 0;
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
			{
				if (map[i][j] == '1')
					put_argv(win, win->mlxx->wall, bg, win->mlxx->size_x);
				else if (map[i][j] == '0')
					put_argv(win, win->mlxx->bg, bg, win->mlxx->size_x);
				else if (map[i][j] == 'E')
				{
					put_argv(win, win->mlxx->bg, bg, win->mlxx->size_x, c);
					put_argv(win, win->mlxx->ext, , win->mlxx->size_x, c);
				}
				else if (map[i][j] == 'P')
				{
					mlx_put_image_to_window(win->mlx, \
					win->win, win->mlxx->bg, win->mlxx->size_x, c);
					mlx_put_image_to_window(win->mlx, \
					win->win, win->mlxx->chr,win->mlxx->size_x, c);
					win->mlxx->size_x = win->mlxx->size_x + 64;
				}
				else if (map[i][j] == 'C')
				{
					mlx_put_image_to_window(win->mlx, \
					win->win, win->mlxx->bg, win->mlxx->size_x, c);
					mlx_put_image_to_window(win->mlx, \
					win->win, win->mlxx->coll, win->mlxx->size_x, c);
					win->mlxx->size_x = win->mlxx->size_x + 64;
				}
			}
			j++;
		}
		i++;
	}	
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
		mlx_loop(win->mlx);
	}
}