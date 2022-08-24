/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:42:39 by chanhpar          #+#    #+#             */
/*   Updated: 2022/08/24 10:42:41 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern void	push_swap_instruction_validator(char *input);
extern void	check_leaks(void);

int	main(void)
{
	atexit(check_leaks);
	push_swap_instruction_validator(NULL);
	push_swap_instruction_validator("");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	push_swap_instruction_validator("pa\n");
	return (0);
}
