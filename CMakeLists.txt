cmake_minimum_required(VERSION 3.31)
project(Cpp05)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 CPP_Module_05/ex00/main.cpp
		CPP_Module_05/ex00/Bureaucrat.cpp
		CPP_Module_05/ex00/Bureaucrat.hpp
		CPP_Module_05/ex00/Makefile)
add_executable(ex01 CPP_Module_05/ex01/Bureaucrat.cpp CPP_Module_05/ex01/Bureaucrat.hpp CPP_Module_05/ex01/Form.cpp CPP_Module_05/ex01/Form.hpp CPP_Module_05/ex01/main.cpp CPP_Module_05/ex01/Makefile)
add_executable(ex02 CPP_Module_05/ex02/AForm.cpp CPP_Module_05/ex02/AForm.hpp CPP_Module_05/ex02/Bureaucrat.cpp CPP_Module_05/ex02/Bureaucrat.hpp CPP_Module_05/ex02/main.cpp CPP_Module_05/ex02/Makefile CPP_Module_05/ex02/PresidentialPardonForm.cpp CPP_Module_05/ex02/PresidentialPardonForm.hpp CPP_Module_05/ex02/RobotomyRequestForm.cpp CPP_Module_05/ex02/RobotomyRequestForm.hpp CPP_Module_05/ex02/ShrubberyCreationForm.cpp CPP_Module_05/ex02/ShrubberyCreationForm.hpp)
add_executable(ex03 CPP_Module_05/ex03/AForm.cpp CPP_Module_05/ex03/AForm.hpp CPP_Module_05/ex03/Bureaucrat.cpp CPP_Module_05/ex03/Bureaucrat.hpp CPP_Module_05/ex03/Intern.cpp CPP_Module_05/ex03/Intern.hpp CPP_Module_05/ex03/main.cpp CPP_Module_05/ex03/Makefile CPP_Module_05/ex03/PresidentialPardonForm.cpp CPP_Module_05/ex03/PresidentialPardonForm.hpp CPP_Module_05/ex03/RobotomyRequestForm.cpp CPP_Module_05/ex03/RobotomyRequestForm.hpp CPP_Module_05/ex03/ShrubberyCreationForm.cpp CPP_Module_05/ex03/ShrubberyCreationForm.hpp)
