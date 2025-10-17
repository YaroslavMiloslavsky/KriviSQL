# KriviSQL

Welcome to my SQL project!
<br>
The main goal here is to have fun and learn.

## Objective
My main goal is to create a simple DB structure with a query language in order to learn all the different methods of data retrieval and fetching.

## Running
### Prequisites
- GCC and the standard tool set, such as make, gdb and valgrind.
- Either Windows or Unix (Valgrind won't work on MS W)

### Commands
- make : makes the project
- make test : runs tests (I have built my own testing framework)
- make clean : erases all un-needed objects
- make valgrind : runs the CLI with valgrind output
- make testmem : runs the tests with valgrind output

### Examples:
- Running make valgrind:
```bash
gcc -c -Wall -Werror -pedantic -I header src/command.c -o command.o
gcc -g -Wall -Werror -pedantic command.o helper.o main.o -o KriviSQL
valgrind --leak-check=full --show-leak-kinds=all ./KriviSQL
==5600== Memcheck, a memory error detector
==5600== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5600== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==5600== Command: ./KriviSQL
==5600== 
 ---------- Welcome to Krivi SQL version 0.10 ----------
@Hey
@exit
@
Goodbye :) Do come again!
==5600== 
==5600== HEAP SUMMARY:
==5600==     in use at exit: 0 bytes in 0 blocks
==5600==   total heap usage: 6 allocs, 6 frees, 2,568 bytes allocated
==5600== 
==5600== All heap blocks were freed -- no leaks are possible
==5600== 
==5600== For lists of detected and suppressed errors, rerun with: -s
==5600== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
<br>

- Running make testmem:
```bash
gcc -c -Wall -Werror -pedantic -I header src/test.c -o test.o
gcc -c -Wall -Werror -pedantic -I header src/test_helper.c -o test_helper.o
gcc -c -Wall -Werror -pedantic -I header src/test_util.c -o test_util.o
gcc -g -Wall -Werror -pedantic test_util.o command.o helper.o test_helper.o test.o -o KriviSQL_testing
valgrind --leak-check=full --show-leak-kinds=all ./KriviSQL_testing
==6040== Memcheck, a memory error detector
==6040== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6040== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6040== Command: ./KriviSQL_testing
==6040== 
------------------ Running unit tests ------------------
test_is_blank_base_case
test_is_blank_non_empty_case
test_is_blank_null_case
test_clean_spaces_trailing_base_case
test_clean_spaces_blank_first_case
test_clean_spaces_both_ends_case
test_clean_spaces_non_spaces_case
test_clean_spaces_null_case
test_clean_spaces_new_line_case
test_clean_spaces_carriage_case
test_clean_spaces_tab_case
test_clean_spaces_space_case
------------------ Test End ------------------
==6040== 
==6040== HEAP SUMMARY:
==6040==     in use at exit: 0 bytes in 0 blocks
==6040==   total heap usage: 70 allocs, 70 frees, 5,575 bytes allocated
==6040== 
==6040== All heap blocks were freed -- no leaks are possible
==6040== 
==6040== For lists of detected and suppressed errors, rerun with: -s
==6040== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Conventions:
You may notice I am still not set on the conventions, so the code conventions might feel uneven right now.
<br>
I do try to use cammelCase, but for tests snake_case is more convenient.