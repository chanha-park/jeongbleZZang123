#include <sys/types.h>
#include <regex.h>
#include <unistd.h>

void pushswap_instruction_validator(const char *str)
{
	regex_t 	preg;
	regmatch_t	pmatch[1];
	char  		*pattern = "^(s[a|b|s]|p[a|b]|r{1,2}[a|b|r])$";
	int 		len;

	if (!str)
		return ;
	regcomp(&preg, pattern, REG_EXTENDED);
	if (!regexec(&preg, str, 1, pmatch, 0))
	{
		len = pmatch[0].rm_eo - pmatch[0].rm_so;
		write(1, str + pmatch[0].rm_so, len);
		write(1, "\n", 1);
	}
	else
		write(1, "KO\n", 3);
	regfree(&preg);
}

int main(void)
{
	pushswap_instruction_validator(NULL);
	pushswap_instruction_validator("sa");
	pushswap_instruction_validator("pb");
	pushswap_instruction_validator("rrr");
	pushswap_instruction_validator("    sa  ");
	pushswap_instruction_validator("pp");
	pushswap_instruction_validator("aa");
	pushswap_instruction_validator("sr");
	pushswap_instruction_validator("SR");
	return (0);
}
