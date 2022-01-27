# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rubennijhuis <rubennijhuis@student.coda      +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/24 19:46:54 by rubennijhui   #+#    #+#                  #
#    Updated: 2022/01/27 14:19:28 by rnijhuis      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := philo
INCLUDE_DIR := ./include
SRC_DIR := ./src
BIN_DIR := ./bin
LIB_DIR := ./libs

OBJS := main.o \
		utils/ft_calloc.o

INCLUDES := 

SRCS_PREFIX = $(SRCS:%=$(SRC_DIR)/%)
INCLUDES_PREFIX = $(INCLUDES:%=$(INCLUDE_DIR)/%)

CC := gcc
CFLAGS := -Wall -Wextra -Werror
LINK := $(CC) $(CFLAGS)

TEST_COMMAND = 5 1000 1000 1000

# $(NAME):$(OBJS) $(INCLUDE_DIR)/$(NAME).h
# 	$(LINK) $(SRCS_PREFIX) -o $(BIN_DIR)/$(NAME)

%.o:%.c
	gcc -c -Wall -Wextra -Werror -I $(INCLUDE_DIR) -o $@ $^

run:
	$(BIN_DIR)/$(NAME) $(TEST_COMMAND)

all: run

clean:
	@rm -rf $(OBJS)
	@echo "🧹 Removing object files"

fclean: clean
	@rm -rf $(BIN_DIR)/$(NAME)
	@echo "🧹 Removing $(NAME) executable"

re: fclean all

.PHONY: run all clean fclean re