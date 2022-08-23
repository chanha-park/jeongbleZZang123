#include <stdlib.h>

extern void	phone_number_checker(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	return (0);
}
