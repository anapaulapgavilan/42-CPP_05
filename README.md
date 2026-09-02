# CPP_05

![42](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white) ![Language](https://img.shields.io/badge/lang-C++98-blue?style=flat-square) ![Status](https://img.shields.io/badge/status-completed-success?style=flat-square)

42 School C++ module 05: exceptions and bureaucratic form processing flow.

## About This Project

### What It Does

This module simulates a bureaucratic form-signing office: a "Bureaucrat" with a numeric grade signs and executes different kinds of "Form" objects, and every invalid operation throws a custom exception instead of silently failing.

Exercises in this module:
- ex00: the Bureaucrat class with a bounded grade (1-150) and grade-too-high/too-low exceptions.
- ex01: an abstract Form base plus a concrete ShrubberyCreationForm, with sign/execute rules based on grade.
- ex02: an abstract AForm base with three concrete forms (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm), each with different side effects and grade requirements.
- ex03: adds an Intern class that can produce the right AForm subclass from a string name, without the caller knowing the concrete type.

### Purpose

It evaluates custom exception classes, abstract base classes with pure virtual methods, and a simple factory pattern, all wired together through a realistic sign/execute workflow.

## Stack

- School: 42
- Primary language: C++98
- Scope: one repository per project

## Skills Demonstrated

`Exception handling` | `Abstract base classes` | `Factory pattern`

## Features

- Custom exception classes for every invalid bureaucratic operation
- Abstract Form hierarchy with concrete forms and grade-based sign/execute rules
- Intern factory that builds the right form type from a string name

## Review Focus

- Look for exception paths that report invalid grades and unauthorized execution clearly.
- Review the AForm hierarchy for clean separation between shared workflow and concrete side effects.
- Notice the factory-style Intern flow, which converts user-facing names into concrete form objects.

## Project Deep Dive

CPP_05 models a small permission-based workflow: bureaucrats sign and execute forms only if their grade allows it. That makes exceptions useful instead of decorative, because invalid operations must be reported clearly and consistently.

The later exercises add concrete form subclasses and an Intern factory. This turns the module into a compact example of workflow design: shared validation in the base type, specific behavior in derived forms, and object creation hidden behind a simple interface.

## Implementation Notes

- Encodes grade boundaries and invalid operations as explicit exception paths.
- Uses abstract form classes to separate common sign/execute rules from concrete side effects.
- Applies a simple factory approach so callers can request forms by name without knowing subclasses.

## Structure

| Exercise | Path | Binary |
|---|---|---|
| ex00 | ./ex00 | bureaucrat |
| ex01 | ./ex01 | forms |
| ex02 | ./ex02 | aforms |
| ex03 | ./ex03 | intern |

## How to Run

Prerequisites: `make` and a C++98-capable compiler (`g++` or `clang++`).

Compile and run each exercise separately:

### ex00

~~~bash
cd ex00
make
./bureaucrat
~~~

### ex01

~~~bash
cd ex01
make
./forms
~~~

### ex02

~~~bash
cd ex02
make
./aforms
~~~

### ex03

~~~bash
cd ex03
make
./intern
~~~

## Testing

No dedicated testing scripts were detected at the project root.

## Notes

- This repository is part of the 42 portfolio.
- Commands are intended for local execution for review and evaluation.

## Author

anapaulapgavilan
