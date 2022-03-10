# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.oodam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 10:35:30 by rnijhuis      #+#    #+#                  #
#    Updated: 2022/03/10 14:53:59 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#============ General vars ===========#
NAME := philo
INCLUDE_DIR := include
SRC_DIR := src
LIBS_DIR := libs
OBJS_DIR := objs

#============ Input files ============#
INC = -I $(INCLUDE_DIR)

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
		\
		threads/close_threads.c \
		threads/make_threads.c \

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))


#========= Command arguments =========#
CC = clang
CFLAGS = -Wall -Wextra -Werror -g $(INC)
LDFLAGS = 

TEST_DATA = 5 800 200 200


#=============== Rules ===============#
objs/%.o:src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^
	@echo "🔨 Compiling: $^"

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
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
