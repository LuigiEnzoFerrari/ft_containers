FT_NAME := ft_containers
STD_NAME := std_containers
CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++98 -Wfatal-errors -pedantic-errors# -fsanitize=address 
# 
MAIN = main.cpp


TESTDIRS := normal_iterator/ func/ vector/
VPATH = tests/ $(addprefix tests/, $(TESTDIRS))

V_ITERATORS := vector_iterator.cpp vector_reverse_iterator.cpp \
	vector_modifiers.cpp vector_elements_access.cpp \
	vector_constructors.cpp vector_capacity.cpp\
	aux.cpp

VECTOR_SRCS := $(V_ITERATORS)

SRCS :=  $(VECTOR_SRCS)
OBJDIR := ./objs/

FT_OBJS := $(addprefix $(OBJDIR)ft_, $(notdir $(SRCS:.cpp=.o)))
STD_OBJS :=$(addprefix $(OBJDIR)std_, $(notdir $(SRCS:.cpp=.o)))

INC := -I include/ -I tests/

all: $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(INC) $(FT_OBJS) -o $@

$(STD_NAME): $(STD_OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(INC) $(STD_OBJS) -o $@

$(OBJDIR)ft_%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR)std_%.o: %.cpp
	$(CC) $(CFLAGS) -D STD $(INC) -c $< -o $@
	
$(FT_OBJS): | $(OBJDIR)
$(STD_OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(FT_NAME) $(STD_NAME) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re one
