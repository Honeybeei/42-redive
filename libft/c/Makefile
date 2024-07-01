# Compiler and flags
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -Werror -I./inc
CXXFLAGS = -Wall -Wextra -Werror -I./inc -std=c++17

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIB_DIR = lib

# Source files
C_SRCS = $(filter-out $(SRC_DIR)/test_libft.cpp, $(wildcard $(SRC_DIR)/*.c))
C_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SRCS))

# Test file
TEST_SRC = $(SRC_DIR)/test_libft.cpp
TEST_OBJ = $(OBJ_DIR)/test_libft.o

# Library name
LIB_NAME = libft.a

# Executable name for tests
TEST_NAME = test_libft

# Targets
all: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(C_OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(LIB_DIR)/$(LIB_NAME) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(TEST_OBJ) -L$(LIB_DIR) -lft -o $(TEST_NAME)
	./$(TEST_NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LIB_DIR)
	rm -f $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test