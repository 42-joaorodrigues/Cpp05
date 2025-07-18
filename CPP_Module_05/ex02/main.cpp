#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm() {
    std::cout << "\n===== TESTING SHRUBBERY CREATION FORM =====\n" << std::endl;

    // Create a form
    ShrubberyCreationForm form("garden");
    std::cout << "Created form: " << form << std::endl;

    // Test with bureaucrats of different grades
    Bureaucrat highRank("Director", 1);
    Bureaucrat midRank("Manager", 100);
    Bureaucrat lowRank("Intern", 150);

    std::cout << "\n--- Testing with a low-ranked bureaucrat ---" << std::endl;
    std::cout << lowRank << std::endl;
    lowRank.signForm(form);
    lowRank.executeForm(form);

    // Create a new form for the mid-rank test
    ShrubberyCreationForm form2("backyard");

    std::cout << "\n--- Testing with a mid-ranked bureaucrat ---" << std::endl;
    std::cout << midRank << std::endl;
    midRank.signForm(form2);
    midRank.executeForm(form2);

    // Create a new form for the high-rank test
    ShrubberyCreationForm form3("frontyard");

    std::cout << "\n--- Testing with a high-ranked bureaucrat ---" << std::endl;
    std::cout << highRank << std::endl;
    highRank.signForm(form3);
    highRank.executeForm(form3);

    // Test execution without signing
    ShrubberyCreationForm form4("park");
    std::cout << "\n--- Testing execution without signing ---" << std::endl;
    highRank.executeForm(form4);
}

void testRobotomyRequestForm() {
    std::cout << "\n===== TESTING ROBOTOMY REQUEST FORM =====\n" << std::endl;

    // Create a form
    RobotomyRequestForm form("Bender");
    std::cout << "Created form: " << form << std::endl;

    // Test with bureaucrats of different grades
    Bureaucrat highRank("CEO", 1);
    Bureaucrat midRank("Team Lead", 50);
    Bureaucrat lowRank("Junior", 100);

    std::cout << "\n--- Testing with a low-ranked bureaucrat ---" << std::endl;
    std::cout << lowRank << std::endl;
    lowRank.signForm(form);
    lowRank.executeForm(form);

    // Create a new form for the mid-rank test
    RobotomyRequestForm form2("C3PO");

    std::cout << "\n--- Testing with a mid-ranked bureaucrat ---" << std::endl;
    std::cout << midRank << std::endl;
    midRank.signForm(form2);
    midRank.executeForm(form2);

    // Create a new form for the high-rank test
    RobotomyRequestForm form3("R2D2");

    std::cout << "\n--- Testing with a high-ranked bureaucrat ---" << std::endl;
    std::cout << highRank << std::endl;
    highRank.signForm(form3);

    // Test multiple robotomies to show the 50% success rate
    std::cout << "\n--- Testing multiple robotomies to show 50% success rate ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Attempt " << i + 1 << ": ";
        highRank.executeForm(form3);
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n===== TESTING PRESIDENTIAL PARDON FORM =====\n" << std::endl;

    // Create a form
    PresidentialPardonForm form("Arthur Dent");
    std::cout << "Created form: " << form << std::endl;

    // Test with bureaucrats of different grades
    Bureaucrat highRank("President", 1);
    Bureaucrat midRank("Senator", 20);
    Bureaucrat lowRank("Citizen", 50);

    std::cout << "\n--- Testing with a low-ranked bureaucrat ---" << std::endl;
    std::cout << lowRank << std::endl;
    lowRank.signForm(form);
    lowRank.executeForm(form);

    // Create a new form for the mid-rank test
    PresidentialPardonForm form2("Ford Prefect");

    std::cout << "\n--- Testing with a mid-ranked bureaucrat ---" << std::endl;
    std::cout << midRank << std::endl;
    midRank.signForm(form2);
    midRank.executeForm(form2);

    // Create a new form for the high-rank test
    PresidentialPardonForm form3("Marvin");

    std::cout << "\n--- Testing with a high-ranked bureaucrat ---" << std::endl;
    std::cout << highRank << std::endl;
    highRank.signForm(form3);
    highRank.executeForm(form3);
}

void testEdgeCases() {
    std::cout << "\n===== TESTING EDGE CASES =====\n" << std::endl;

    // Create forms
    ShrubberyCreationForm shrub("test");
    RobotomyRequestForm robot("test");
    PresidentialPardonForm pardon("test");

    // Test with bureaucrat that can sign but not execute
    Bureaucrat signOnly("SignOnly", 25);
    std::cout << "\n--- Testing with bureaucrat that can sign but not execute Presidential Pardon ---" << std::endl;
    signOnly.signForm(pardon);
    signOnly.executeForm(pardon);

    // Test with a bureaucrat at the exact grade boundaries
    Bureaucrat exactGradeRobot("ExactGrade", 45);
    std::cout << "\n--- Testing with bureaucrat at the exact grade needed for RobotomyRequestForm ---" << std::endl;
    exactGradeRobot.signForm(robot);
    exactGradeRobot.executeForm(robot);

    // Attempt to execute unsigned forms
    Bureaucrat exec("Executor", 1);
    ShrubberyCreationForm unsignedShrub("unsigned");
    std::cout << "\n--- Testing execution of an unsigned form ---" << std::endl;
    exec.executeForm(unsignedShrub);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try {
        testShrubberyCreationForm();
        testRobotomyRequestForm();
        testPresidentialPardonForm();
        testEdgeCases();

        std::cout << "\n===== ALL TESTS COMPLETED =====\n" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
