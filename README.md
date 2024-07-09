# Push_swap

## Description

The `push_swap` project involves writing a program that sorts a stack of integers using a minimal set of operations. This exercise aims to enhance understanding of sorting algorithms and their complexity, which are essential topics in computer science and common in job interviews.

## Objectives

- Implement sorting algorithms focusing on their efficiency.
- Use the C programming language and comply with the Norm.
- Ensure proper memory management and avoid common errors (segmentation fault, bus error, double free, etc.).

## Rules

- There are two stacks named `a` and `b`.
- Stack `a` contains a random amount of unique integers at the beginning.
- Stack `b` is initially empty.
- The goal is to sort the integers in stack `a` in ascending order using the following operations:

  - `sa`: Swap the first two elements of `a`.
  - `sb`: Swap the first two elements of `b`.
  - `ss`: `sa` and `sb` at the same time.
  - `pa`: Push the first element of `b` to the top of `a`.
  - `pb`: Push the first element of `a` to the top of `b`.
  - `ra`: Rotate all elements of `a` up by one.
  - `rb`: Rotate all elements of `b` up by one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra`: Reverse rotate all elements of `a` down by one.
  - `rrb`: Reverse rotate all elements of `b` down by one.
  - `rrr`: `rra` and `rrb` at the same time.

## Program Requirements

- The program must be named `push_swap`.
- It must take as an argument the stack `a` formatted as a list of integers.
- The program should output the smallest list of operations to sort the stack `a`.
- Each operation must be followed by a newline (`\n`).
- The program must handle errors gracefully, such as non-integer arguments, integers out of range, and duplicate values.

## Usage

### Compiling the Program

To compile the program, run:

```sh
make

Running the Program
To run the program with a list of integers:

./push_swap [list of integers]
Example: ./push_swap 2 1 3 6 5 8

Error Handling
If an error occurs, the program will output "Error" followed by a newline to the standard error.

Example:
./push_swap 0 one 2 3
Error

Benchmark
To validate the project:
* Sort 100 random numbers in fewer than 700 operations for a minimal grade of 80.
* Sort 500 random numbers in fewer than 5500 operations for maximal validation.

Makefile Targets
* all: Compile the program.
* clean: Remove object files.
* fclean: Remove object files and the executable.
* re: Recompile the program.
* bonus: Compile the bonus part (if applicable).

External Functions Used
* read
* write
* malloc
* free
* exit
* ft_printf or any equivalent custom function

Dependencies
Custom libft library (if used).
Ensure all sources and the associated Makefile are in the libft folder.

Author
This project was created by Ana Husic.

