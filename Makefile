# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyle <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 11:28:47 by alyle             #+#    #+#              #
#    Updated: 2018/04/04 11:20:11 by alyle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sudoku

LIBNAME = libft.a

GCCFLAGS = -Wall -Wextra -Werror

SRCS = sudoku.c make_sudoku.c solve_sudoku.c valid_insert.c ft_valid_grid.c

OBJ = sudoku.o make_sudoku.o solve_sudoku.o valid_insert.o ft_valid_grid.o

all: $(LIBNAME) $(NAME)

$(NAME):
	@gcc $(GCCFLAGS) -o $(NAME) -L . $(LIBNAME)

$(LIBNAME):
	@gcc $(GCCFLAGS) -c $(SRCS)
	@ar rc $(LIBNAME) $(OBJ)
	@ranlib $(LIBNAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBNAME)

re: fclean all
