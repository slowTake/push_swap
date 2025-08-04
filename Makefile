# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 12:25:20 by pnurmi            #+#    #+#              #
#    Updated: 2025/08/04 12:38:46 by pnurmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DONT FORGET TO CHANGE Makefile!
# DONT FORGET TO CHANGE Makefile!
# DONT FORGET TO CHANGE Makefile!
# DONT FORGET TO CHANGE Makefile!
# DONT FORGET TO CHANGE Makefile!
# DONT FORGET TO CHANGE Makefile!

# Compiler and flags
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g -I includes -I libft

# Directories  
OBJDIR	:= .objs
LIBDIR	:= libft

# Executable name
NAME	:= push_swap

# Source files (automatically finds all .c files in src/ and subdirectories)
SRC		:= $(shell find src -name "*.c")

# Object files
OBJ		:= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Libft files (since you're compiling libft sources directly)
LIBFT_SRC := $(shell find $(LIBDIR) -name "*.c")
LIBFT_OBJ := $(addprefix $(OBJDIR)/, $(LIBFT_SRC:.c=.o))

# Colors for pretty output
GREEN	:= \033[0;32m
CYAN	:= \033[0;36m
YELLOW	:= \033[1;33m
RESET	:= \033[0m

# Default rule
.DEFAULT_GOAL := all

# Build rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN)🚀 Built: $@$(RESET)"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)🛠️  Compiled:$(RESET) $<"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)🧹 Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)🗑️  Removed binary.$(RESET)"

re: fclean all

.PHONY: all clean fclean re