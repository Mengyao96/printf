/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:24:16 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/16 14:24:23 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *s)
{
	int	i;

	if (!s)
		return(write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
		i += write(1, &s[i], 1);
	return (i);
}

/* int	main(void)
{
	char	*z = "123456";
	int	b = ft_printf_str(z);

	printf("\n%d", b);
	printf("\n NULL%sNULL ", "123456");
	return (0);
} */
