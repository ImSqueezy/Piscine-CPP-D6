NAME = a.out
FLAGS = -Wall -Wextra -Werror
COMPILE = c++ $(FLAGS)
SRCS = main.cpp Base.cpp utils.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o:%.cpp Base.hpp ADerived.hpp BDerived.hpp CDerived.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean