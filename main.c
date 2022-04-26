#include "main.h"

#define WIDTH 60
#define HEIGHT 30
#define WIN_X_POS 10
#define WIN_Y_POS 5

typedef void	(*t_jump_function)(int *y, int *x);
typedef enum e_dir
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
}				t_dir;

void	do_dir(t_dir dir, int *y, int *x)
{
	const static t_jump_function	dir_table[] = {
	[UP] = up_dir,
	[DOWN] = down_dir,
	[LEFT] = left_dir,
	[RIGHT] = right_dir
	};

	dir_table[dir](y, x);
}

const t_dir	get_dir(int c)
{
	const static t_dir dir_table[] = {
	['w'] = UP,
	['s'] = DOWN,
	['a'] = LEFT,
	['d'] = RIGHT,
	[KEY_UP] = UP,
	[KEY_DOWN] = DOWN,
	[KEY_LEFT] = LEFT,
	[KEY_RIGHT] = RIGHT
	};

	return (dir_table[c]);
}

typedef struct s_body
{
	int	x;
	int	y;
}	t_body;

t_list	*new_body(int x, int y)
{
	t_body	*body;
	body = malloc(sizeof(t_body));

	body->x = x;
	body->y = y;
	return (ft_lstnew(body));
}

void	new_head(t_list **head, int x, int y)
{
	(*head)->next = new_body(x, y);
	*head = (*head)->next;
	mvprintw(y, x, "██");
}

void	del_tail(t_list **snake)
{
	t_body *tail = (t_body *)(*snake)->content;
	attron(COLOR_PAIR(3));
	mvprintw(tail->y, tail->x, "  ");
	attroff(COLOR_PAIR(3));
	ft_lstadvance(snake, free);
}

int	self_collision(t_list *head, t_list *snake)
{
	while (snake != head)
	{
		if (((t_body *)head->content)->x == ((t_body *)snake->content)->x && ((t_body *)head->content)->y == ((t_body *)snake->content)->y)
			return (1);
		snake = snake->next;
	}
	return (0);
}

int	fruit_collision(t_list *head, int fruit_x, int fruit_y)
{
	if (((t_body *)head->content)->x == fruit_x && ((t_body *)head->content)->y == fruit_y)
		return (1);
	return (0);
}

void	newfruit(int *fruit_x, int *fruit_y, t_list *snake)
{
	int	min = 6;
	int	max = 33;
	(*fruit_x) = (rand() % (max + 1 - min) + min) * 2;
	(*fruit_y) = rand() % (max + 1 - min) + min;
	t_list	*real_snake = snake;
	while (snake != NULL)
	{
		if (*fruit_x == ((t_body *)snake->content)->x && *fruit_y == ((t_body *)snake->content)->y)
		{
			newfruit(fruit_x, fruit_y, real_snake);
			return ;
		}
		snake = snake->next;
	}
	attron(COLOR_PAIR(1));
	mvprintw(*fruit_y, *fruit_x, "██");
	attroff(COLOR_PAIR(1));
}

int border_collision(t_list *head)
{
	if (((t_body *)head->content)->x == WIN_X_POS
	|| ((t_body *)head->content)->y == WIN_Y_POS
	|| ((t_body *)head->content)->x == WIN_X_POS + WIDTH - 2
	|| ((t_body *)head->content)->y == WIN_Y_POS + HEIGHT - 1)
		return (1);
	return (0);
}

int	wrap_around(int *x, int *y)
{
	if ((*x) == WIN_X_POS)
	{
		(*x) = WIN_X_POS + WIDTH - 4;
		return (1);
	}
	if ((*y) == WIN_Y_POS)
	{
		(*y) = WIN_Y_POS + HEIGHT - 2;
		return (1);
	}
	if ((*x) == WIN_X_POS + WIDTH - 2)
	{
		(*x) = WIN_X_POS + 2;
		return (1);
	}
	if ((*y) == WIN_Y_POS + HEIGHT - 1)
	{
		(*y) = WIN_Y_POS + 1;
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	initscr(); cbreak(); noecho(); timeout(75);
	nonl(); intrflush(stdscr, FALSE); keypad(stdscr, TRUE);
	WINDOW * win = newwin(HEIGHT, WIDTH, WIN_Y_POS, WIN_X_POS);
	refresh();
	srand(time(NULL));

	// wborder(win, "█", '┃', '-', '-', '+', '+', '+', '+');

	if (has_colors() == FALSE)
	{
		endwin();
		exit(EXIT_SUCCESS);
	}

	int	f = open("HS.txt", O_WRONLY);
	if (f < 0)
	{
		exit(5);
	}
	dprintf(f, "bleh\n");
	close(f);


	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	wbkgd(win, COLOR_PAIR(2));

	box(win, 0, 0);
	wrefresh(win);
	attroff(COLOR_PAIR(2));
	printf("\x1b[?25l");

	int x = 30;
	int y = 15;

	int	score = 0;

	int	fruit_x = 10;
	int	fruit_y = 10;

	int	c;
	t_dir	dir = RIGHT;

	t_list	*snake = NULL;

	int i = 0;
	while (i < 5)		// Starting size of the snake
	{
		ft_lstadd_back(&snake, new_body(x + 2, y));
		attron(COLOR_PAIR(3));
		mvprintw(y, x + 2, "██");
		attroff(COLOR_PAIR(3));
		x += 2;
		i++;
	}

	t_list *head = ft_lstlast(snake);
	newfruit(&fruit_x, &fruit_y, snake);
	while (1)
	{
		c = getch();
		if (c == 'q')
			break ;
		if (self_collision(head, snake))
			break ;
		if (argc == 1 && border_collision(head))
			break ;
		t_dir cdir = get_dir(c);
		if ((cdir == DOWN && dir != UP) ||
			(cdir == UP && dir != DOWN) ||
			(cdir == LEFT && dir != RIGHT) ||
			(cdir == RIGHT && dir != LEFT))
			dir = cdir;
		if (fruit_collision(head, fruit_x, fruit_y))
		{
			newfruit(&fruit_x, &fruit_y, snake);
			score++;
			mvprintw(4, 40, ft_itoa(score));
		}
		else
			del_tail(&snake);
		do_dir(dir, &y, &x);
		if (argc != 1)
			wrap_around(&x, &y);
		new_head(&head, x, y);

	}

	printf("\x1b[?25h");
	endwin();
	return (0);
}


/*
Blijf in directie bewegen totdat er een muur is of nieuwe movement input
Kan elke 4 directies in draaien tenzij er een muur in die directie is
Als een input in de richting van een muur is beweegt pacman pas in die richting als er geen muur meer is (een opening)

*/
