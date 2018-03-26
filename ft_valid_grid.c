/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stautuaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:33:19 by stautuaa          #+#    #+#             */
/*   Updated: 2018/03/25 16:27:36 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_valid_rows(char **g_sgrid, int i, int j)
{
	int		seek;

	seek = j + 1;
	while (seek < 9)
	{
		if (g_sgrid[i][seek] == g_sgrid[i][j])
			return (FALSE);
		seek++;
	}
	return (TRUE);
}

int		ft_valid_columns(char **g_sgrid, int i, int j)
{
	char	c;
	int		rows;

	c = g_sgrid[i][j];
	rows = i + 1;
	while (rows < 9)
	{
		if (g_sgrid[rows][j] == c)
		{
			return (FALSE);
		}
		rows++;
	}
	return (TRUE);
}

int		ft_valid_squares(char **g_sgrid, int i, int j)
{
	int		row;
	int		col;
	int		count;

	count = 0;
	row = (i / 3) * 3;
	while (row < (i / 3 + 1) * 3)
	{
		col = (j / 3) * 3;
		while (col < (j / 3 + 1) * 3)
		{
			if (g_sgrid[row][col] == g_sgrid[i][j])
				count++;
			col++;
		}
		row++;
	}
	if (count != 1)
	{
		return (FALSE);
	}
	return (TRUE);
}

int		ft_valid_grid(char **g_sgrid)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (g_sgrid[i][j] == '-')
				return (FALSE);
			if (g_sgrid[i][j] >= '0' && g_sgrid[i][j] <= '9')
			{
				if (!ft_valid_rows(g_sgrid, i, j))
					return (FALSE);
				if (!ft_valid_columns(g_sgrid, i, j))
					return (FALSE);
				if (!ft_valid_squares(g_sgrid, i, j))
					return (FALSE);
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}
