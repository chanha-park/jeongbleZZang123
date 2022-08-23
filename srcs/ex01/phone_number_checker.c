#include <regex.h>
#include <unistd.h>

void	phone_number_checker(char *input)
{
	regex_t		reg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			ret;

	if (!input)
		return ;
	pattern = "01[0-9]-[0-9]{3,4}-[0-9]{4}";
	ret = regcomp(&reg, pattern, REG_EXTENDED);
	if (ret != 0)
		return ;
	ret = regexec(&reg, input, 1, pmatch, 0);
	if (ret != 0)
		write(1, "KO\n", 3);
	else
	{
		while (1)
		{
			ret = regexec(&reg, input, 1, pmatch, 0);
			if (ret != 0)
				break ;
			write(1, input + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
			input += pmatch[0].rm_eo;
		}
		write(1, "\n", 1);
	}
	regfree(&reg);
}
