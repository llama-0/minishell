# minishell
42 Project in a Unix learning curve

(for MacOS)

## How to build

```
make
```

## How to run

```
./minishell
```

If you wish to run the program under valgrind, you have two options:

* `make val` will generate valgrind-out.txt file with all info about possible leaks
* `make valgr` will run program under valgrind in interactive mode

(take a look at Makefile for further details) 

## How to exit minishell?

```
exit
```

This is a simplest realization of a shell program, key features of which are:
- buildins
  - echo
  - cd
  - setenv
  - unsetenv
  - env
  - exit
- expansions
  - $
  - ~
- error handling
  
Bonus feature: management of `;`

To make parsing of commands easier I've build a **dictionary** data structure based on linked list.
