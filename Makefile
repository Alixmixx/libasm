RM = rm -rf
MKDIR = mkdir -p
LIB = ar rcs
CC = gcc
CCFLAGS = -g -Wall -Wextra -Werror #-fomit-frame-pointer
NASM = nasm
NASMFLAGS = -f elf64
NAME = libasm.a
TEST = test
SRC_DIR = src
OBJ_DIR = obj
ASMSRC = $(SRC_DIR)/ft_strlen.s\
		 $(SRC_DIR)/ft_strcpy.s\
		 $(SRC_DIR)/ft_strcmp.s\
		 $(SRC_DIR)/ft_write.s\
		 $(SRC_DIR)/ft_read.s\
		 
ASMOBJ = $(ASMSRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

bonus: all

$(NAME): $(ASMOBJ)
	@echo "$(GREEN)Creating $(NAME)$(NC)"
	$(LIB) $(NAME) $(ASMOBJ)

$(TEST): all
	@echo "$(GREEN)Compiling test$(NC)"
	$(CC) main.c $(NAME) -o $(TEST)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@echo "$(GREEN)Assembling $<$(NC)"
	$(MKDIR) $(OBJ_DIR)
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	@echo "$(RED)Cleaning object files$(NC)"
	$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME) and test$(NC)"
	$(RM) $(NAME)
	$(RM) test

re: fclean all

.PHONY: all bonus test clean fclean re
