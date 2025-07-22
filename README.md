# C++ Module 05

![42 Badge](https://img.shields.io/badge/42-CPP--Module--05-brightgreen)
![C++ Badge](https://img.shields.io/badge/Language-C%2B%2B98-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)

## What I Learned

Through this advanced C++ project at 42 School, I developed crucial object-oriented programming skills and exception handling expertise:

- **Exception handling mechanisms** - Mastered try/catch blocks and custom exception class hierarchies
- **Inheritance and polymorphism** - Implemented abstract base classes with pure virtual functions
- **Orthodox Canonical Form** - Applied proper constructor, destructor, copy constructor, and assignment operator patterns
- **Custom exception design** - Created meaningful exception classes with proper inheritance from std::exception
- **Abstract class implementation** - Designed and implemented abstract base classes with concrete derived classes
- **Polymorphic behavior** - Used virtual functions to achieve runtime polymorphism
- **RAII principles** - Applied Resource Acquisition Is Initialization for proper resource management
- **Error propagation** - Implemented robust error handling that propagates meaningful error information
- **Factory pattern basics** - Created dynamic object instantiation through the Intern class
- **C++98 standard compliance** - Worked within older C++ standards while maintaining modern design principles

This project strengthened my understanding of advanced OOP concepts, error handling strategies, and design patterns essential for robust C++ applications.

## About the Project

C++ Module 05 focuses on **Repetition and Exceptions** through a bureaucratic system simulation. The project implements a hierarchy of forms and bureaucrats with comprehensive exception handling, demonstrating:

- Custom exception class hierarchies
- Abstract base classes and inheritance
- Polymorphic behavior through virtual functions
- Proper resource management and error handling
- Factory pattern implementation

## Implementation Details

The project consists of four progressive exercises that build a complete bureaucratic system:

### Exercise 00: Bureaucrat Foundation

Core bureaucrat class with grade validation and custom exceptions:

| Class | Features | Grade Range |
|-------|----------|-------------|
| **Bureaucrat** | Name (const), Grade validation | 1 (highest) to 150 (lowest) |
| **Exceptions** | GradeTooHighException, GradeTooLowException | Custom error messages |

**Key Methods:**
- `incrementGrade()` - Improves rank (decreases number)
- `decrementGrade()` - Worsens rank (increases number)
- Stream insertion operator for formatted output

### Exercise 01: Form System

Introduction of forms that bureaucrats can sign:

| Class | Features | Validation |
|-------|----------|------------|
| **Form** | Name (const), Signed status, Required grades | Sign/Execute grade validation |
| **Integration** | beSigned(), signForm() methods | Proper error handling and messaging |

**Interaction Flow:**
- Bureaucrat attempts to sign form via `signForm()`
- Form validates bureaucrat's grade through `beSigned()`
- Success/failure messages with clear reasoning

### Exercise 02: Concrete Form Types

Abstract base class with three specialized form implementations:

| Form Type | Sign Grade | Exec Grade | Action |
|-----------|------------|------------|--------|
| **ShrubberyCreationForm** | 145 | 137 | Creates ASCII tree file |
| **RobotomyRequestForm** | 72 | 45 | 50% success robotomy with sound effects |
| **PresidentialPardonForm** | 25 | 5 | Presidential pardon announcement |

**Abstract Design:**
- `AForm` base class with pure virtual `executeAction()`
- Common execution validation in base class
- Specialized behavior in derived classes

### Exercise 03: Dynamic Form Creation

Factory pattern implementation through the Intern class:

```cpp
// Dynamic form creation
Intern intern;
AForm* form = intern.makeForm("robotomy request", "Bender");
```

**Supported Forms:**
- "shrubbery creation" → ShrubberyCreationForm
- "robotomy request" → RobotomyRequestForm  
- "presidential pardon" → PresidentialPardonForm

## Usage

```bash
# Navigate to specific exercise
cd CPP_Module_05/ex00  # or ex01, ex02, ex03

# Compile the project
make

# Run the executable
./bureaucrat  # or ./form, ./aform, ./intern

# Clean build files
make clean

# Remove all generated files
make fclean

# Rebuild
make re
```

## Code Architecture

### Exception Hierarchy

```cpp
std::exception
    └── Bureaucrat::GradeTooHighException
    └── Bureaucrat::GradeTooLowException
    └── AForm::GradeTooHighException
    └── AForm::GradeTooLowException
    └── AForm::FormNotSignedException
    └── Intern::UnknownFormException
```

### Class Inheritance

```cpp
AForm (Abstract)
    ├── ShrubberyCreationForm
    ├── RobotomyRequestForm
    └── PresidentialPardonForm
```

### Integration Example

```cpp
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create high-ranking bureaucrat
        Bureaucrat president("Alice", 1);
        
        // Create presidential pardon form
        PresidentialPardonForm pardon("Bob");
        
        // Sign and execute the form
        president.signForm(pardon);
        president.executeForm(pardon);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

## Technical Challenges Overcome

- **Exception safety** - Ensuring proper cleanup and state consistency when exceptions occur
- **Abstract class design** - Balancing common functionality in base class vs. specialized behavior
- **Const correctness** - Proper use of const methods and const member variables
- **Memory management** - Preventing leaks in factory pattern with dynamic allocation
- **Polymorphic destruction** - Virtual destructors for proper cleanup of derived objects
- **Grade logic inversion** - Managing the counter-intuitive grade system (1=best, 150=worst)
- **Factory pattern implementation** - Creating clean, extensible object creation without excessive conditionals
- **Exception propagation** - Maintaining meaningful error information through call stack

## Design Patterns Applied

- **Template Method Pattern** - Common execution validation with specialized actions
- **Factory Pattern** - Dynamic form creation through Intern class
- **Exception Hierarchy** - Structured error handling with meaningful exception types
- **RAII** - Resource management through proper constructor/destructor design

---

*This project was completed as part of the 42 School curriculum, demonstrating proficiency in advanced C++ concepts including exception handling, inheritance, polymorphism, and design patterns.*

---

## License

This project is licensed under the [MIT License](./LICENSE).
