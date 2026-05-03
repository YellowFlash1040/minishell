# minishell

A simple Unix shell built in C that replicates core features of Bash, including command execution, piping, redirections, and environment variable handling.

This project is part of the 42 School curriculum and demonstrates proficiency in process management, file descriptors, parsing, and system calls.

## Prerequisites:

Before building the project, ensure you have the following installed:

- GNU Make
- GNU Compiler Collection (GCC)
- Readline library
- Standard Unix system libraries

Install missing prerequisites on Debian/Ubuntu-based systems:

```
sudo apt update && sudo apt install make gcc libreadline-dev
```

## Installation

1.  Clone the repository:

```
git clone https://github.com/YellowFlash1040/minishell
cd minishell
```

2.  Build the project:

```
make
```

This will create an executable named `minishell` in the project directory.

## Usage

Run the shell:

```
./minishell
```

Have fun!

### Supported Features

- Execution of system commands (e.g., `ls`, `echo`, `cat`)
- Handling of environment variables (`$PATH`, `$HOME`, etc.)
- Pipes (`|`) to chain commands
- Input/output redirections:
  - `>` redirect output
  - `>>` append output
  - `<` redirect input
  - `<<` heredoc
- Signal handling (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Built-in commands:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`

## Example

```
$> echo "Hello, world!"
Hello, world!
$> ls -l | grep minishell
-rwxr-xr-x 1 root root 77264 May  4 18:59 minishell
```

## Notes

- The shell follows Bash-like behavior but does not aim to fully replicate all features.
