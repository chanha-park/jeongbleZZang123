#include <stdlib.h>

extern void	phone_number_checker(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	phone_number_checker(NULL);
	phone_number_checker("");
	phone_number_checker("010-1234-5678");
	phone_number_checker("010-12a4-5678");
	phone_number_checker("010-1234-5678   010-888-7777");
	return (0);
}
