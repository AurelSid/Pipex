Pipex

"Pipex" is a command-line utility designed to emulate the behavior of Unix pipes in a simplified manner. The project’s primary goal is to demonstrate an understanding of Unix pipe mechanisms by implementing a program that mimics the shell pipeline operations. Specifically, "Pipex" takes four arguments: two files and two shell commands. It processes the content of the first file through the first command, pipes the output of that command into the second command, and writes the final output to the second file.

Key Features:

Handles input and output redirection using Unix pipes.
Executes commands and manages their input/output streams correctly.
Ensures error handling and memory management to prevent crashes and leaks.
Example Usage:
Running ./pipex infile "ls -l" "wc -l" outfile will read from infile, execute ls -l, pipe the output to wc -l, and save the result to outfile.

Bonus Features:

Supports multiple pipe stages, allowing for a chain of commands.
Implements here-documents for more complex redirections.
"Pipex" showcases the ability to work with low-level Unix functionalities and manage process communication through pipes, simulating complex shell operations in C.
