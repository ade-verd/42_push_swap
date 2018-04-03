# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2018/04/03 15:36:09 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = push_swap_and_checker
NAME_SWP = push_swap
NAME_CHK = checker

# Directories
SRC_PATH = src
SWP_PATH = $(SRC_PATH)/$(NAME_SWP)
CHK_PATH = $(SRC_PATH)/$(NAME_CHK)
LIB_PATH = libftprintf/libft
OBJ_PATH = obj

# MAKEFLAGS
MAKEFLAGS += --no-print-directory
MAKE = make --no-print-directory -C #$(MAKEFLAGS)

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
.PHONY: all, clean, fclean, re, norme, norm, push_swap, checker

all: $(NAME)

$(NAME): $(NAME_SWP) $(NAME_CHK)

$(NAME_SWP): force
	@$(MAKE) $(SWP_PATH) $@
	@if [ -h $@ ]; then rm -f $@; fi;
	@ln -s $(SWP_PATH)/$@ .

$(NAME_CHK): force
	@$(MAKE) $(CHK_PATH) $@
	@if [ -h $@ ]; then rm -f $@; fi;
	@ln -s $(CHK_PATH)/$@ .

force:
	@true

libft.a:
	@$(MAKE) $(LIB_PATH) $@

clean:
	@$(MAKE) $(SWP_PATH) clean
	@$(MAKE) $(CHK_PATH) clean
	@rm -Rf $(OBJ_PATH)


fclean:
	@$(MAKE) $(SWP_PATH) fclean
	@$(MAKE) $(CHK_PATH) fclean
	@rm -Rf $(OBJ_PATH)
	@if [ -h $(NAME_SWP) ]; then rm -f $(NAME_SWP); fi;
	@if [ -h $(NAME_CHK) ]; then rm -f $(NAME_CHK); fi;

re: fclean all

norme:
	@echo -e "$(TITLE)Norminette: $(NAME_SWP)$(END_TITLE)"
	@$(MAKE) $(SWP_PATH) norme
	@echo -e "$(TITLE)Norminette: $(NAME_CHK)$(END_TITLE)"
	@$(MAKE) $(CHK_PATH) norme

normadev: 
	sh ~/Projects/support/Normadev/normadev.sh **/*.[ch]
#	norminette **/*.[ch] | grep -B 1 "Error\|Warning" || echo "norme OK"

# **************************************************************************** #
# Personal notes :                                                             #
#                                                                              #
# $@ : rule's name                                                             #
# $^ : all dependencies after ':'                                              #
# $< : corresponding dependency                                                #
# || : of there is an error, execute the command after the double pipe         #
#                                                                              #
# **************************************************************************** #
