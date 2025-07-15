/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:59:28 by mezhang           #+#    #+#             */
/*   Updated: 2025/07/15 17:06:14 by mezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *content, ...);
size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_printf_ptr(void *ptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_printf_uint(unsigned int num);
void	ft_printf_hex(unsigned int num, char c);

#endif
