FT_NAME := ft_containers
STD_NAME := std_containers
CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address

SRCSDIR := ./tests/Simple-UnitTestCpp

SRCS := main.cpp iterator.cpp UnitTest.cpp

SRCS_PATHS := $(addprefix $(SRCSDIR)/, $(SRCS))

OBJDIR := ./objs/

OBJS := $(addprefix $(OBJDIR), $(notdir $(SRCS_PATHS:.cpp=.o)))

INC := -I./include/ -I tests/

$(OBJDIR)%.o: ./tests/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(FT_NAME) $(STD_NAME)

$(STD_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(FT_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(FT_NAME) $(STD_NAME) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
