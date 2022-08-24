/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction_validator.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:08:13 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 22:52:29 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.h>
#include <unistd.h>

void	push_swap_instruction_validator(const char *str)
{
	regex_t		preg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			len;

	if (!str)
		return ;
	pattern = "^(s[a|b|s]|p[a|b]|r{1,2}[a|b|r])$";
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
