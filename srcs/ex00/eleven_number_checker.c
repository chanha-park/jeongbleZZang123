#include <regex.h>
#include <unistd.h>

void	eleven_number_checker(char *input)
{
	regex_t		reg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			ret;

	if (!input)
		return ;
	pattern = "^[0-9]{11}$";
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
