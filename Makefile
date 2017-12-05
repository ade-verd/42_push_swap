# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2017/12/05 15:52:48 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Project_Name

SRC_PATH = src
SRC_NAME = main.c\


SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CPPFLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft

CC = gcc
CFLAGS = -Werror -Wall -Wextra

.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rm -Rf $(OBJ_PATH)

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

# **************************************************************************** #
# Personal notes :
#
# $@ : rule's name
# $^ : all dependencies after ':'
# $< : corresponding dependency
# || : if there is an error, execute the command after the double pipe
#
# **************************************************************************** #
