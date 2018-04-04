# c_sudoku
Sudoku solving algorithm written in C

Written in conjunction with STautaa and OYang.

Runs using recursive backtracking.

Takes nine lines of nine characters as input.  Valid characters are numbers '1' - '9'and '.' used to represent missing numbers.  Will output the solution As a list of numbers seperated by a single space.  If there is a non-valid entry an "Error" message will be displayed.  Error message will be displayed for inputs having no solution or more than one solution.

To run clone all files into a repository.  Use the Makefile to compile the program using GCC. 

$> `make`

$> `./sudoku "9..8..21." ".5..4...." "..1....7." "41..8..9." "6.2......" ".9......." "...2..4.8" "...41.52." ".....5..1"`

9 3 4 8 6 7 2 1 5

7 5 6 1 4 2 3 8 9

8 2 1 9 5 3 6 7 4

4 1 3 5 8 6 7 9 2

6 8 2 7 9 4 1 5 3

5 9 7 3 2 1 8 4 6

1 7 5 2 3 9 4 6 8

3 6 9 4 1 8 5 2 7

2 4 8 6 7 5 9 3 1

To clean binary file and \*.o files type `make fclean`

Enjoy!!!
