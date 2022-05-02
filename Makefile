# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.oodam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 10:35:30 by rnijhuis      #+#    #+#                  #
#    Updated: 2022/05/02 21:51:31 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#============ General vars ===========#
#=====================================#

NAME := philo
INCLUDE_DIR := include
SRC_DIR := src
OBJS_DIR := objs
BIN_DIR := bin
OUTPUT := $(BIN_DIR)/$(NAME)

#=====================================#
#============ Input files ============#
#=====================================#

INC = -I $(INCLUDE_DIR)

SRCS := main.c \
		initiate.c \
		\
		philosopher/philo.c \
		philosopher/actions.c \
		\
		utils/gettime.c \
		utils/ft_atoi.c \
		utils/ft_calloc.c \
		utils/print_state.c \
		utils/validate_args.c \
		\
		threads/make_threads.c \
		threads/death_checker.c \
		threads/destroy_mutexes.c \

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(INC)
# LDFLAGS = -fsanitize=thread

TEST_DATA = 5 800 200 200

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o:src/*%.c $(INCLUDE_DIR)/* $(LIB_HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "🔨 Compiling: $<"

all: $(OUTPUT)

$(OUTPUT):$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) $(NO_DEAD_CODE) -pthread -o $(OUTPUT)
	@echo "✅ Built $(NAME)"

run:
	./$(OUTPUT) $(TEST_DATA)

norm:
	@-norminette $(INCLUDE_DIR)/philo.h
	@-norminette $(SRC_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Removing object files"

fclean: clean
	@rm -rf $(OUTPUT)
	@echo "🧹 Removing $(NAME) executable"

re: fclean all

.PHONY: all clean fclean re run
