MANDATORY=  megaphone.cpp\

CC=cc
FLAGS= -Wall -Werror -Wextra -std=c++98
DEBUG=-fsanitize=address -g
NAME=megaphone

all: $(NAME)

$(NAME):$(MANDATORY)
	g++ $(FLAGS) $(MANDATORY) -o $(NAME)

debug:$(VRLIBFT)
	g++ $(FLAGS) $(DEBUG) $(MANDATORY) -o $(NAME) 

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
