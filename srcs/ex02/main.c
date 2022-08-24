/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:32 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 10:42:32 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern void	simple_email_validator(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	simple_email_validator(NULL);
	simple_email_validator("");
	simple_email_validator("john@ljEfj3.ke");
	simple_email_validator("john@ljEfj3.ke");
	simple_email_validator("john@ljEfj3.ke");
	simple_email_validator("john@ljEfj3.ke");
	simple_email_validator("john@ljEfj3.ke");
	return (0);
}
