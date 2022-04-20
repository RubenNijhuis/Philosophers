# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.oodam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 10:35:30 by rnijhuis      #+#    #+#                  #
#    Updated: 2022/03/14 17:52:18 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#============ General vars ===========#
#=====================================#

NAME := philo
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs
OBJS_DIR := objs

#=====================================#
#============ Input files ============#
#=====================================#

LIB_HEADERS =
LIB_HEADERS_INCLUDE =
LIB_ARCHIVES =

INC = -I $(INCLUDE_DIR) $(INCLUDE_LIBS)

SRCS := main.c \
		stop_sim.c \
		initiate.c \
		validate_arguments.c \
		\
		philo/philo.c \
		philo/states.c \
		\
		utils/ft_calloc.c \
		utils/ft_atoi.c \
		utils/convert_time.c \
		utils/print_state.c \
		utils/is_only_number.c \
		\
		threads/close_threads.c \
		threads/make_threads.c \

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

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -pthread -o $(NAME)
	@echo "✅ Built $(NAME)"

get_src_files:
	@find $(SRC_DIR) | cut -b 5-

run:
	./$(NAME) $(TEST_DATA)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Removing object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "🧹 Removing $(NAME) executable"

re: fclean all

.PHONY: all clean fclean re run
