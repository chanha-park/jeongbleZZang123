#include <regex.h>
#include <unistd.h>

void eleven_number_checker(const char *str)
{
	regex_t 	preg;
	regmatch_t	pmatch[1];
	char  		*pattern = "[0-9]{11}";

	if (!str)
		return;
	// You should COMPILE pattern string to regex pattern. NOT COMPARE!
	// If successful, regcomp() returns 0. If unsuccessful, regcomp() returns nonzero.
	if (regcomp(&preg, pattern, REG_EXTENDED))
		return;
	// Let's match!!
	//
	// If a match is found, regexec() returns 0.
	// If unsuccessful, regexec() returns nonzero indicating either no match or an error.
	if (!regexec(&preg, str, 1, pmatch, 0))
	{
		// rm_eo is end offset, rm_so is start offset of matched string.
		// so, "pmatch[0].rm_eo - pmatch[0].rm_so" means length of matched string.
		int len = pmatch[0].rm_eo - pmatch[0].rm_so;
		write(1, str + pmatch[0].rm_so, len);
		write(1, "\n", 1);
	}
	else
		write(1, "KO\n", 3);
	// You should free!!!!
	// Frees any memory that was allocated by regcomp() to implement preg.
	regfree(&preg);
}
