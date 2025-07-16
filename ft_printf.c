/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:13:06 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/16 23:41:52 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	output(va_list	ap, char c)
{
	int	target;

	if (c == 'c')
	{
		target = va_arg(ap, int);
		return (write(1, &target, 1));
	}
	else if (c == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printf_uint(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (-1);
}

int	ft_printf(const char *content, ...)
{
	va_list	ap;
	int		i;
	int		count_args;
	int		temp;

	va_start(ap, content);
	i = 0;
	count_args = 0;
	while (content[i])
	{
		if (content[i] == '%')
			temp = output(ap, content[++i]);
		else
			temp = write(1, &content[i], 1);
		if (temp < 0)
			return (-1);
		count_args += temp;
		i++;
	}
	va_end(ap);
	return (count_args);
}

/* int	main(void)
{
	char	*z = "d";
	// int		a = ft_printf("\001\002\007\v\010\f\r\n");
	int		b = printf("\001\002\007\v\010\f\r\n");

	// printf("%d\n", a);
	printf("%d\n", b);
	// printf("\001\002\007\v\010\f\r\n");
	return (0);
} */
