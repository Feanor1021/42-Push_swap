# Push_swap

## Overview

Push_swap is a sorting algorithm project that consists of two programs: `push_swap` and `checker`. The `push_swap` program takes a list of integers as input, and uses a set of operations to sort the list in ascending order. The `checker` program takes the same list of integers and a set of operations as input, and checks whether the list is sorted correctly using those operations.

## Usage

To compile the programs, run `make` in the root directory of the project. This will generate the `push_swap` and `checker` executables in the same directory.

To use the `push_swap` program, run `./push_swap <list>` where `<list>` is a space-separated list of integers to be sorted. The program will output a list of operations to sort the list in ascending order.

To use the `checker` program, run `./checker <list> <operations>` where `<list>` is the same list of integers used by the `push_swap` program, and `<operations>` is a space-separated list of operations to be performed on the list. The program will output either `OK` if the list is sorted correctly, or `KO` if it is not.

## Operations

The following operations are available:

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: do `sa` and `sb` simultaneously
- `pa`: take the first element from stack B and put it on top of stack A
- `pb`: take the first element from stack A and put it on top of stack B
- `ra`: shift all elements of stack A up by one
- `rb`: shift all elements of stack B up by one
- `rr`: do `ra` and `rb` simultaneously
- `rra`: shift all elements of stack A down by one
- `rrb`: shift all elements of stack B down by one
- `rrr`: do `rra` and `rrb` simultaneously

## Example

    $> ./push_swap 5 2 4 3 1
    ra pb pb ra pa pa pa
    $> ./checker 5 2 4 3 1 ra pb pb ra pa pa pa
    OK

In this example, `push_swap` takes the list `5 2 4 3 1` as input and outputs a list of operations to sort it: `ra pb pb ra pa pa pa`. The `checker` program is then used to check whether the list is sorted correctly using those operations, and it outputs `OK` indicating that it is.



code for the pyviz.py file is:

    python3 pyviz.py `ruby -e "puts (1..499).to_a.shuffle.join(' ')"`
