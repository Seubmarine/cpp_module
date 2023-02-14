CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g3

NAME = diamondtrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

INCLUDE =

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
.PHONY: all clean fclean re