/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:18:04 by alyle             #+#    #+#             */
/*   Updated: 2018/03/25 16:18:10 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		ft_valid_input(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') ||
					argv[i][j] == '.')
				j++;
			else
				return (FALSE);
		}
		if (j != 9)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		main(int argc, char **argv)
{
	g_count = 0;
	g_solution = ft_initialize();
	if (argc == 10)
	{
		if (!ft_valid_input(argv))
			write(1, "Error\n", 6);
		else
		{
			g_sgrid = ft_create_grid(argv);
			if (!ft_valid_grid(g_sgrid))
				write(1, "Error\n", 6);
			else
			{
				ft_solve_sudoku(0, 0);
				if (g_count != 1)
					write(1, "Error\n", 6);
				else
					ft_print_grid(g_solution);
			}
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
