/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_password_validator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:35 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 14:18:04 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.h>
#include <unistd.h>

void	simple_password_validator(const char *str)
{
	regex_t		preg;
	regmatch_t	pmatch[1];
	char		*pattern;
	int			len;

	if (!str)
		return ;
	pattern = "^[^42Seoul. ]{8,12}$";
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
