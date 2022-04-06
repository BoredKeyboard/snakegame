#include "main.h"

typedef void	(*t_jump_function)(int *y, int *x);

const t_jump_function	*get_jump_table(void)
{
	const static t_jump_function	dir_table[] = {
	['w'] = up_dir,
	['s'] = down_dir,
	['a'] = left_dir,
	['d'] = right_dir
	};

	return (dir_table);
}

int	main(void)
{
	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho(); timeout(100);
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	printf("\x1b[?25l");

	int	y = 1;
	int	x = 1;
	const	t_jump_function *dir_table = get_jump_table();

	int	c;
	int	dir = 'd';

	while (1)
	{
		c = getch();

		if ((c == 's' && dir != 'w') ||
			(c == 'w' && dir != 's') ||
			(c == 'a' && dir != 'd') ||
			(c == 'd' && dir != 'a'))
			dir = c;

		dir_table[dir](&y, &x);
	}

	printf("\x1b[?25h");
	endwin();
	return (0);
}

/*



In een array met de posities van elk lichaamsdeel van de snake nemen de
	lichaamsdelen elkaars positie over van achteren naar voren
	Het achterste lichaamsdeel verandert als eerst en het hoofd verandert als laatst


*/
