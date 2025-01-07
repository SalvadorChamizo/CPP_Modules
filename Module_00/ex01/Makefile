NAME = phonebook
RM = rm -f
CC = g++
FLAGS = -g -Wall -Werror -Wextra
C98_FLAGS = -std=c++98

FILES = src/Contact_Class \
		src/PhoneBook_Class \
		src/Utils \
		main \

SRCS_DIR = ./
OBJS_DIR = ./

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@$(CC) $(FLAGS) $(CPP98_FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FLAGS) $(C98_FLAGS) -o $(NAME)
	@echo
	@echo "$(GREEN)CPP Module 00: Ex01 compiled!$(RESET)"
	@echo

clean:
	@$(RM) $(OBJS)
	@echo
	@echo "$(RED)Cleaning objects.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Cleaning executables.$(RESET)"
	@echo

re: fclean $(NAME)

.PHONY: clean fclean all re

# Colors
MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY    = \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD    = \033[1m
RED     = \033[31;1m