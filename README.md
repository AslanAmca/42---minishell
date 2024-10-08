# Minishell

**Minishell** is a project from Ecole 42 that focuses on building a minimal shell program in C. The goal of the project is to implement a basic command line interface capable of executing commands, managing environment variables, and supporting input/output redirection.

## Project Overview

In this project, you will create a shell that can interpret user commands and execute them. The shell should support various built-in commands and handle processes through the `fork`, `exec`, and `wait` system calls.

## Objectives

- To understand how a shell works and how it interacts with the operating system.
- To gain experience in process management and execution in C.
- To learn about handling strings, parsing commands, and managing environment variables.
- To implement features like input/output redirection and piping.

## Features

- **Command Execution**: Execute commands entered by the user.
- **Built-in Commands**: Implement essential built-in commands such as `cd`, `echo`, `exit`, and others.
- **Environment Variables**: Support for managing and manipulating environment variables.
- **Input/Output Redirection**: Handle input/output redirection using `<` and `>` operators.
- **Piping**: Implement piping functionality with the `|` operator to connect commands.

## How to Use

1. **Compiling the Project**:
	Use `make` to compile the shell program:
	```bash
	make
	```

2. Running the Shell:
	```bash
	./minishell
	```

3. Using Commands
