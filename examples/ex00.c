/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:58:24 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 13:58:27 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

void	eleven_number_checker(const char *str)
{
	int		phone_number;
	int		i;

	if (!str)
		return ;
	phone_number = 0;
	i = 0;
	while (*(str + i))
	{
		if (ft_isdigit(*(str + i)))
		{
			phone_number++;
			if (phone_number == 11)
			{
				write(1, str + i - 10, 11);
				write(1, "\n", 1);
				return ;
			}
		}
		else
			phone_number = 0;
		i++;
	}
	write(1, "KO\n", 3);
	return ;
}

int main(void)
{
	eleven_number_checker("0123456789");
	eleven_number_checker("01234x567890");
	eleven_number_checker("01234567890");
	eleven_number_checker("01234567890  ");
	eleven_number_checker("   01234567890");
	eleven_number_checker("   01234567890   ");
	eleven_number_checker("01234  56789");
	return (0);
}
