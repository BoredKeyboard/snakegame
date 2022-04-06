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

typedef struct s_body
{
	int	x;
	int	y;
}	t_body;

t_list	*new_body(int x, int y)
{
	t_body	*body = malloc(sizeof(t_body));
	body->x = x;
	body->y = y;
	return (ft_lstnew(body));
}

int	main(void)
{
	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho(); timeout(100);
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	printf("\x1b[?25l");

	int x = 1;
	int y = 1;

	const	t_jump_function *dir_table = get_jump_table();

	int	c;
	int	dir = 'd';

	t_list	*snake = new_body(1, 1);
	ft_lstadd_back(&snake, new_body(2, 1));

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
