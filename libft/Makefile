# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/07/22 11:32:07 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASCII = ascii/ft_isalpha.c ascii/ft_isdigit.c ascii/ft_isalnum.c \
		ascii/ft_isascii.c ascii/ft_isprint.c ascii/ft_toupper.c \
		ascii/ft_tolower.c ascii/ft_isspace.c

GNL = gnl/get_next_line.c

LISTS = lists/ft_lstnew.c lists/ft_lstadd_front.c lists/ft_lstsize.c \
		lists/ft_lstlast.c lists/ft_lstadd_back.c lists/ft_lstdelone.c \
		lists/ft_lstclear.c lists/ft_lstiter.c lists/ft_lstmap.c

MEMORY = memory/ft_memset.c memory/ft_bzero.c memory/ft_memcpy.c \
		 memory/ft_memmove.c memory/ft_memchr.c memory/ft_memcmp.c \
		 memory/ft_calloc.c 

NUMBERS = numbers/ft_atoi.c numbers/ft_itoa.c numbers/ft_digitcount.c 

PRINTING = printing/ft_putchar.c printing/ft_putstr.c printing/ft_putnbr.c \
		   printing/ft_putuint.c printing/ft_puthex.c printing/ft_putptr.c \
		   printing/ft_putendl_fd.c printing/ft_putnbr_fd.c \
		   printing/ft_putendl_fd.c printing/ft_putnbr_fd.c \
		   printing/ft_putnbr_fd.c printing/ft_printf.c

STRINGS = strings/ft_strlen.c strings/ft_strlcpy.c strings/ft_strlcat.c \
		  strings/ft_strchr.c strings/ft_strrchr.c strings/ft_strncmp.c \
		  strings/ft_strnstr.c strings/ft_strdup.c ft_substr.c \
		  strings/ft_strjoin.c strings/ft_strtrim.c ft_split.c \
		  strings/ft_strmapi.c strings/ft_striteri.c

SOURCES = $(ASCII) $(GNL) $(LISTS) $(MEMORY) $(NUMBERS) $(PRINTING) $(STRINGS)
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
HEADER = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
