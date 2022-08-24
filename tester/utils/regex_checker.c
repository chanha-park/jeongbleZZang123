/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:44:29 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/25 04:06:31 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	regex_t		preg;
	regmatch_t	pmatch[2];
	char		*pattern;
	char		*string;
	char		errStr[256];
	int			ret;
	int			len;

	if (argc != 3)
	{
		printf("Usage: ./regex_checker PATTERN STRING\n");
		printf("Quote PATTERN using single-quotes\n");
		return (1);
	}
	pattern = argv[1];
	string = argv[2];
	ret = regcomp(&preg, pattern, REG_EXTENDED);
	if (ret != 0)
	{
		regerror(ret, &preg, errStr, sizeof(errStr));
		printf("Regex Compile Error: %s\n", errStr);
		return (1);
	}
	ret = regexec(&preg, string, 1, pmatch, 0);
	if (ret == 0)
	{
		len = pmatch[0].rm_eo - pmatch[0].rm_so;
		printf("Matched Index: %lld %lld\n", pmatch[0].rm_so, pmatch[0].rm_eo);
		printf("Matched String: %.*s\n", len, string + pmatch[0].rm_so);
	}
	else
		printf("Matching Failure\n");
	regfree(&preg);
	return (0);
}
