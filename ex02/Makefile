NAME = PmergeMe

SRC = $(wildcard ./*.cpp)

OBJ=$(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $@

fclean:
	$(RM) $(OBJ) $(NAME)

clean:
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
