#include "main.h"

void	up_dir(int *y, int *x)
{
	(*y)--;
}

void	down_dir(int *y, int *x)
{
	(*y)++;
}

void	left_dir(int *y, int *x)
{
	(*x) -= 2;
}

void	right_dir(int *y, int *x)
{
	(*x) += 2;
}
