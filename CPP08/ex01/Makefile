CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Span

SRC = main.cpp \
	  Span.cpp

OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
