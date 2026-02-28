NAME = a.out
FLAGS = -Wall -Wextra -Werror
COMPILE = c++ $(FLAGS)
SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o:%.cpp Serializer.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean