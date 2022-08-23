#include <stdlib.h>

extern void	eleven_number_checker(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	eleven_number_checker("01012345678");
	eleven_number_checker("0101234o678");
	eleven_number_checker("");
	eleven_number_checker(NULL);
	eleven_number_checker(" 01012345678");
	eleven_number_checker("01012345678 ");
	eleven_number_checker(" 01012345678 ");
	eleven_number_checker("010 1 2 3 4 5 6 7 8");
	eleven_number_checker("12345678901a");
	eleven_number_checker("01011112222\n");
	eleven_number_checker("01022221111\0");
	eleven_number_checker("01022221111\t ");
	return (0);
}
