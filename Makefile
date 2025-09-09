# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/09/09 17:04:45 by thblack-         ###   ########.fr        #
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
C_SRC_FILES	= client.c minitalk_utils.c
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
LIBFT_A		= $(LIBFT_DIR)/libft.a

# INCLUDE PATHS AND LIBRARIES
INC			= -I. -I$(LIBFT_DIR) -I$(INC_DIR)
LIBFT		= -L$(LIBFT_DIR) -lft

# <<<<<<< MAIN TARGETS >>>>>>>

all: start $(SERVER) $(CLIENT) finish

$(SERVER): $(S_OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(INC) $(S_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(C_OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(INC) $(C_OBJ) $(LIBFT) -o $(CLIENT)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(LIBFT_H) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# <<<<<<< PHONY TARGETS >>>>>>>

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
	@rm -f $(SERVER) $(CLIENT)
	@make -C libft fclean --no-print-directory

re: fclean all

.PHONY: all start finish clean fclean re
