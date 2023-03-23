MANDATORY=  main.cpp  PmergeMe.cpp

CC=cc
FLAGS= -Wall -Werror -Wextra -std=c++98
DEBUG=-fsanitize=address -g
NAME=PmergeMe

all: $(NAME)

$(NAME):$(MANDATORY)
	c++ $(FLAGS) $(MANDATORY) -o $(NAME)

debug:$(VRLIBFT)
	c++ $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all