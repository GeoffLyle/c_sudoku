/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sudoku.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stautuaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:46:35 by stautuaa          #+#    #+#             */
/*   Updated: 2018/03/25 16:21:30 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	**ft_initialize(void)
{
	char	**array;
	int		i;

	array = malloc(81);
	i = 0;
	while (i < 9)
	{
		array[i] = malloc(9);
		i++;
	}
	return (array);
}

char	**ft_input_line(char *str, char **g_sgrid, int row)
{
	int		i;

	i = 0;
	while (str[i])
	{
		g_sgrid[row][i] = str[i];
		i++;
	}
	return (g_sgrid);
}

char	**ft_create_grid(char **argv)
{
	char	**g_sgrid;
	int		i;

	g_sgrid = ft_initialize();
	i = 1;
	while (i <= 9)
	{
		ft_input_line(argv[i], g_sgrid, i - 1);
		i++;
	}
	return (g_sgrid);
}

void	ft_print_grid(char **g_sgrid)
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(g_sgrid[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
