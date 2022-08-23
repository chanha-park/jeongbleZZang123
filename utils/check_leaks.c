#include <stdlib.h>

void	check_leaks(void)
{
	system("leaks --quiet $PPID > /dev/null ; echo leaks: $?");
}
