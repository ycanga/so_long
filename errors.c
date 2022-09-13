/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:52:39 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/13 21:27:37 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_control(char *av, t_win *win)
{
	int	i;

	i = ft_strlen(av);
	if (i < 5 || (av[i - 1] != 'r' && av[i - 2] != 'e' && av[i - 3] != 'b' \
	&& av[i - 4] != '.'))
		ft_error(win, 4);
}

void	ft_error(t_win *win, int a)
{
	if (a == 0)
		ft_printf("\033[31mMap Error. !\n");
	if (a == 1)
		ft_printf("\033[31mInvalid Map Size. !\n");
	if (a == 2)
		ft_printf("\033[31mArgument Error. !\n");
	if (a == 3)
		ft_printf("\033[31mValid Map Error. !\n");
	if (a == 4)
		ft_printf("\n\033[31mPlease use only '.ber' files. !\n");
	if (a == 7)
		ft_printf("\033[31mFile Not Found. !\n");	
	free_data(win);
	exit(EXIT_FAILURE);
}

void	free_data_2(t_win *win)
{
	mlx_destroy_image(win->mlx, win->mlxx->chr);
	mlx_destroy_image(win->mlx, win->mlxx->chr_r);
	mlx_destroy_image(win->mlx, win->mlxx->chr_l);
	mlx_destroy_image(win->mlx, win->mlxx->chr_b);
	mlx_destroy_image(win->mlx, win->mlxx->bg);
	mlx_destroy_image(win->mlx, win->mlxx->wall);
	mlx_destroy_image(win->mlx, win->mlxx->ext);
	mlx_destroy_image(win->mlx, win->mlxx->coll);
}

int	free_data(t_win *win)
{
	int	i;

	i = 0;
	while (i < win->mapp->height)
	{
		free(win->mapp->map[i]);
		free(win->mapp->valid_map[i]);
		i++;
	}
	free(win->mapp->valid_map);
	free(win->mapp);
	if (win->mlx)
	{
		free_data_2(win);
		mlx_destroy_window(win->mlx, win->win);
		free(win->mlxx);
	}
	free(win);
	exit(EXIT_SUCCESS);
	return (0);
}
