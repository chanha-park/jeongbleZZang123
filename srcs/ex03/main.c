#include <stdlib.h>

extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	return (0);
}
