# B4 - Synthesis Pool
## B-SYN-400

## The Empire Strikes Back (or do they?)

- **Binary Name:** empire
- **Language:** C
- **Compilation:** via Makefile, including re, clean, and fclean rules

## Overview

A group of Romans has dedicated themselves to a new project: conquering the last Gallic village resisting the Roman Empire, defended by Asterix and Obelix. In this project, they gather around a table to strategize and feast.

## Project Context

The project involves monitoring the conquest project using a provided library. No standard output printing is allowed; only the referred library can print a final report.

## Project Requirements

- N Romans gather around a table (N is defined on the command line).
- Each Roman has a dish in front of them.
- A fork is to the left of each dish.
- A Roman can only use a fork if it is to the left or right of their dish.
- Each Roman goes through three states: eat with two forks (left and right), rest (does not use either fork), and think (uses one fork).
- Additional rules for better digestion.
- A Roman who thinks must eat before resting.
- After resting, a Roman can either eat or think.
- The think and eat states take between 300 and 400 milliseconds.
- Forks cannot be used by two Romans simultaneously for hygienic reasons.

Each Roman is independent, running in separate threads without knowledge of the others.

## Usage

```bash
./empire -p nbr_p -e nbr_e

Options
    - `-p nbr_p`: Number of Romans.
    - `-e nbr_e`: Maximum number of times a Roman eats before exiting the program.
```
The program ends once each Roman has eaten the maximum number of times. It should always end normally if given enough time.

## Compilation

Compile the program using the provided Makefile, including the following rules:

```bash
make
make re
make clean
make fclean

```

