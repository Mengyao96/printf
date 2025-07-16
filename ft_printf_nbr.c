/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:42:58 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/16 13:52:19 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbr_to_str(long num)
{
	static char	str[15];
	size_t	i;

	i = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -1 * num;
	}
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_printf_nbr(int n)
{
	long	num;
	char	*str;
	// int		len;

	num = (long)n;
	str = nbr_to_str(num);
	ft_putstr_fd(str, 1);
	if (n < 0)
		return(ft_strlen(str) + 1);
	return (ft_strlen(str));
}

/* int	main(void)
{
	int	n = -2147483648LL; //-2147483648;
	int	b;

	b = ft_printf_nbr(n);
	printf("\n%d", b);
	printf("\n%d", n);

	return (0);
} */
