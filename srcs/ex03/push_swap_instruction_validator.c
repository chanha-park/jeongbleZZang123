#include <regex.h>
#include <unistd.h>

void	push_swap_instruction_validator(char *input)
{
	regex_t		reg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			ret;

	if (!input)
		return ;
	pattern = "^(?:(p[a|b])|(r{1,2}[a|b|r])|(s[a|b|s]))\x0a$";
	ret = regcomp(&reg, pattern, REG_EXTENDED);
	if (ret != 0)
		return ;
	ret = regexec(&reg, input, 0, pmatch, 0);
	if (ret != 0)
	{
		write(1, "KO\n", 3);
	}
	else
	{
		write(1, "OK\n", 3);
	}
	regfree(&reg);
}
