/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:03 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/10 21:59:04 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	control(t_win *win)
{
	if (win->mapp->collect_count != 0)
		ft_error(win, 1);
}

void	valid_map_control(t_win *win, int i, int j)
{
	char	*point;

	point = &win->mapp->valid_map[i][j];
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			win->mapp->collect_count--;
		*point = '.';
		if(win->mapp->valid_map[i][j + 1] != '1' && win->mapp->valid_map[i][j + 1] != '.')
			valid_map_control(win, i, j + 1);
		if(win->mapp->valid_map[i][j - 1] != '1' && win->mapp->valid_map[i][j - 1] != '.')
			valid_map_control(win, i, j - 1);
		if(win->mapp->valid_map[i + 1][j] != '1' && win->mapp->valid_map[i + 1][j] != '.')
			valid_map_control(win, i + 1, j);
		if(win->mapp->valid_map[i - 1][j ] != '1' && win->mapp->valid_map[i - 1][j] != '.')
			valid_map_control(win, i - 1, j);
	}
	valid_map_control_2(win, i, j);
}

void	valid_map_control_2(t_win *win, int i, int j)
{
	char	*point;

	ft_printf("%s", &point);
	point = &win->mapp->valid_map[i][j];
	if (*point == 'E')
		win->mapp->map_true = 1;
	if (*point != '1')
	{
		*point = '.';
		if(win->mapp->valid_map[i][j + 1] != '1' && win->mapp->valid_map[i][j + 1] != '.')
			valid_map_control_2(win, i, j + 1);
		if(win->mapp->valid_map[i][j - 1] != '1' && win->mapp->valid_map[i][j - 1] != '.')
			valid_map_control_2(win, i, j - 1);
		if(win->mapp->valid_map[i + 1][j] != '1' && win->mapp->valid_map[i + 1][j] != '.')
			valid_map_control_2(win, i + 1, j);
		if(win->mapp->valid_map[i - 1][j ] != '1' && win->mapp->valid_map[i - 1][j] != '.')
			valid_map_control_2(win, i - 1, j);
	}
	control(win);
}

void	valid_map_copy(t_win *win, int i, int j)
{
	int a;

	a = 0;
	while (a < win->mapp->height)
	{	
		win->mapp->valid_map[a] = ft_calloc(ft_strlen(win->mapp->map[a]), 1);
		ft_strlcpy(win->mapp->valid_map[a], win->mapp->map[a], win->mapp->width + 1);
		a++;
	}
	win->mapp->collect_count = win->mapp->collect;
	valid_map_control(win, i, j);
	
	// if (win->mapp->map[i - 1][j] == '1' && win->mapp->map[i + 1][j] == '1' \
	// && win->mapp->map[i][j + 1] == '1' && win->mapp->map[i][j - 1] == '1')
	// {
	// 	win->mapp->map_true = 0;
	// 	ft_error(win, 0);
	// }
	// else
	// 	win->mapp->map_true = 1;
}

void	map_valid_control(t_win *win)
{
	int		i;
	int		j;
	char	**map;

	map = win->mapp->map;
	i = 0;
	while (i < win->mapp->height)
	{
		j = 0;
		while (j <= win->mapp->width - 1)
		{
			if (map[i][j] == 'E')
				valid_map_copy(win, i, j);
			else if (map[i][j] == 'P')
				valid_map_copy(win, i, j);
			else if (map[i][j] == 'C')
				valid_map_copy(win, i, j);
			j++;
		}
		i++;
	}
}

void	argv_control(t_win *win)
{
	if (win->mapp->player != 1)
		ft_error(win, 2);
	if (win->mapp->exit != 1)
		ft_error(win, 2);
	if (win->mapp->collect < 0)
		ft_error(win, 2);
	map_valid_control(win);
}
