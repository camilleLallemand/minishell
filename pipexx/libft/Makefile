# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:23:54 by lconiau           #+#    #+#              #
#    Updated: 2024/03/20 14:54:44 by lconiau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC = ft_atoi.c ft_putnbr_fd.c ft_striteri.c ft_split.c ft_putendl_fd.c ft_putstr_fd.c ft_itoa.c ft_putchar_fd.c ft_strmapi.c  ft_memcmp.c ft_strdup.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_isalpha.c ft_calloc.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_isalnum.c ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c
OBJS	= $(SRC:.c=.o)
CFLAGS	= -Wall -Werror -Wextra
CC	= cc
DEPS= libft.h

BONUS			=	ft_lstadd_back_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstsize_bonus.c
BONUS_OBJS		= $(BONUS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS) $(DEPS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
        
clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)
	rm -f $(BONUS_OBJS)

re: fclean all

bonus:
	$(MAKE) $(NAME) SRC="$(BONUS) $(SRC)"


.PHONY: all clean fclean re bonus