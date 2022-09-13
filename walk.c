/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:49:09 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/13 11:53:14 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk(t_win *win, int keycode)
{
	if (keycode == 13)
	{
		win->mlxx->chr_pos = win->mlxx->chr_b;
		move_up(win);
	}
	if (keycode == 0)
	{
		win->mlxx->chr_pos = win->mlxx->chr_l;
		move_left(win);
	}
	if (keycode == 1)
	{
		win->mlxx->chr_pos = win->mlxx->chr;
		move_down(win);
	}
	if (keycode == 2)
	{
		win->mlxx->chr_pos = win->mlxx->chr_r;
		move_right(win);
	}
}

void	move_up(t_win *win)
{
	if (win->mapp->map[win->mapp->player_i - 1][win->mapp->player_j] != '1' \
	&& win->mapp->map[win->mapp->player_i - 1][win->mapp->player_j] != 'E')
	{
		if (win->mapp->map[win->mapp->player_i - 1][win->mapp->player_j] == 'C')
			win->mapp->collect--;
		win->mapp->map[win->mapp->player_i - 1][win->mapp->player_j] = 'P';
		win->mapp->map[win->mapp->player_i][win->mapp->player_j] = '0';
		win->mapp->player_i--;
		win->mapp->walk_count++;
		ft_printf("Step : %d\n", win->mapp->walk_count);
	}
	else if (win->mapp->map[win->mapp->player_i - 1] \
	[win->mapp->player_j] == 'E')
	{
		if (win->mapp->collect == 0)
		{
			win->mapp->walk_count++;
			ft_printf("Step : %d\n", win->mapp->walk_count);
			ft_printf("\033[32mYou Win !!!");
			exit(EXIT_SUCCESS);
		}
	}
	mlx_clear_window(win->mlx, win->win);
	map_argv_put(win);
}

void	move_down(t_win *win)
{
	if (win->mapp->map[win->mapp->player_i + 1][win->mapp->player_j] != '1' \
	&& win->mapp->map[win->mapp->player_i + 1][win->mapp->player_j] != 'E')
	{
		if (win->mapp->map[win->mapp->player_i + 1][win->mapp->player_j] == 'C')
			win->mapp->collect--;
		win->mapp->map[win->mapp->player_i + 1][win->mapp->player_j] = 'P';
		win->mapp->map[win->mapp->player_i][win->mapp->player_j] = '0';
		win->mapp->player_i++;
		win->mapp->walk_count++;
		ft_printf("Step : %d\n", win->mapp->walk_count);
	}
	else if (win->mapp->map[win->mapp->player_i + 1] \
	[win->mapp->player_j] == 'E')
	{
		if (win->mapp->collect == 0)
		{
			win->mapp->walk_count++;
			ft_printf("Step : %d\n", win->mapp->walk_count);
			ft_printf("\033[32mYou Win !!!");
			exit(EXIT_SUCCESS);
		}
	}
	mlx_clear_window(win->mlx, win->win);
	map_argv_put(win);
}

void	move_left(t_win *win)
{
	if (win->mapp->map[win->mapp->player_i][win->mapp->player_j - 1] != '1' \
	&& win->mapp->map[win->mapp->player_i][win->mapp->player_j - 1] != 'E')
	{
		if (win->mapp->map[win->mapp->player_i][win->mapp->player_j - 1] == 'C')
			win->mapp->collect--;
		win->mapp->map[win->mapp->player_i][win->mapp->player_j - 1] = 'P';
		win->mapp->map[win->mapp->player_i][win->mapp->player_j] = '0';
		win->mapp->player_j--;
		win->mapp->walk_count++;
		ft_printf("Step : %d\n", win->mapp->walk_count);
	}
	else if (win->mapp->map[win->mapp->player_i] \
	[win->mapp->player_j - 1] == 'E')
	{
		if (win->mapp->collect == 0)
		{
			win->mapp->walk_count++;
			ft_printf("Step : %d\n", win->mapp->walk_count);
			ft_printf("\033[32mYou Win !!!");
			exit(EXIT_SUCCESS);
		}
	}
	mlx_clear_window(win->mlx, win->win);
	map_argv_put(win);
}

void	move_right(t_win *win)
{
	if (win->mapp->map[win->mapp->player_i][win->mapp->player_j + 1] != '1' \
	&& win->mapp->map[win->mapp->player_i][win->mapp->player_j + 1] != 'E')
	{
		if (win->mapp->map[win->mapp->player_i][win->mapp->player_j + 1] == 'C')
			win->mapp->collect--;
		win->mapp->map[win->mapp->player_i][win->mapp->player_j + 1] = 'P';
		win->mapp->map[win->mapp->player_i][win->mapp->player_j] = '0';
		win->mapp->player_j++;
		win->mapp->walk_count++;
		ft_printf("Step : %d\n", win->mapp->walk_count);
	}
	else if (win->mapp->map[win->mapp->player_i] \
	[win->mapp->player_j + 1] == 'E')
	{
		if (win->mapp->collect == 0)
		{
			win->mapp->walk_count++;
			ft_printf("Step : %d\n", win->mapp->walk_count);
			ft_printf("\033[32mYou Win !!!");
			exit(EXIT_SUCCESS);
		}
	}
	mlx_clear_window(win->mlx, win->win);
	map_argv_put(win);
}
