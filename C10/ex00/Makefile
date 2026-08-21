# Create a program called ft_display_file that displays, on the standard output,
# only the content of the file given as argument.

# The submission directory should have a Makefile with the following rules : all,
# clean, fclean. The binary will be called ft_display_file.

NAME	= ft_display_file

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -o

RM	= rm -f

SRC	= display_file.c

OBJ	= $(SRC:.c=.o)

HEADER	= display_file.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(NAME) $(SOURCE) -I $(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
