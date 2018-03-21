/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocgrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:01:30 by ssong             #+#    #+#             */
/*   Updated: 2017/12/21 22:15:37 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**malloc_grid(int size)
{
	int		i;
	int		y;
	char	**grid;

	y = 0;
	i = 0;
	grid = (char**)malloc((sizeof(char*) * size + 1));
	grid[size] = 0;
	while (i != size)
	{
		grid[i] = (char*)malloc(sizeof(char) * size + 1);
		y = 0;
		while (y < size)
		{
			grid[i][y] = '.';
			y++;
		}
		grid[i][y] = 0;
		i++;
	}
	return (grid);
}

/*
** 1. mallocs the grid
** 2. sets all coordinates withtin the grid to '.'
*/

int		more_tetri(t_tetri *tetri)
{
	t_tetri *tmp;

	tmp = tetri;
	while (tmp != 0)
	{
		if (tmp->flag == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
** checks to see if there are any more unused tetriminos
** If there aren't then SUCCESS!!
*/

void	re_zero(t_tetri *tetri)
{
	t_tetri *tmp;

	tmp = tetri;
	while (tmp != NULL)
	{
		if (tmp->flag == 1)
			tmp->flag = 0;
		tmp = tmp->next;
	}
}

void	set_flags(t_tetri *tetri)
{
	t_tetri *tmp;

	tmp = tetri;
	while (tmp != NULL)
	{
		tmp->flag = 0;
		tmp = tmp->next;
	}
}

/*
** the value flags in each struct indicates whether a
** tetrimino has been used in the recursive backtracking
** I am setting everything to Zero as an initiation.
*/

int		find_locat(char **grid, int *x, int *y)
{
	while ((*y) < g_size)
	{
		while ((*x) < g_size)
		{
			if (grid[*y][*x] == '.')
				return (1);
			(*x)++;
		}
		*x = 0;
		(*y)++;
	}
	return (0);
}

/*
** xy[0] == 'y' and xy[1] == 'x'. I had to do this cause when I use
** the function check_location() I need to pass more the 4 arguments.
** The Flag is used to identify whether the Tetrimino has been used already.
*/
