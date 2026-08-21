/*
 * The malloc function is forbidden. You can only do this exercise by declaring a
 * fixed-sized array.
 * 
 */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>

/* Error messages have to be displayed on their reserved output followed by a new
 * line.
 */

# define NO_ARG_MSG "File name missing.\n"
# define MORE_THAN_ONE_MSG "Too many arguments.\n"
# define CANNOT_READ_MSG "Cannot read file.\n"

void	ft_putstr(char *str);

#endif
