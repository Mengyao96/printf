/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:43:13 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/15 21:00:06 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_printf_ptr(void *ptr)
{
	uintptr_t	address;
	char		*hex;
	char		buffer[32];
	size_t		i;

	hex = "0123456789abcdef";
	if (ptr == NULL)
		return ;
	address = (uintptr_t) ptr;
	i = 0;
	while (address > 0)
	{
		buffer[i] = hex[address % 16];
		address = address / 16;
		i++;
	}
	buffer[i] = '\0';
	write(1, "0x", 2);
	while (i > 0)
	{
		ft_putchar_fd(buffer[i - 1], 1);
		i--;
	}
	// printf("%s", "12345");
}

/* int	main(void)
{
	char	*z = "d";

	ft_printf_ptr(z);
	printf("\n%p", z);
	return (0);
} */
