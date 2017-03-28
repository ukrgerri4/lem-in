# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:53:26 by ikryvenk          #+#    #+#              #
#    Updated: 2017/02/07 16:08:49 by ikryvenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
WWW = -Wall -Wextra -Werror -pipe
LIB_PATH = ../libft
LIBFT = $(LIB_PATH)/libft.a

OBJECTS = ft_checkparam.o \
            ft_checkparam_fun.o \
            ft_p_numb.o \
            ft_p_string.o \
            ft_printf.o \
            ft_put_count.o \
            ft_types.o \
            ft_p_wstring.o \
            ft_p_wput_count.o \
            ft_p_wstring2.o

LIB_OBJECTS = $(LIB_PATH)/ft_atoi.o \
            $(LIB_PATH)/ft_bzero.o \
            $(LIB_PATH)/ft_strlen.o \
            $(LIB_PATH)/ft_strdel.o

all: $(NAME)

$(NAME): $(LIB_OBJECTS) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIB_OBJECTS)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	rm -f $(LIB_OBJECTS)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
