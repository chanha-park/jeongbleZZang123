# Solution of Ex02.

## Model answer code

```c
#include <sys/types.h>
#include <regex.h>
#include <unistd.h>

void simple_password_validator(const char *str)
{
	regex_t 	preg;
	regmatch_t	pmatch[1];
	char  		*pattern = "^[^42Seoul. ]{8,12}$";
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
```

## Learning Objectives

Learn negation using ^(caret sign).
