# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 20:52:06 by uzanchi           #+#    #+#              #
#    Updated: 2024/09/26 20:56:15 by uzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c \
		ft_split_utils.c \
		list_check.c \
		free_init.c \
		list_utils.c \
		list_swap.c \
		list_rotate.c \
		list_reverse_rotate.c \
		list_push.c \
		mediane_utils.c \
		push_algo_utils.c \
		push_swap.c
OBJS = ${SRCS:.c=.o}

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
PURPLE = \033[1;35m
BOLD := \033[1m
RESET = \033[0m 

SUCCESS = [ ✔ ]
ERROR = [ ✗ ]
CLEAN = [ ♻ ]
REMOVE = [ 🗑 ]
REDO = [ 🗘 ]

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN} ============ ${SUCCESS} ${NAME} compiled successfully! ================ ${RESET}"

${BONUS}: ${OBJS} ${OBJS_BONUS}
	@${CC} ${FLAGS} ${OBJS_BONUS} -o ${BONUS}
	@echo "${GREEN} ============ ${SUCCESS} ${BONUS} compiled successfully! ================ ${RESET}"

.c.o:
	@${CC} ${FLAGS} -c $< -o $@ || (echo "\n${RED} ============ ${ERROR} Compilation failed ! ==================== ${NC}\n"; exit 1)
	@echo "${GREEN} ============ ${SUCCESS} Successful compilation ! ================ ${RESET}"

clean:
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@echo "${YELLOW} ============ ${CLEAN} Successful binary cleaning ! ============ ${RESET}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${BOLD}${ORANGE} ============ ${REMOVE} Deleted executable ! ==================== ${RESET}"

re: fclean all
	@echo "${PURPLE} ============ ${REDO} Redo completed ! ======================== ${RESET}"

bonus: ${BONUS}

.PHONY: all clean fclean re