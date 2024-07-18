# Standard
NAME                = Pipex

# Directories
LIBFT               = ./libft/libft.a
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/
GNL_DIR             = get_next_line/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra  -MMD -g -fsanitize=address
RM                  = rm -f 

# Additional flags
INCLUDES            = -I /usr/local/include
LIBRARIES           = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

# Source files
SRCS                = main.c  here_doc.c find_execs.c check_access.c
GNL_SRCS            = get_next_line.c get_next_line_utils.c

# File paths
SRC                 = $(addprefix $(SRC_DIR), $(SRCS))
GNL_SRC             = $(addprefix $(GNL_DIR), $(GNL_SRCS))
OBJ                 = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(GNL_SRCS:.c=.o))
DEPS                = $(OBJ:.o=.d)

all:                $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft > /dev/null
	@echo "\033[1;32mLibft.a has been created.\033[0m"

obj:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\033[1;31mDirectory already created.\033[0m"; \
	else \
		mkdir -p $(OBJ_DIR); \
		echo "Directory obj/ with files .o is being created..."; \
	fi

$(NAME): $(LIBFT) obj $(OBJ)
	@echo "Compiling so_long..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(LIBRARIES)
	@echo "\033[1;32mDone.\033[0m"

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile $@ created.\033[0m";

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -I$(GNL_DIR) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile $@ created.\033[0m";

clean:
	@echo "Removing obj/..."
	@$(RM) -r $(OBJ_DIR)
	@echo "Cleaning libft..."
	@make clean -C ./libft > /dev/null
	@echo "\033[1;32mAll Done for clean.\033[0m"

fclean: clean
	@echo "Removing so_long..."
	@$(RM) $(NAME)
	@echo "Removing libft.a..."
	@$(RM) $(LIBFT)
	@echo "\033[1;32mDone.\033[0m"

re: fclean all

.PHONY: all obj clean fclean re

-include $(DEPS)