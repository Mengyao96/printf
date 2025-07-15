/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:13:41 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/15 20:41:23 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lower_hex(unsigned int num)
{
	char	*hex;
	size_t	i;
	char	buffer[32];

	hex = "0123456789abcdef";
	i = 0;
	while (num > 0)
	{
		buffer[i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	buffer[i] = '\0';
	while (i > 0)
	{
		ft_putchar_fd(buffer[i - 1], 1);
		i--;
	}
}

void	upper_hex(unsigned int num)
{
	char	*hex;
	size_t	i;
	char	buffer[32];

	hex = "0123456789ABCDEF";
	i = 0;
	while (num > 0)
	{
		buffer[i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	buffer[i] = '\0';
	while (i > 0)
	{
		ft_putchar_fd(buffer[i - 1], 1);
		i--;
	}
}

void	ft_printf_hex(unsigned int num, char c)
{
	if (c == 'x')
		lower_hex(num);
	else
		upper_hex(num);
}

/* int	main(void)
{
	ft_printf_hex(-255, 'X');
	printf("\n%X", -255);
	return (0);
} */
