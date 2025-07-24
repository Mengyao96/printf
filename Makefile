# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 17:07:22 by mezhang           #+#    #+#              #
#    Updated: 2025/07/22 16:43:10 by mezhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft/

SRCS = ft_printf.c \
		ft_printf_hex.c \
		ft_printf_nbr.c \
		ft_printf_ptr.c \
		ft_printf_str.c \
		ft_printf_uint.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C ./libft
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
