CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = PmergeMe

SRCS = main.cpp

INCLUDE = -I.

OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) PmergeMe.hpp
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean
	$(MAKE) all
.PHONY: all clean fclean re