#include "main.h"

void	up_dir(int *y, int *x)
{
	(*y)--;
	mvprintw(*y, *x, "██");
}

void	down_dir(int *y, int *x)
{
	(*y)++;
	mvprintw(*y, *x, "██");
}

void	left_dir(int *y, int *x)
{
	(*x) -= 2;
	mvprintw(*y, *x, "██");
}

void	right_dir(int *y, int *x)
{
	(*x) += 2;
	mvprintw(*y, *x, "██");
}
