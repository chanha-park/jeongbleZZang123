/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_number_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:28 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/25 08:11:31 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.h>
#include <unistd.h>

void	phone_number_checker(const char *str)
{
	regex_t		preg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			len;
	int			index;

	if (!str)
		return ;
	pattern = "010-[0-9]{3,4}-[0-9]{4}";
	regcomp(&preg, pattern, REG_EXTENDED);
	index = 0;
	if (!regexec(&preg, str + index, 1, pmatch, 0))
	{
		len = pmatch[0].rm_eo - pmatch[0].rm_so;
		write(1, str + index + pmatch[0].rm_so, len);
		write(1, "\n", 1);
		index += pmatch[0].rm_eo;
	}
	else
		write(1, "KO\n", 3);
	regfree(&preg);
}
