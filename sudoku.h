/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyle <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:12:37 by alyle             #+#    #+#             */
/*   Updated: 2018/03/25 21:32:26 by alyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

char			**g_sgrid;
int				g_count;
char			**g_solution;

# define TRUE 1
# define FALSE 0

int				valid_row_insert(int i, int j);
int				valid_column_insert(int i, int j);
int				valid_square_insert(int i, int j);
int				valid_insert(int i, int j);
int				ft_success(void);
int				ft_check_grid(int i, int j, char n);
int				ft_solve_sudoku(int i, int j);
void			ft_putchar(char c);
char			**ft_input_line(char *str, char **g_sgrid, int row);
int				ft_valid_input(char **argv);
int				ft_valid_rows(char **g_sgrid, int i, int j);
int				ft_valid_columns(char **g_sgrid, int i, int j);
int				ft_valid_squares(char **g_sgrid, int i, int j);
int				ft_valid_grid(char **g_sgrid);
void			ft_print_grid(char **g_sgrid);
char			**ft_create_grid(char **argv);
char			**ft_initialize(void);
char			**ft_copy(void);

#endif
