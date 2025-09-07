# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/09/04 18:24:36 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= minitalk
SERVER		= server
CLIENT		= client
NAME		= $(SERVER) $(CLIENT)

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

# PROJECT SOURCES: Explicitly states
S_SRC_FILES	= server.c
S_SRC		= $(addprefix $(SRC_DIR)/, $(S_SRC_FILES))
C_SRC_FILES	= client.c
C_SRC		= $(addprefix $(SRC_DIR)/, $(C_SRC_FILES))

# PROJECT HEADER
HEADER		= $(INC_DIR)/minitalk.h

# PROJECT OBJECTS
S_OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(S_SRC))
C_OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRC))

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# REMOVE
RM			= rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/libft.h

# INCLUDE PATHS AND LIBRARIES
INC			= -I. -I$(LIBFT_DIR) -I$(INC_DIR)
LIBFT		= -L$(LIBFT_DIR) -lft

# <<<<<<< MAIN TARGETS >>>>>>>

$(SERVER): $(S_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(S_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(C_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) $(C_OBJ) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(LIBFT_H) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# <<<<<<< PHONY TARGETS >>>>>>>

all: start $(NAME) finish

start:
	@echo "==== THOMASROFF MAKEFILE ===="
	@echo "Building $(PROJECT)"

finish:
	@echo "====== BUILD COMPLETE ======="

clean:
	@echo "Removing object files."
	@rm -f $(S_OBJ) $(C_OBJ)
	@make -C libft clean --no-print-directory

fclean: clean
	@echo "Removing static library files."
	@rm -f $(NAME)
	@make -C libft fclean --no-print-directory

re: fclean all

.PHONY: all start finish clean fclean re
