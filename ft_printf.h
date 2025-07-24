/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:59:28 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/24 10:05:30 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if defined(__linux__)
#  define NULLPTR "(nil)"
#  define NULLPTR_LEN 5
# elif defined(__APPLE__)
#  define NULLPTR "0x0"
#  define NULLPTR_LEN 3
# endif

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
// # include <limits.h>

int		ft_printf(const char *content, ...);
size_t	ft_strlen(const char *s);

int		ft_printf_str(char *s);
int		ft_printf_ptr(void *ptr);
int		ft_printf_nbr(int n);
int		ft_printf_uint(unsigned int num);
int		ft_printf_hex(int num, char c);

#endif
