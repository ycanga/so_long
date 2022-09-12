/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:30:03 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/12 12:36:10 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_control(t_win *win, int i, int j)
{
	if (win->mapp->valid_map[i][j] != '1')
	{
		if (win->mapp->valid_map[i][j] != 'E')
		{
			if (win->mapp->valid_map[i][j] == 'C')
				win->mapp->collect_count--;
			win->mapp->valid_map[i][j] = 'x';
			if (win->mapp->valid_map[i][j + 1] != '1' \
			&& win->mapp->valid_map[i][j + 1] != 'x')
				valid_map_control(win, i, j + 1);
			if (win->mapp->valid_map[i][j - 1] != '1' \
			&& win->mapp->valid_map[i][j - 1] != 'x')
				valid_map_control(win, i, j - 1);
			if (win->mapp->valid_map[i + 1][j] != '1' \
			&& win->mapp->valid_map[i + 1][j] != 'x')
				valid_map_control(win, i + 1, j);
			if (win->mapp->valid_map[i - 1][j] != '1' \
			&& win->mapp->valid_map[i - 1][j] != 'x')
				valid_map_control(win, i - 1, j);
		}
		else
			win->mapp->exit_count = 0;
	}
}

void	valid_map_copy(t_win *win, int i, int j)
{
	int	a;

	a = 0;
	while (a < win->mapp->height)
	{	
		win->mapp->valid_map[a] = ft_calloc(ft_strlen(win->mapp->map[a]), 1);
		ft_strlcpy(win->mapp->valid_map[a], \
		win->mapp->map[a], win->mapp->width + 1);
		a++;
	}
	win->mapp->exit_count = win->mapp->exit;
	win->mapp->collect_count = win->mapp->collect;
	valid_map_control(win, i, j);
	if (win->mapp->collect_count != 0 || win->mapp->exit_count != 0)
		ft_error(win, 2);
}

void	argv_env_control_2(t_win *win, int i, int j)
{
	if (win->mapp->map[i - 1][j] == '1' && win->mapp->map[i + 1][j] == '1' \
	&& win->mapp->map[i][j + 1] == '1' && win->mapp->map[i][j - 1] == '1')
	{
		win->mapp->map_true = 0;
		ft_error(win, 2);
	}
	else
		win->mapp->map_true = 1;
}

void	argv_env_control(t_win *win)
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
				argv_env_control_2(win, i, j);
			else if (map[i][j] == 'P')
				argv_env_control_2(win, i, j);
			else if (map[i][j] == 'C')
				argv_env_control_2(win, i, j);
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
	if (win->mapp->collect < 1)
		ft_error(win, 2);
	argv_env_control(win);
	valid_map_copy(win, win->mapp->player_i, win->mapp->player_j);
}
