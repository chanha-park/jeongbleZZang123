#include <regex.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

# define N_MATCH 2

void	WriteCamel(char *str, size_t start, size_t end)
{
	char	c;

	for (size_t i = start; i < end; i++)
	{
		c = str[i];
		if (i == start)
			c &= (~' ');
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	int	unused;
	regex_t		reg_snake;
	regmatch_t	pmatch[2];
	char		*snake_case = "^([a-z]+)(_[a-z]+)*$";
	/* char		*CamelCase = "^([A-Z][a-z]*)+$"; */
	char		*str;
	int			ret;
	int			offset = 0;

	if (argc != 2)
		return (1);
	ret = regcomp(&reg_snake, snake_case, REG_EXTENDED);
	if (ret != 0)
		return (1);
	str = argv[1];
	ret = regexec(&reg_snake, str, 2, pmatch, 0);
	if (ret != 0)
	{
		printf("not snake case\n");
	}
	else
	{
		printf("snake pattern\n");
		while (1)
		{
			ret = regexec(&reg_snake, str + offset, 2, pmatch, 0);
			if (ret != 0)
				break ;
			WriteCamel(str + offset, pmatch[1].rm_so, pmatch[1].rm_eo);
			offset += pmatch[1].rm_eo + 1;
		}
	}
	regfree(&reg_snake);
	return (0);
}
