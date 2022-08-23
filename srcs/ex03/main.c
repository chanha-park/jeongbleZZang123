#include <stdlib.h>

extern void	push_swap_instruction_validator(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	push_swap_instruction_validator(NULL);
	push_swap_instruction_validator("");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	return (0);
}
