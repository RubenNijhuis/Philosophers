# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rnijhuis <rnijhuis@student.oodam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 10:35:30 by rnijhuis      #+#    #+#                  #
#    Updated: 2022/09/12 15:02:47 by rubennijhui   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#============ General vars ===========#
#=====================================#

NAME			:=	philo
INCLUDE_DIR		:=	include
SRC_DIR			:=	src
OBJS_DIR		:=	objs

#=====================================#
#============ Input files ============#
#=====================================#

INC				:=	-I $(INCLUDE_DIR)

SRCS			:=	main.c \
					initiate.c \
					\
					routine/run.c \
					routine/actions.c \
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

OBJS			:=	$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

#=====================================#
#========= Command arguments =========#
#=====================================#

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror $(INC)
# CFLAGS += -g -fsanitize=thread

TEST_INPUT = 100 800 200 500

#=====================================#
#=============== Rules ===============#
#=====================================#

objs/%.o:src/*%.c $(INCLUDE_DIR)/*
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "🔨 Compiling: $<"

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) $(NO_DEAD_CODE) -pthread -o $(NAME)
	@echo "✅ Built $(NAME)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "🧹 Removing $(NAME) object files"

fclean: clean
	@rm -rf $(OUTPUT)
	@echo "🧹 Removing $(NAME) executable"

re: fclean all

#=====================================#
#=========== Special Rules ===========#
#=====================================#

run: $(NAME)
	./$(NAME) $(TEST_INPUT)

norm:
	@echo "\033[92m========= $(NAME) norm ========\033[0m"
	@-norminette $(INCLUDE_DIR)
	@echo
	@-norminette $(SRC_DIR)
	@echo "\033[92m========= $(NAME) norm ========\033[0m"

#=====================================#
#================ Misc ===============#
#=====================================#

.PHONY: all clean fclean re run
