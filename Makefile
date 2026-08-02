NAME = chess

CXX = g++

CXXFLAGS = -Wall -Wextra -Wpedantic -g -O0 -Iinclude

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp \
      src/board.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run