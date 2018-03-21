/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:49:04 by ttran             #+#    #+#             */
/*   Updated: 2017/12/21 22:58:50 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_gc = 0;

int		ft_check_buffer(char *str, int br)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	if (br == 21)
		if (str[20] != '\n')
			return (0);
	if (ft_check_characters(str) == 0)
		return (0);
	return (1);
}

/*
** Will check the row and column of the tetrimino
** This function makes sure that there are no irregularly shaped
** tetriminos.
*/

int		ft_check_characters(char *str)
{
	int i;
	int n;
	int count;

	count = 0;
	n = 4;
	i = 0;
	while (n < 21)
	{
		while (i < n)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#')
				count++;
			i++;
		}
		i++;
		n += 5;
	}
	if (count != 4)
		return (0);
	return (1);
}

/*
** Will make sure all the characters within the string are either '#' or '.'
** if it isn't then we know the tetrimino is invalid
*/

int		ft_check_connections(char **str, int y, int x)
{
	int connections;

	connections = 0;
	if (x > 0)
	{
		if (str[y][x - 1] == '#')
			connections++;
	}
	if (x < 3)
	{
		if (str[y][x + 1] == '#')
			connections++;
	}
	if (y > 0)
	{
		if (str[y - 1][x] == '#')
			connections++;
	}
	if (y < 3)
	{
		if (str[y + 1][x] == '#')
			connections++;
	}
	return (connections);
}

/*
** This functions will count up the total numbers of connections that a '#' has.
** This will check the upper, left, right, and bottom position for a '#'.
** Then will return total connections because later we will need
** the total number of connections to validate the tetrimino. For 4
** tetriminos, there has to be 6 or 8 total connections or it will be invalid.
*/

int		ft_setletter(t_tetri *tetri)
{
	if (g_gc == 26)
		return (0);
	tetri->letter = 'A' + g_gc;
	g_gc++;
	return (1);
}

/*
** Sets the character in the struct depending on the position of the Tetrimino.
*/

int		check_valid(t_tetri *tetri, char **store)
{
	int i;
	int n;
	int pounds;
	int connections;

	connections = 0;
	pounds = 0;
	n = -1;
	while (store[++n] != 0)
	{
		i = -1;
		while (store[n][++i] != '\0')
		{
			if (store[n][i] == '#')
			{
				pounds++;
				connections += ft_check_connections(store, n, i);
				ft_min(tetri, n, i, pounds);
				ft_max(tetri, n, i, pounds);
			}
		}
	}
	if (ft_setletter(tetri) == 0 || connections < 6)
		return (0);
	return (1);
}
