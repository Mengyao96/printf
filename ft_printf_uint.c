/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:47:09 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/15 20:48:28 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uint(unsigned int num)
{
	size_t	i;
	char	buffer[32];

	i = 0;
	while (num > 0)
	{
		buffer[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	buffer[i] = '\0';
	while (i > 0)
	{
		ft_putchar_fd(buffer[i - 1], 1);
		i--;
	}
}

/* int	main(void)
{
	ft_printf_uint(-123456);
	printf("\n%u", -123456);
	return (0);
} */
