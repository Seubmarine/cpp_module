CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = human_weapon

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

INCLUDE = -I Weapon.hpp -I HumanA.hpp -I HumanB.hpp
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