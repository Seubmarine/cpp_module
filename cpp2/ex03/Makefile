CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = bsp

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

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