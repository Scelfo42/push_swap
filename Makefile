NAME = push_swap

RM_DIR = rm -rf

CC = clang

DEBUG_FLAG = -g

CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG)

OLD_PROJ = projects

HEADER_1 = header/ft_push_swap.h

HEADER_2 = $(OLD_PROJ)/fl_header/ft_first_layer.h

DEPS = header $(OLD_PROJ)/fl_header

OLD_PROJ_DIR = first_layer

SRCS_DIR = srcs

OBJ_DIR = obj

LIB_DIR = $(OLD_PROJ)/lib

LIB = libft.a

SRCS_FILES = ft_push_swap.c ft_create_node.c ft_check_errors.c ft_moves.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(MAKE) -C projects all 
	$(CC) $(CFLAGS) $(O_SRCS) $(LIB_DIR)/$(LIB) -o $(NAME)
	#clear

clean:
	$(MAKE) -C projects clean
	$(RM_DIR) $(OBJ_DIR)/
	$(RM) $(O_SRCS)
	#clear

fclean: clean 
	$(RM_DIR) $(LIB_DIR)
	$(RM) $(NAME)
	#clear

re: fclean all
	#clear

push:
	git add .
	@echo "$(RED)Adding all changes..."
	sleep 1.5
	@clear
	@echo "$(GREEN)All changes added$(NC)"
	@read -p "Enter a custom commit message (leave blank to use the default message): " message; \
	if [ -n "$$message" ]; then \
		git commit -m "$$message"; \
	else \
		git commit -m "$(shell date +'%H:%M %d-%h') update"; \
	fi
	@echo "$(YELLOW)Committing...and..."
	git push
	@echo "$(GREEN)PUSHA KEKKO!$(NC)"

norm:
	norminette *

pull:
	git pull	

.PHONY: all clean fclean re push norm pull
.SILENT:
