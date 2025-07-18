# C++ Module 05

## 📘 Project Overview
 
**C++ Module 05** is a project from the 42 curriculum focused on **Repetition and Exceptions**. Its goal is to introduce exception handling in C++ through the implementation of a bureaucratic system with forms, bureaucrats, and exception management.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Exercise 00 – Bureaucrat](#exercise-00--bureaucrat)
- [Exercise 01 – Form up, maggots!](#exercise-01--form-up-maggots)
- [Exercise 02 – No, you need form 28B, not 28C...](#exercise-02--no-you-need-form-28b-not-28c)
- [Exercise 03 – At least this beats coffee-making](#exercise-03--at-least-this-beats-coffee-making)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Learn exception handling in C++
- Understand try/catch blocks and custom exceptions
- Implement inheritance and abstract classes
- Practice Orthodox Canonical Form
- Build a bureaucratic system with forms and bureaucrats

---

## General Requirements

- Written in **C++98**, following Orthodox Canonical Form
- Compile with `c++` and flags `-Wall -Wextra -Werror -std=c++98`
- No memory leaks or undefined behavior
- Global variables and `using namespace` are **forbidden**
- Exception classes do not need to follow Orthodox Canonical Form
- All other classes must follow Orthodox Canonical Form
- Use C++-style functions instead of C equivalents

### Makefile

Must include rules:
- `all`, `clean`, `fclean`, `re`, `$(NAME)`

---

## Exercise 00 – Bureaucrat

**Goal:** Create the foundation of the bureaucratic system with a Bureaucrat class.

### Requirements

Create a `Bureaucrat` class with:
- **Constant name**
- **Grade** ranging from 1 (highest) to 150 (lowest)
- **Getters:** `getName()` and `getGrade()`
- **Member functions:** increment and decrement grade
- **Custom exceptions:**
  - `Bureaucrat::GradeTooHighException`
  - `Bureaucrat::GradeTooLowException`

### Key Features

- Constructor throws exceptions for invalid grades
- Grade increment/decrement throws exceptions if out of range
- Overloaded insertion operator (`<<`) for output format:
  ```
  <name>, bureaucrat grade <grade>.
  ```
- Exceptions must be catchable with `try/catch` blocks

---

## Exercise 01 – Form up, maggots!

**Goal:** Add forms that bureaucrats can sign.

### Requirements

Create a `Form` class with:
- **Constant name**
- **Boolean signed status** (false at construction)
- **Constant grade required to sign**
- **Constant grade required to execute**
- **Custom exceptions:**
  - `Form::GradeTooHighException`
  - `Form::GradeTooLowException`

### Key Features

- `beSigned(Bureaucrat)` member function
- `signForm()` member function in Bureaucrat class
- Proper error messages for signing attempts
- Overloaded insertion operator for form information

---

## Exercise 02 – No, you need form 28B, not 28C...

**Goal:** Create concrete form types and implement form execution.

### Requirements

Rename `Form` to `AForm` (abstract base class) and create:

#### Concrete Form Classes

1. **ShrubberyCreationForm**
   - Required grades: sign 145, exec 137
   - Creates `<target>_shrubbery` file with ASCII trees

2. **RobotomyRequestForm**
   - Required grades: sign 72, exec 45
   - Makes drilling noises, 50% success rate for robotomy

3. **PresidentialPardonForm**
   - Required grades: sign 25, exec 5
   - Announces presidential pardon by Zaphod Beeblebrox

### Key Features

- `execute(Bureaucrat const & executor) const` in base class
- `executeForm(AForm const & form)` in Bureaucrat class
- All forms take target parameter in constructor
- Proper execution validation and error handling

---

## Exercise 03 – At least this beats coffee-making

**Goal:** Implement an Intern class that can create forms dynamically.

### Requirements

Create an `Intern` class with:
- **No name, grade, or unique characteristics**
- `makeForm(string formName, string target)` function
- Returns pointer to appropriate form type
- Handles invalid form names gracefully

### Key Features

- Supports all three form types from Exercise 02
- Prints creation confirmation: `Intern creates <form>`
- Avoids excessive if/else structures (use elegant solution)
- Proper error handling for unknown form names

### Example Usage

```cpp
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
```

---

## Implementation Notes

### Exception Handling

- Use standard C++ exception hierarchy
- Implement custom exception classes for each error type
- Ensure exceptions are properly caught and handled
- Provide meaningful error messages

### Design Patterns

- Use inheritance for form hierarchy
- Implement abstract base class properly
- Follow SOLID principles
- Avoid code duplication

### Memory Management

- Properly manage dynamic memory allocation
- Avoid memory leaks
- Use appropriate destructors
- Consider RAII principles

---

## Testing

Create comprehensive tests for:
- Bureaucrat grade validation
- Form signing and execution
- Exception handling
- Intern form creation
- Edge cases and error conditions

---

## Submission Guidelines

- Code must be submitted to the assigned Git repository
- Only repository contents will be evaluated
- Ensure correct file and folder naming
- Include all required files for each exercise
- Test thoroughly before submission

---

## Final Note

This project introduces essential C++ concepts including exception handling, inheritance, and polymorphism. Understanding these concepts is crucial for advanced C++ programming and object-oriented design.

---
