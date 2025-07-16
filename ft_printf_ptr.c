/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:43:13 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/16 23:44:37 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_count(uintptr_t address)
{
	char	*hex;
	int		i;
	char	buffer[32];
	int		count;

	hex = "0123456789abcdef";
	i = 0;
	if (address == 0)
		return (ft_putchar_fd('0', 1), 1);
	while (address > 0)
	{
		buffer[i] = hex[address % 16];
		address = address / 16;
		i++;
	}
	buffer[i] = '\0';
	count = 0;
	while (i > 0)
	{
		if (write(1, &buffer[i - 1], 1) < 0)
			return (-1);
		count++;
		i--;
	}
	return (count);
}

int	ft_printf_ptr(void *ptr)
{
	int			i;
	int			count;
	uintptr_t	address;

	i = 0;
	if (write(1, "0x", 2) < 0)
		return (-1);
	i += 2;
	address = (uintptr_t)ptr;
	count = get_count(address);
	if (count < 0)
		return (-1);
	i += count;
	return (i);
}

/* int	main(void)
{
	char	*z = "";

	// ft_printf(z);
	// printf("%s", "2");
	ft_printf("%p", z);
	printf("\n%d", ft_printf(" %p", z));
	int a = printf("\n%p", z);
	printf("\n%d", a);
	return (0);
} */
