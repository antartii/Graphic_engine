CC = g++
AR = ar rcs

TARGET = program
TARGET_DEBUG = $(TARGET)_debug
CFLAGS_INCLUDES = $(addprefix -I, $(shell find $(INCLUDE_DIR) -type d)) \
    $(foreach dep, $(DEPENDENCIES_PATH), $(addprefix -I, $(shell find $(dep)/includes -type d)))
CFLAGS = $(CFLAGS_INCLUDES) -W -Wextra -lGL -lGLU -lglut
CFLAGS_DEBUG = -g

INCLUDE_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
DEPENDENCIES_PATH =

SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: build_dependencies $(TARGET)

build_dependencies:
	@$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep);)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)\
	$(foreach dep,$(DEPENDENCIES_PATH), $(dep)/*.a) -o $(TARGET)
	@echo "project '$(TARGET)' successfully build"

$(TARGET_DEBUG): $(OBJ)
	@echo "project '$(TARGET_DEBUG)' successfully build"
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(OBJ)\
	$(foreach dep,$(DEPENDENCIES_PATH),-L$(dep) -l$(dep)) -o $(TARGET_DEBUG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "making directory '$(OBJ_DIR)' since it doesn't exist"

debug: build_dependencies $(TARGET_DEBUG)

clean:
	@$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep) clean;)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep) fclean;)
	@rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re build_dependencies