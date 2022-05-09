NAME = snake
LIBFT = libft/libft.a

play: $(NAME)
	@./$(NAME)

wrap: $(NAME)
	@./$(NAME) yes do the wrappy thing

$(NAME): main.c dir.c $(LIBFT)
	@gcc main.c dir.c -Ilibft -Llibft -lft -lncurses -o $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

.PHONY: play wrap
