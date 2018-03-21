/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfill2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:27:20 by ssong             #+#    #+#             */
/*   Updated: 2017/12/21 22:50:17 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_min(t_tetri *tetri, int y, int x, int pound)
{
	if (pound == 1)
	{
		tetri->miny = y;
		tetri->minx = x;
	}
	else
	{
		if (y < tetri->miny)
			tetri->miny = y;
		if (x < tetri->minx)
			tetri->minx = x;
	}
}

void	ft_max(t_tetri *tetri, int y, int x, int pound)
{
	if (pound == 1)
	{
		tetri->maxy = y;
		tetri->maxx = x;
	}
	else
	{
		if (y > tetri->maxy)
			tetri->maxy = y;
		if (x > tetri->maxx)
			tetri->maxx = x;
	}
}

int		open_error(int fd)
{
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (0);
	}
	return (1);
}

int		close_err(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (0);
	}
	return (1);
}
