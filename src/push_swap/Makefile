# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2018/03/08 12:59:04 t aThursday, March 08, 19:13by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = push_swap

# Compiler
CC = gcc

# Directories
SRC_PATH = ./
SRC_PATH_MUTUAL = ../mutual/
OBJ_PATH = ../../obj/$(NAME)/
PRINTF_PATH = ../../libftprintf/
LIBFT_PATH = $(PRINTF_PATH)libft/
LIB_PATH = $(LIBFT_PATH) $(PRINTF_PATH) 
INC_PATH = ../../includes/ \
		   $(addsuffix includes/, $(LIB_PATH))

# Includes & libraries
CPPFLAGS = $(addprefix -I ,$(INC_PATH))
LDFLAGS = $(addprefix -L ,$(LIB_PATH))
LDLIBS = -lft -lftprintf

# Sources
SRC_NAME = \
		   main.c\

SRC_NAME_MUTUAL = \
		   reader.c\
		   heaps_manager.c\
		   stack_manager.c\
		   buffer_manager.c\
		   errors_manager.c\
		   \
		   swap_motion.c\
		   push_motion.c\
		   rotate_motion.c\
		   rrotate_motion.c\
		   reverse_motion.c\
		   \
		   counter_tools.c\
		   sorter_method1.c\
		   pivot_interject_method1.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_MUTUAL = $(SRC_NAME_MUTUAL:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME)) \
	  $(addprefix $(SRC_PATH_MUTUAL),$(SRC_NAME_MUTUAL))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME)) \
	  $(addprefix $(OBJ_PATH)/$(SRC_PATH_MUTUAL),$(OBJ_NAME_MUTUAL))

# Flags with OS Compatibiliy
OS = $(shell uname)
ifeq ($(OS), Darwin)
	FLAGS_DEFAULT = -Werror -Wall -Wextra
endif
ifeq ($(OS), Linux)
	FLAGS_DEFAULT = -Wno-unused-result
endif
ifdef FLAGS
	ifeq ($(FLAGS), no)
		CFLAGS := $(ADDFLAGS)
	endif
	ifeq ($(FLAGS), debug)
		CFLAGS := $(FLAGS_DEFAULT) -ansi -pedantic -g $(ADDFLAGS)
	endif
else
	CFLAGS := $(FLAGS_DEFAULT) $(ADDFLAGS)
endif

# Variables
COUNTER=0

# **************************************************************************** #
# SPECIALS CHARS                                                               #
# **************************************************************************** #
LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BOLD = \033[1m
LOG_UNDERLINE = \033[4m
LOG_BLINKING = \033[5m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

TITLE = $(LOG_CLEAR)$(LOG_BLUE)
END_TITLE = $(LOG_NOCOLOR)
LINKING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tlinking " \
				".................. $(LOG_VIOLET)$<$(LOG_NOCOLOR)"
ASSEMBLING = "--$(LOG_CLEAR)$(LOG_GREEN)✓$(LOG_NOCOLOR)\tassembling " \
			 	"............... $(LOG_YELLOW)$(NAME)$(LOG_NOCOLOR)"
OBJECTS_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion " \
				"............ $(LOG_RED)×$(LOG_NOCOLOR)"
BIN_DEL = "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion " \
				"............. $(LOG_RED)×$(LOG_NOCOLOR)"

# **************************************************************************** #
# RULES                                                                        #
# **************************************************************************** #
.PHONY: all, clean, fclean, re, norme, normadev

all: $(NAME)

$(NAME): libftprintf.a $(OBJ_PATH) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@if [ $(COUNTER) -ne 0 ]; then echo -e $(ASSEMBLING); fi;

libftprintf.a:
	@make -C $(PRINTF_PATH) $@

$(OBJ_PATH):
	@echo -e "$(TITLE)build $(NAME)$(END_TITLE)"
	@echo -e "--$(LOG_CLEAR)Flags : $(CFLAGS)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/$(SRC_PATH_MUTUAL)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo -e $(LINKING)
	$(eval COUNTER=$(shell echo $$(($(COUNTER)+1))))

clean:
	@echo -e "$(TITLE)clean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@make -C $(PRINTF_PATH) clean_quiet

fclean:
	@echo -e "$(TITLE)fclean $(NAME)$(END_TITLE)"
	@echo -e $(OBJECTS_DEL)
	@rm -Rf $(OBJ_PATH)
	@echo -e $(BIN_DEL)
	@rm -f $(NAME)
	@make -C $(PRINTF_PATH) fclean_quiet

re: fclean all

norme:
	norminette $(SRC)
	norminette $(addprefix $(INC_PATH), *.h)

normadev: 
	~/Projects/Normadev/normadev.sh **/*.[ch]

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : of there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
