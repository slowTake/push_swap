# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 12:25:20 by pnurmi            #+#    #+#              #
#    Updated: 2025/08/11 14:36:15 by pnurmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME        := push_swap

# Directory Definitions
SRC_DIR     := srcs
OBJ_DIR     := objs
INC_DIR     := includes

# Source Files: Manually listed with full paths
SRCS        := $(SRC_DIR)/main/main.c \
               $(SRC_DIR)/moves/push.c \
               $(SRC_DIR)/moves/rotate.c \
               $(SRC_DIR)/moves/rrotate.c \
               $(SRC_DIR)/moves/swap.c \
               $(SRC_DIR)/parsing/checks.c \
               $(SRC_DIR)/parsing/error.c \
               $(SRC_DIR)/parsing/parse.c \
               $(SRC_DIR)/sort/radix.c \
               $(SRC_DIR)/sort/sort.c \
               $(SRC_DIR)/utility/list_man.c \
               $(SRC_DIR)/utility/utils.c

# Header File for Push_Swap
HEADER      := push_swap.h

# Object Files: Generated from full source paths
OBJS        := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler and Flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g

# Remove Command
RM          := rm -f

# Libft Integration
LIBFT_DIR   := ./libft
LIBFT       := $(LIBFT_DIR)/libft.a
LIBFT_H     := $(LIBFT_DIR)/libft.h

# Include Paths and Libraries
INC         := -I. -I$(LIBFT_DIR) -I$(INC_DIR)
LIBS        := -L$(LIBFT_DIR) -lft

# -------------------- Main Targets --------------------

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $(NAME)

# Rule to compile individual .c files into .o files.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rule to build libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# -------------------- Phony Targets --------------------

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all