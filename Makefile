# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2017/12/15 10:45:34 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = NewProjectName

SRC_PATH = ./
SRC_NAME = main.c\
		#

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -I$(INC_PATH) -Ilibft/includes
LDFLAGS = -Llibft
LDLIBS = -lft
LIB_PATH = libft
INC_PATH = ./

OS = $(shell uname)
ifeq ($(OS), Darwin)
	CC := gcc
	CFLAGS += -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	ifeq (, $(shell which clang))
		CC := gcc
	else
		CC := clang
	endif
	CFLAGS += -Wno-unused-result
endif

#Colors font
C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)
ERROR = $(C_ERROR)ERROR$(C_NO)
WARNING = $(C_WARN)WARNING$(C_NO)

#Rules
.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): obj $(OBJ) lib
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "Compiling -> " $(NAME) $(SUCCESS)

lib:
	@make -C $(LIB_PATH)

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Linking -> " $< $(DONE)

clean:
	@rm -f $(OBJ)
	@rm -Rf $(OBJ_PATH)
	@echo "Cleaning all $(NAME)'s objects -> " $(SUCCESS)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) clean_only_lib
	@echo "Deleting -> " $(NAME) $(SUCCESS)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

test:
	@echo $(OS)
	@echo $(CC)
	@echo $(CFLAGS)

# **************************************************************************** #
# Personal notes :
#
# $@ : rule's name
# $^ : all dependencies after ':'
# $< : corresponding dependency
# || : if there is an error, execute the command after the double pipe
#
# **************************************************************************** #
