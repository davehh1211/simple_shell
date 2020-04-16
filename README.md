# Simple Shell

A shell is a command-interpreter program useful for creating and executing programs. It reads a command typed by the user and execute them in response to that command and user intentions.

#### [Simple Shell](https://intranet.hbtn.io/projects/235)
For further information, click on the previous link. 

## Prerequisites

For further installation is necessary to set this program on Ubuntu 14.04 LTS using Vagrant in VirtualBox.

You need to install this software
```
1. VirtualBox - Virtual Machine
2. Vagrant
3. Emacs
4. Vim/Vi
5. VSCode
```

## Environment

This project was constructed and tested in the previous set up and debugged with GCC version 4.8.4.


## Instalation.
Follow the following instructions to get a copy of the program and run in your local machine.

- Clone the following repository. 
 > `https://github.com/julianfrancor/simple_shell.git`  

- Compile it with GCC 
 > `gcc -Wall -Werror -pedantic -Wextra -g`

- Run the program
 > `./executable_name`

 - Run with debugger
 > `valgrind --leak-check=full --show-leak-kinds=all ./executable_name`


## General Information and contents

|    File    |Function|Description                            			|
|-------------------|----------|-------------------------------------------------|
|Simple_Shell       |  main    |The starting point of the program shell			| 
|                   |controlc  |handles to avoid exitting with ctrl+c   			|
|_getline           |_getchar  |reads characters from the STDIN_FILENO|
|			        |_getline  |reads a line from the STDIN_FILENO and holds it in a buffer.|
|built-ins          |envbuilt  |prints the enviroment var|
|                   |_getenv   |gets the enviroment variable from environ|
|execute.c          |execute   |executes the cmdpath given by the user|
|memory_allocators.c|_malloc   |allocates memory using malloc.|
|                   |_calloc   |allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.|
|                   |_realloc  |creates an array of integers.|
|path_functions.c   |pathrunner|finds and runs the command given by the user|
|                   |pathfinder|finds the path of environment var|
|                   |pathgetter|extracts the full path of environment variable|
|                   |pathcommand|concatenates the path with the command|
|                   |count_dir  |counts the amount of directories.  |
|shellhead          |library    |contains all the different prototype to run the shell program|
|string_functions.c | _strdup   |returns a pointer to a newly allocated space in memory|
|                   |_strcmp    |compares two strings|
|                   |_strcpy    |writes the character c to stdout|
|                   |_strcat    |concatenates two strings|
|                   |_strlen    |counts the amount of characters in a string|
|string_handler.c   |_strspn    |gets the length of a prefix substring.|
|                   |_strcspn   |calculates the length of the initial segment of s which consists entirely of bytes not in reject.|
|                   |_strpbrk   |searches a string for any of a set of bytes.|
|                   | _strchr   |locates a character in a string.|
|string_tokenizer.c |tokenizer  |splits a string into tokens and place them in a double pointer.|
|                   |_strtok    |splits a string into words.|
|                   |_strtok_r  |breaks a string into a sequence of zero or more nonempty tokens|
|                   |count_words|counts the words in a string|

 - PID & PPID
 - Arguments
 - Executing a program
 - Creating processes
 - Wait
 - File information
 - Environment

## Basic lifetime of a shell


The main process or **init process**, or also called **parent process** creates more subsequent processes during execution. As soon as the shell starts, it prints a prompt and expects the user to type in a command to be executed.

#### 1. **Reading.**

When the user enters a command, the command is read by the function **_getlin** where stores the command line from the standard input in a buffer.

#### 2. **Parsing**

The shell splits this line with the **_strtok** function in the number of words entered until delimitator suh as **_\n\r\a\t**. These words or tokens are saved separately in an array of pointers and return each one to be executed.
> Check the String_handler and the string_tokenizer files. 

#### 3. **Executing**

 The shell checks the command path comes without a path. If it is the case, it finds the path of the command in the Environment variable, and concatenates it with the path found. 
 > Check the execute file

Then compares it with any built-in function to prove its existence of such word as a command. 
 > Check the execute file.

On the other hand, if the command comes with a path e.g: “/bin/ls -l”, it just has to check its existence as previously explained on this page. When the shell checks both cases, it executes the command using the function execve and makes the child process in order to run it as intended.
> Check the built-ins and string_functions file. 

#### 4. **Displaying**.
The program will execute the command with its subsequent arguments, displays all the content and returns 0 for the child process to close and free the memory allocated.

## Basic loop of a shell

The basic logic of the program: the shell has a loop that handle commands in three steps:

	*	Read: Read the command from standard input. (getline())
	*	Parse: Separate the command string into a program and arguments. (strtok())
	*	Execute: Run the parsed command. (fork() & execve())


## Built with...

- Visual Studio Code - Coding and structuring.
- Clion - Debugging and testing outcomes.

##  Authors

- [GitHub - Julian Franco Rua](https://github.com/julianfrancor)

- [GitHub - Oscar David Henao Hidalgo](https://github.com/davehh1211)

## Blogs - What Happens when we type the command `"ls -l"`

- [Blog - Julian Franco Rua](https://medium.com/@julianfrancor9/what-happens-when-you-type-ls-l-in-the-shell-959b39049f1)

- [Blog - Oscar David Henao Hidalgo](https://medium.com/@davelockly/what-happens-when-you-type-the-command-ls-l-b7dc459a868)
