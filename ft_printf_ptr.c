/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:43:13 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/16 14:31:05 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf_ptr(void *ptr)
{
	uintptr_t	address;
	char		*hex;
	char		buffer[32];
	size_t		i;

	hex = "0123456789abcdef";
	address = (uintptr_t) ptr;
	i = 0;
	if (address == 0 || ptr == NULL)
		buffer[i++] = '0';
	while (address > 0)
	{
		buffer[i++] = hex[address % 16];
		address = address / 16;
	}
	buffer[i] = '\0';
	write(1, "0x", 2);
	while (i > 0)
	{
		ft_putchar_fd(buffer[--i], 1);
	}
	return (ft_strlen(buffer) + 2);
}

/* int	main(void)
{
	char	*z = 0;
	int	b = ft_printf_ptr(z);

	printf("\n%d", b);
	printf(" %p %p ", NULL, (void *)0);
	return (0);
} */
