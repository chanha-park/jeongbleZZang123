# Solution of Ex01.

## Model answer code

```c
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
```

## Learning Objectives

Learn range pattern matching and expression repetition.
