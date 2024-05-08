# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 07:31:49 by lconiau           #+#    #+#              #
#    Updated: 2024/03/20 14:55:46 by lconiau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = pipex

CC      = cc

CFLAGS  = -Wall -Werror -Wextra -g3 -MMD -MP

SRC_PATH = src/

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft/

HEAD    = includes/pipex.h

CFLAGS += -I$(LIBFT_PATH)

LDFLAG = -L$(LIBFT_PATH) -lft


COMMANDS_DIR    =       $(SRC_PATH)child.c \
							$(SRC_PATH)main.c \
                            $(SRC_PATH)handle_error.c \
                            $(SRC_PATH)handle_files.c \
							$(SRC_PATH)handle_free.c \
							$(SRC_PATH)handle_heredoc.c\

GNL_DIR = 	gnl/get_next_line.c \
				gnl/get_next_line_utils.c

SRCS    =       $(COMMANDS_DIR) $(GNL_DIR)

DEPS = $(OBJS:.o=.d) 

all: libs $(NAME)

-include $(DEPS)

$(NAME): $(OBJS) libft/libft.a
		$(CC) $(OBJS) $(LDFLAG) -o $@

libs:
	make -C $(LIBFT_PATH)

clean:
		rm -rf $(OBJS)
		rm -f $(DEPS)
		make -C $(LIBFT_PATH) clean

fclean: clean
		make -C $(LIBFT_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY : all, clean, re, fclean
