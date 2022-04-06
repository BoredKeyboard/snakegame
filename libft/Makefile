# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mforstho <mforstho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/12 16:16:58 by mforstho      #+#    #+#                  #
#    Updated: 2022/02/02 15:05:12 by mforstho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS ?= -Wextra -Wall -Werror

include sources.mk

HEADERS := libft.h
OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:c=o))

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))
CFLAGS += $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $^

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
