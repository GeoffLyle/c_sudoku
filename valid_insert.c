/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 20:44:44 by alyle             #+#    #+#             */
/*   Updated: 2018/03/25 20:59:11 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		valid_row_insert(int i, int j)
{
	int		col;
	int		count;

	col = 0;
	count = 0;
	while (col < 9)
	{
		if (g_sgrid[i][col] == g_sgrid[i][j])
			count++;
		col++;
	}
	if (count == 1)
		return (TRUE);
	return (FALSE);
}

int		valid_column_insert(int i, int j)
{
	int		count;
	int		rows;

	rows = 0;
	count = 0;
	while (rows < 9)
	{
		if (g_sgrid[rows][j] == g_sgrid[i][j])
			count++;
		rows++;
	}
	if (count == 1)
		return (TRUE);
	return (FALSE);
}

int		valid_square_insert(int i, int j)
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

int		valid_insert(int i, int j)
{
	if (!valid_row_insert(i, j))
		return (FALSE);
	if (!valid_column_insert(i, j))
		return (FALSE);
	if (!valid_square_insert(i, j))
		return (FALSE);
	return (TRUE);
}
