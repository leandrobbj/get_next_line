# Get Next Line &nbsp;![language](https://img.shields.io/badge/language-444444?style=flat-square&logo=c&labelColor=555555) ![makefile](https://img.shields.io/badge/make-444444?style=flat-square&logo=monster&logoColor=goldenrod&labelColor=555555) ![42](https://img.shields.io/badge/lisboa-444444?style=flat-square&logo=42&logoColor=black&labelColor=777777)

*This project has been created as part of the 42 curriculum by lbraga.*

**Get_Next_Line** reads a text file from a file descriptor, one line at a time, until the end of the file is reached. The goal is to return the next available line on each call while keeping any unread data available for the next invocation. This project introduces the use of **static variables** in C to preserve state between function calls.

1. [Algorithm](#algorithm)
2. [Instructions](#instructions)
3. [Resources](#resources)
4. [AI Disclosure](#ai-disclosure)
5. [Final Notes](#final-notes)

## Algorithm

The core of the algorithm is a static `char buffer[BUFFER_SIZE + 1]`. Because it is static, it works as a cache that stores any leftover data read from a file descriptor that was not part of the previously returned line. 

### Algorithm Flow

* **Initialization:** `get_next_line` first checks whether the static buffer already contains leftover data from a previous call. If it does, that content is appended to the current line using `join_free_line`.

* **Reading:** If the line is not complete yet, `find_line` keeps calling `read()` to fill the buffer. After each read, the new data is concatenated to the line until a `\n` is found or the end of the file is reached.

* **Cleanup:** Once reading is complete, `clean_line` finds the newline with `ft_strchr` and terminates the returned string there. If extra data remains after the newline, it is shifted to the front of the static buffer so it can be used on the next call to `get_next_line`.

## Instructions

The project must be compiled with the `-D BUFFER_SIZE=n` flag to define the buffer size used by `read()`. You can change `BUFFER_SIZE` as needed.

* Compiling:

  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o program_name
	```
* Execution:

		./program_name

<p align="right"> <i>*your_main and program_name are only reference names for your own files</i>

## Resources

* [CS50: Introduction to Computer Science](https://pll.harvard.edu/course/cs50-introduction-computer-science) - Harvard University's lectures on C programming, memory management, and algorithms.
* [Linux Programmer's Manual (man pages)](https://man7.org/linux/man-pages/) - Specifically for read.
* [Norminette Documentation](https://github.com/42School/norminette) - Helpful for ensuring the code follows the school's coding standards.

##  AI Disclosure

In accordance with the 42 curriculum guidelines,  AI tools focusing help my understanding of fundamental concepts such as static variables and file descriptor management and summarize the behavior of the function `read()`.

The AI also helped with test development to identify potential logic bugs and edge cases during the implementation of complex functions, and supported the organization and formatting of project configuration files.

## Final Notes

Developing get_next_line was a significant challenge that introduced me to the power of static variables for data persistence. Using a fixed-size buffer allowed for an efficient algorithm that minimizes memory fragmentation and prevents leaks. 

This project also taught me to manage dynamic line growth and file descriptors, ensuring that every call reads only what is necessary to return a complete line. Ultimately, it was about building a deeper understanding of memory and logic to create a robust tool for my future projects at 42.
