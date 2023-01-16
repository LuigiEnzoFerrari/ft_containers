FT_NAME := ft_containers
STD_NAME := std_containers
CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address -Wfatal-errors

SRCSDIR := ./tests/Simple-UnitTestCpp

SRCS := main.cpp iterator.cpp

SRCS_PATHS := $(addprefix $(SRCSDIR)/, $(SRCS))

OBJDIR := ./objs/

FT_OBJS := $(addprefix $(OBJDIR)ft_, $(notdir $(SRCS_PATHS:.cpp=.o)))

STD_OBJS :=$(addprefix $(OBJDIR)std_, $(notdir $(SRCS_PATHS:.cpp=.o)))

INC := -I./include/ -I tests/

all: $(FT_NAME) $(STD_NAME)

$(STD_NAME): $(STD_OBJS)
	$(CC) $(CFLAGS) $(STD_OBJS) -o $@

$(FT_NAME): $(FT_OBJS)
	$(CC) $(CFLAGS) $(FT_OBJS) -o $@

$(OBJDIR)ft_%.o: ./tests/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR)std_%.o: ./tests/%.cpp
	$(CC) $(CFLAGS) -D STD $(INC) -c $< -o $@

	
$(FT_OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(FT_NAME) $(STD_NAME) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re one
