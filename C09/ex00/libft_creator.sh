#!/bin/bash
# libft_creator.sh - compiles the libft source files and builds libft.a

NAME="libft.a"
CC="gcc"
CFLAGS="-Wall -Wextra -Werror"

SRC="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"

# 1. Compile each .c into a .o
echo "Compiling sources..."
for file in $SRC; do
	obj="${file%.c}.o"
	$CC $CFLAGS -c "$file" -o "$obj"
	if [ $? -ne 0 ]; then
		echo "Error compiling $file"
		exit 1
	fi
done

# 2. Archive all .o files into libft.a
echo "Creating $NAME..."
OBJ=$(echo "$SRC" | sed 's/\.c/\.o/g')
ar rcs "$NAME" $OBJ

# 3. Index the archive (usually redundant with 'ar rcs', but explicit for safety/portability)
ranlib "$NAME"

# 4. Clean up object files (optional)
rm -f $OBJ

if [ -f "$NAME" ]; then
	echo "$NAME created successfully."
else
	echo "Failed to create $NAME"
	exit 1
fi
