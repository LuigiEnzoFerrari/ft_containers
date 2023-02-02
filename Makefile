FT_NAME := ft_containers
STD_NAME := std_containers
CC := c++
CFLAGS := -g -Wall -Wextra -Werror -Wfatal-errors -pedantic-errors -std=c++98 -fsanitize=address
MAIN = main.cpp


TESTDIRS := normal_iterator/ map/ vector/

VPATH = tests/ $(addprefix tests/, $(TESTDIRS)) include/

VECTOR := vector_iterator.cpp vector_reverse_iterator.cpp \
	vector_modifiers.cpp vector_elements_access.cpp \
	vector_constructors.cpp vector_capacity.cpp \
	vector_non_member_functions.cpp \
	aux.cpp

HEADERS = stl_map.hpp

MAP := map_pair.cpp map_constructors.cpp map_capacity.cpp map_element_access.cpp \
	map_iterators.cpp map_modifiers.cpp map_observers.cpp map_operations.cpp \

SRCS :=  $(VECTOR) $(MAP)
OBJDIR := ./objs/

FT_OBJS := $(addprefix $(OBJDIR)ft_, $(notdir $(SRCS:.cpp=.o)))
STD_OBJS :=$(addprefix $(OBJDIR)std_, $(notdir $(SRCS:.cpp=.o)))

INC := -I include/ -I tests/

all: $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJS) $(MAIN) $(HEADERS)
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
