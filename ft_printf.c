/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:13:06 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/15 21:09:47 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int	in_set(char c)
{
	char	*set;

	set = "cspdiuxX%";
	while (*set)
	{
		if (*set == 'c')
			return (1);
		set++;
	}
	return (0);
}

static void	output (va_list	ap, char c)
{
	if (in_set(c) == 0)
		return ;
	if	(c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
		ft_printf_ptr(va_arg(ap, void *)); // convert to uintptr_t
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_printf_uint(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_printf_hex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *content, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, content);
	i = 0;
	while (content[i])
	{
		if (content[i] == '%')
		{
			i++;
			// if (content[i] == '%') // 是否要定义当个 “&” 出现在末尾的现象？
			// 	return (0);
			output(ap, content[i]);
		}
		else
			ft_putchar_fd(content[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char	*z = "d";

	ft_printf("=== %p ----%d*** %i===%x++++%s~~", z, 123, 456, 1212, "idk" );
	printf("\n=== %p ----%d*** %i===%x++++%s~~", z, 123, 456, 1212, "idk" ); //warning: incomplete format specifier [-Wformat]
	return (0);
}
