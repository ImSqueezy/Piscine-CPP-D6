NAME = prog
FLAGS = -Wall -Wextra -Werror
COMPILE = c++ $(FLAGS)
SRCS = ScalarConverter.cpp main.cpp utils.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o:%.cpp ScalarConverter.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean