#include <stdlib.h>

extern void	snake_ToCamel(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	snake_ToCamel("");
	snake_ToCamel(NULL);
	snake_ToCamel("hello");
	snake_ToCamel("hello_");
	snake_ToCamel("_hello");
	snake_ToCamel("_hello_");
	snake_ToCamel("world_hello");
	snake_ToCamel("world_hello  ");
	snake_ToCamel(" world_hello");
	snake_ToCamel("World_hello");
	snake_ToCamel("worLd_hello");
	snake_ToCamel("world__hello");
	snake_ToCamel("foo_bar  world_hello");
	snake_ToCamel("_");
	snake_ToCamel("a_B");
	snake_ToCamel("a_bc_def_ghi");
	snake_ToCamel("worl d_hello");
	snake_ToCamel("world_Hello");
	snake_ToCamel("world_hello\n");
	snake_ToCamel("42_Hello");
	snake_ToCamel("world()_hi");
	return (0);
}
