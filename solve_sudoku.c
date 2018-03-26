/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:55 by alyle             #+#    #+#             */
/*   Updated: 2018/03/25 21:32:52 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_check_grid(int i, int j, char n)
{
	g_sgrid[i][j] = n;
	if (valid_insert(i, j))
		return (1);
	g_sgrid[i][j] = '.';
	return (0);
}

char	**ft_copy(void)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		ft_input_line(g_sgrid[i], g_solution, i);
		i++;
	}
	return (g_solution);
}

int		ft_success(void)
{
	if (++g_count >= 2)
		return (1);
	return (0);
}

int		ft_solve_sudoku(int i, int j)
{
	char	n;

	if (i > 8)
	{
		ft_copy();
		return (ft_success());
	}
	else if (g_sgrid[i][j] == '.')
	{
		n = '1';
		while (n <= '9')
		{
			if (ft_check_grid(i, j, n))
			{
				if (ft_solve_sudoku(i + (j + 1) / 9, (j + 1) % 9))
					return (1);
			}
			n++;
		}
		g_sgrid[i][j] = '.';
		return (0);
	}
	else
		return (ft_solve_sudoku(i + (j + 1) / 9, (j + 1) % 9));
}
