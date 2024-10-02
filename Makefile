# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 13:03:40 by uzanchi           #+#    #+#              #
#    Updated: 2024/09/28 13:03:41 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror -I./includes

# Directories
SRCDIR = src
OBJDIR = obj
BONUS_OBJDIR = bonus/obj
INCDIR = includes

# Source files
SRCS = $(SRCDIR)/list.c \
       $(SRCDIR)/main.c \
       $(SRCDIR)/parse.c \
       $(SRCDIR)/ope.c \
       $(SRCDIR)/ope2.c \
       $(SRCDIR)/insert_sort.c \
       $(SRCDIR)/do_mov.c \
       $(SRCDIR)/count_move.c \
       $(SRCDIR)/quick_sort.c \
       $(SRCDIR)/quick_sort_utils.c \
       $(SRCDIR)/count_move_utils.c \
       $(SRCDIR)/free.c \
	   $(SRCDIR)/ft_split.c \
	   $(SRCDIR)/utils.c

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Bonus files
SRCS_BONUS = bonus/$(SRCDIR)/free_bonus.c \
             bonus/$(SRCDIR)/get_next_line_bonus.c \
             bonus/$(SRCDIR)/list_bonus.c \
             bonus/$(SRCDIR)/ope2_bonus.c \
             bonus/$(SRCDIR)/parse_bonus.c \
             bonus/$(SRCDIR)/ft_split_bonus.c \
             bonus/$(SRCDIR)/get_next_line_utils_bonus.c \
             bonus/$(SRCDIR)/main_bonus.c \
             bonus/$(SRCDIR)/ope_bonus.c \
             bonus/$(SRCDIR)/utils_bonus.c \
			 bonus/$(SRCDIR)/do_move_bonus.c

# Bonus object files
OBJS_BONUS = $(SRCS_BONUS:bonus/$(SRCDIR)/%.c=$(BONUS_OBJDIR)/%.o)

# Colors
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
PURPLE = \033[1;35m
BOLD := \033[1m
RESET = \033[0m 

# Success/Failure markers
SUCCESS = [ ✔ ]
ERROR = [ ✗ ]
CLEAN = [ ♻ ]
REMOVE = [ 🗑 ]
REDO = [ 🗘 ]

# Default rule
all: $(NAME)

# Compilation rule for main program
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) ============ $(SUCCESS) $(NAME) compiled successfully! ================ $(RESET)"

# Compilation rule for bonus program
$(BONUS): $(OBJS_BONUS)
	@$(CC) $(FLAGS) $(OBJS_BONUS) -o $(BONUS)
	@echo "$(GREEN) ============ $(SUCCESS) $(BONUS) compiled successfully! ================ $(RESET)"

# Rule to compile .c to .o for main program
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@ || (echo "\n$(RED) ============ $(ERROR) Compilation failed! ==================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Compiled $< successfully! ================ $(RESET)"

# Rule to compile .c to .o for bonus program
$(BONUS_OBJDIR)/%.o: bonus/$(SRCDIR)/%.c | $(BONUS_OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@ || (echo "\n$(RED) ============ $(ERROR) Compilation failed! ==================== $(RESET)\n"; exit 1)
	@echo "$(GREEN) ============ $(SUCCESS) Compiled $< successfully! ================ $(RESET)"

# Create obj directories if they don't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BONUS_OBJDIR):
	@mkdir -p $(BONUS_OBJDIR)

# Clean rule to remove object files
clean:
	@rm -rf $(OBJDIR) $(BONUS_OBJDIR)
	@echo "$(YELLOW) ============ $(CLEAN) Object files cleaned! ============ $(RESET)"

# Full clean including executables
fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@echo "$(BOLD)$(ORANGE) ============ $(REMOVE) Executables removed! ==================== $(RESET)"

# Rebuild all
re: fclean all
	@echo "$(PURPLE) ============ $(REDO) Rebuild completed! ======================== $(RESET)"

# Bonus compilation
bonus: $(BONUS)

# Phony targets
.PHONY: all clean fclean re bonus
