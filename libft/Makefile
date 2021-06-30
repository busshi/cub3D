# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 14:41:14 by aldubar           #+#    #+#              #
#    Updated: 2021/02/18 21:55:38 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_strlen.c \
			ft_strdup.c \
			ft_strdup_nl.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_split.c \
			ft_islower.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isblank.c \
			ft_ischarset.c \
			ft_len_nbr.c \
			ft_print_hex.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strlcpy.c \
			ft_strrev.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c

OBJS		=	$(SRCS:.c=.o)

CC		=	@gcc

CFLAGS		=	-Wall -Wextra -Werror

RM		=	@rm -rf

OK		=	[ \e[0;32mok\e[0m ]

all:		$(NAME)

$(NAME):	$(OBJS)
		@echo "Compiling libft..."
		$(CC) $(CFLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)
		@echo "$(OK) Libft succesfully created."

clean:
		@echo "Cleaning libft objects..."
		$(RM) $(OBJS)

fclean:		clean
		@echo "Removing $(NAME)..."
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
