#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>

void	up_dir(int *y, int *x);
void	down_dir(int *y, int *x);
void	left_dir(int *y, int *x);
void	right_dir(int *y, int *x);

#endif
