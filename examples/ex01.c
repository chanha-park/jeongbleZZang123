#include <sys/types.h>
#include <regex.h>
#include <unistd.h>

void phone_number_checker(const char *str)
{
	regex_t 	preg;
	regmatch_t	pmatch[1];
	char  		*pattern = "010-[0-9]{3,4}-[0-9]{4}";
	int 		len;
	int			index;

	if (!str)
		return ;
	regcomp(&preg, pattern, REG_EXTENDED);
	index = 0;
	while (!regexec(&preg, str + index, 1, pmatch, 0))
	{
		len = pmatch[0].rm_eo - pmatch[0].rm_so;
		write(1, str + index + pmatch[0].rm_so, len);
		write(1, "\n", 1);
		index += pmatch[0].rm_eo;
	}
	if (!index)
		write(1, "KO\n", 3);
	regfree(&preg);
}

int main(void)
{
	phone_number_checker(NULL);
	phone_number_checker("000-0000-0000");
	phone_number_checker("010-0000-0000");
	phone_number_checker("0100000-0000");
	phone_number_checker("010-111-1111");
	phone_number_checker("010-2222-2222010-2222-2222");
	phone_number_checker("010-3333-3333   010-3333-3333");
	phone_number_checker("010-4444-4444   010-4444-4A44");
	phone_number_checker("   010-555-5555   010-5555-5555  ");
	phone_number_checker("abc010-6666-6666defg010-6666-6666hijkl");
	phone_number_checker("010-7777-7010-7777-7777");
	return (0);
}
