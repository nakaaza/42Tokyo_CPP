# ---- settings ----
NAME     := ex00
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

OBJ_DIR  := obj

SRCS     := main.cpp ClapTrap.cpp
OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS     := $(OBJS:.o=.d)

# ---- rules ----
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
