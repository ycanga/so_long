/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycanga <ycanga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:52:39 by ycanga            #+#    #+#             */
/*   Updated: 2022/09/07 12:48:30 by ycanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_control(char *av)
{
	int		av_length;

	av_length = ft_strlen(av);
	if (av_length > 4 && av[av_length - 4] == '.' && av[av_length - 3] == 'b' && av[av_length - 2] == 'e' && av[av_length - 1] == 'r')
		return (1);
	else
	{
		ft_printf("\nPlease use only '.ber' files. !\n");
		exit(0);
	}
}

void	ft_error(t_win *win, int a)
{
	if(a == 0)
	{
		ft_printf("Map Error. !\n");
		exit(0);
	}
	if(a == 1)
	{
		ft_printf("Invalid Map Size. !\n");
		exit(0);
	}
	if (a == 2)
	{
		ft_printf("Argument Error. !\n");
		exit(0);
	}
	
	free_data(win);
}

void	free_data(t_win *win)
{
	int y;

	y = 0;
	free(win->mapp);
	free(win->mlxx);
	free(win);
	system("Leaks so_long");
	exit(0);
}
