CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = zombie_horde

SRCS = Zombie.cpp zombieHorde.cpp main.cpp
INCLUDE = -I Zombie.hpp
OBJS = $(SRCS:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean
	$(MAKE) all
.PHONY: re all