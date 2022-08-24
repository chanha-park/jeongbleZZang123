/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:08:16 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 15:42:58 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex.h>
#include <unistd.h>

static void	write_camel(char *str, size_t start, size_t end)
{
	char	c;
	size_t	i;

	i = start;
	while (i < end)
	{
		c = str[i];
		if (i == start)
			c &= (~32);
		write(1, &c, 1);
		i++;
	}
}

static void	convert_snake(regex_t *reg_snake, char *input, regmatch_t *pmatch)
{
	int	offset;
	int	ret;

	offset = 0;
	write(1, "snake pattern\n", 14);
	while (1)
	{
		ret = regexec(reg_snake, input + offset, 2, pmatch, 0);
		if (ret != 0)
			break ;
		write_camel(input + offset, pmatch[1].rm_so, pmatch[1].rm_eo);
		offset += pmatch[1].rm_eo + 1;
	}
	write(1, "\n", 1);
}

void	snake_to_camel(char *input)
{
	regex_t		reg_snake;
	regmatch_t	pmatch[2];
	char		*snake_case;
	int			ret;

	if (!input)
		return ;
	snake_case = "^([a-z]+)(_[a-z]+)*$";
	ret = regcomp(&reg_snake, snake_case, REG_EXTENDED);
	if (ret != 0)
		return ;
	ret = regexec(&reg_snake, input, 2, pmatch, 0);
	if (ret != 0)
	{
		write(1, "not snake case\n", 15);
	}
	else
	{
		convert_snake(&reg_snake, input, pmatch);
	}
	regfree(&reg_snake);
}
