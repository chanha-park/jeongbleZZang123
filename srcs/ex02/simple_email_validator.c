#include <regex.h>
#include <unistd.h>

void	simple_email_validator(char *input)
{
	regex_t		reg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			ret;

	if (!input)
		return ;
	pattern = "^((?![42seoul])[a-zA-Z0-9])+@[a-zA-Z0-9]+\\.[a-z]{2,3}$";
	ret = regcomp(&reg, pattern, REG_EXTENDED);
	if (ret != 0)
		return ;
	ret = regexec(&reg, input, 1, pmatch, 0);
	if (ret != 0)
	{
		write(1, "KO\n", 3);
	}
	else
	{
		write(1, input + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
		write(1, "\n", 1);
	}
	regfree(&reg);
}
