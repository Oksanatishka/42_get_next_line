/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:55:36 by obibik            #+#    #+#             */
/*   Updated: 2018/08/22 16:55:38 by obibik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character c to the standard output.
** Param. #1 The character to output.
** Return value None.
** Libc functions write(2).
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** int main () {
**     char letter = 'A';
**     ft_putchar(letter);
**     return(0);
** }
*/
