# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lude-jes <lude-jes@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 16:56:43 by dbaltaza          #+#    #+#              #
#    Updated: 2026/02/03 22:11:24 by lude-jes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ══════════════════════════════════════════════════════════════════════════════
#                                   PROGRAM
# ══════════════════════════════════════════════════════════════════════════════

NAME		= push_swap

# ══════════════════════════════════════════════════════════════════════════════
#                                   COMPILER
# ══════════════════════════════════════════════════════════════════════════════

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# ══════════════════════════════════════════════════════════════════════════════
#                                 DIRECTORIES
# ══════════════════════════════════════════════════════════════════════════════

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= .

# ══════════════════════════════════════════════════════════════════════════════
#                                   SOURCES
# ══════════════════════════════════════════════════════════════════════════════

# Main
MAIN		= main.c

# Operations
OPS_DIR		= ops
OPS_SRC		= swap_ops.c push_ops.c rot_ops.c revrot_ops.c

# Sorting
SORT_DIR	= sorting
SORT_SRC	= index.c small_sort.c sort_utils.c
TURK_DIR	= turk
TURK_SRC	= cost.c move.c target.c turk.c

# Parsing
PARSE_DIR	= parsing
PARSE_SRC	= parse.c validate_token.c

# Utils
UTILS_DIR	= utils
UTILS_SRC	= ft_split.c list_ops.c stack_ops.c

# All sources with paths
SRCS		= $(MAIN) \
			  $(addprefix $(SRC_DIR)/$(OPS_DIR)/, $(OPS_SRC)) \
			  $(addprefix $(SRC_DIR)/$(SORT_DIR)/, $(SORT_SRC)) \
			  $(addprefix $(SRC_DIR)/$(SORT_DIR)/$(TURK_DIR)/, $(TURK_SRC)) \
			  $(addprefix $(SRC_DIR)/$(PARSE_DIR)/, $(PARSE_SRC)) \
			  $(addprefix $(SRC_DIR)/$(UTILS_DIR)/, $(UTILS_SRC))

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ══════════════════════════════════════════════════════════════════════════════
#                                    FLAGS
# ══════════════════════════════════════════════════════════════════════════════

INCLUDES	= -I$(INC_DIR)

# ══════════════════════════════════════════════════════════════════════════════
#                                   COLORS
# ══════════════════════════════════════════════════════════════════════════════

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
RED			= \033[0;31m
RESET		= \033[0m

# ══════════════════════════════════════════════════════════════════════════════
#                                    RULES
# ══════════════════════════════════════════════════════════════════════════════

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(CYAN)Compiling: $(notdir $<)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)✓ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✓ $(NAME) removed$(RESET)"

re: fclean all

# ══════════════════════════════════════════════════════════════════════════════
#                                    UTILS
# ══════════════════════════════════════════════════════════════════════════════

norm:
	@echo "$(BLUE)Checking norminette...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR) | grep -E "Error|OK" || true

.PHONY: all clean fclean re norm