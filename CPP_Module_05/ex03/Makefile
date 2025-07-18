NAME	= ex03
CC		= c++
FLAGS	= -Werror -Wextra -Wall -std=c++98
RM		= rm -rf

SRC		= main.cpp \
		  Bureaucrat.cpp \
		  AForm.cpp \
		  ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp \
		  Intern.cpp
OBJ		= $(SRC:%.cpp=obj/%.o)

all: $(NAME)

obj/%.o : %.cpp
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

.PHONY: all clean fclean re