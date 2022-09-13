/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:01 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/13 20:52:00 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	score(t_win *win)
{
	win->mapp->count = ft_itoa(win->mapp->walk_count);
	mlx_string_put(win->mlx, win->win, 10, 30, 0x00FF00, "Step : ");
	mlx_string_put(win->mlx, win->win, 70, 30, 0xFFFFFFFF, win->mapp->count);
	free(win->mapp->count);
}

int	ft_key(int keycode, t_win *win)
{
	if (keycode == 53)
		free_data(win);
	else
		walk(win, keycode);
	return (keycode);
}

int	main(int ac, char **av)
{
	t_win	*win;

	if (ac == 2)
	{
		win = ft_calloc(sizeof(t_win), 1);
		win->mapp = ft_calloc(sizeof(t_map), 1);
		win->mlxx = ft_calloc(sizeof(t_mlx), 1);
		win->mapp->walk_count = 0;
		ber_control(av[1], win);
		win->mapp->map = &av[1];
		read_map(av[1], win);
		mlx_put_image(win);
		mlx_hook(win->win, 2, 1L << 0, ft_key, win);
		mlx_hook(win->win, 17, 0, free_data, win);
		mlx_loop(win->mlx);
	}
	else
		ft_printf("\033[31mArgument Error !!!");
}
