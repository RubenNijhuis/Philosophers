# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/24 19:46:54 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/02/23 16:14:22 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := philo
INCLUDE_DIR := ./include
SRC_DIR := ./src
BIN_DIR := ./bin
LIB_DIR := ./libs

HEADERFILES := $(INCLUDE_DIR)/$(NAME).h

OBJS := src/main.o \
		src/utils/validate_arguments.o \
		src/utils/initiate_data.o \
		src/utils/ft_atoi.o \
		src/utils/ft_calloc.o \
		src/utils/convert_time.o \

CC=clang
CFLAGS=-Wall -Wextra -g -fsanitize=address
LDFLAGS=-g -fsanitize=address

TEST_COMMAND = 5 1800 1200 1200

obj/%.o:src/%.c ./include/philo.h
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -o $@ $^

$(NAME):$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o ./bin/philo

run:
	$(BIN_DIR)/$(NAME) $(TEST_COMMAND)

clean:
	@rm -rf $(OBJS)
	@echo "🧹 Removing object files"

fclean: clean
	@rm -rf $(BIN_DIR)/$(NAME)
	@echo "🧹 Removing $(NAME) executable"

all: $(NAME) clean

re: fclean all

.PHONY: run all clean fclean re