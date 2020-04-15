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
|------------|--------|-------------------------------------------------|
|Simple_Shell|  main  |The starting point of the program shell			| 
|            |controlc|handle to avoid exitting with ctrl+c   			|
|_getline    |_getchar|function to read characters from the STDIN_FILENO|
|			 |_getline|function to reads a line from the STDIN_FILENO and holds it in a buffer.|
|built-ins  |




 - PID & PPID
 - Arguments
 - Executing a program
 - Creating processes
 - Wait
 - File information
 - Environment

## Basic lifetime of a shell

A shell does three main things in its lifetime.
```
 - Initialize: In this step, a typical shell would read and execute its configuration files.
 These change aspects of the shell’s behavior.

 - Interpret: Next, the shell reads commands from stdin (which could be interactive, or a
 file) and executes them.
	*	Read: Read the command from standard input.
	*	Parse: Separate the command string into a program and arguments.
	*	Execute: Run the parsed command.

 - Terminate: After its commands are executed, the shell executes a shutdown command
 frees up the memory, and terminates.
```
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


Versioning
We use SemVer for versioning. For the versions available, see the tags on this repository.


License
This project is licensed under the MIT License - see the LICENSE.md file for details
