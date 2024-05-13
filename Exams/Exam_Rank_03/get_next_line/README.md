<h1 align="center">Exam Rank 03: Get Next Line</h1>

<p align="center"><img src="https://github.com/jandrana/get_next_line/blob/main/.github/gnlbanner.png" alt="Get Next Line banner"/></p>

<p align="justify">The <strong>Get Next Line (GNL)</strong> is a function developed in C that reads text from a certain file descriptor (fd) and returns one line at a time when calling the get_next_line function.<br><br>It is very important to
make sure that the function doesn´t have any memory leaks of any kind or the function will not pass the exam.</p>

<p align="justify"><strong>Important Note:</strong> ⚠️ In the exam it is <strong>very important</strong> to avoid any kind of memory leaks, since it won't matter if the function works properly in every case if there is one or more memory leaks.</p>

To make sure that there are no leaks in your get_next_line, you can check it using the strict version of the **[Francinette](#testing)** (with francinette -s). Even though passing the strict version is not necessary when delivering the get_next_line project, it is necessary if you want to pass the exam.

## Project Structure

- [`get_next_line.c`](./get_next_line.c): Includes all the functions necessary for the implementation of the get_next_line.
- [`get_next_line.h`](./get_next_line.h): Header file for defining used libraries, function prototypes and constants like <code>BUFFER_SIZE</code>


## Get Next Line Versions

I have uploaded two different versions for the development of the get_next_line function, both versions pass successfully the exam and do not have any memory leaks.

The get_next_line exam was generating a lot of problems in my campus, because a lot of people were trying to pass the exam with a working GNL but they were not passing it because of the memory leaks (their version of gnl passed the project but not the exam nor the strict francinette tester). This is exactly what encouraged me to upload 2 different explained versions of my gnl.

### Long Version
The **long_version** of the get_next_line includes a more readable and understandable version.
- It casts every **malloc** as good practice and uses sizeof(char) * num_char, even though the cast is not necessary and neither is the sizeof(char), since it is always equal to 1.
	- Example of two mallocs that do the exact same thing:
		- string = (char *)malloc(sizeof(char) * num_char + 1);
		- string = malloc(num_char + 1);

- In this version, when copying a string (or part of it) it always does it by iterating each character one by one in each function.
	- Example of copying s1 into s2 with this version:
		- ```c
			i = -1;
			while (s1[++i])
				s2[i] = s1[i];
			s2[i] = '\0';
- It also makes some comprobations that would be needed in order for every function to work with any possible input, even though those comprobations are not needed because you will never call those functions in those special cases.
	- Example: in the **ft_substr** that if the starting point of the string + the lenght of the substr that we are going to create is greater that the total length of the original string (str), then we update the len to be the maximum possible: 
		```bash
		if (start + len > str_len)
			len = str_len - start;
		```
		This is not really necessary because when we call **ft_substr** for updating the buffer in the **get_result_buffer** function, we are already sending the correct len, because we pass the len as the length of the string minus the position where is going to start see:
		```bash
		buffer = ft_substr(temp, nl_pos, ft_strlen(temp) - nl_pos)
		```

### Short Version
The **short_version** of the get_next_line includes a shorter but also careless and less logical version.
- Instead of following the good practice of malloc, it does the shortest possible malloc (it doesn´t cast the malloc and doesn´t multiply the sizeof(char) with the number of chars). Example: 
	- ```c
		string = malloc(num_chars + 1)
- Furthermore, instead of copying a string (or part of it) by iterating each character one by one in every function, it calls a new function called gln_strcpy (which is my own version of the strcpy) to make those copies. This function receives three arguments:
	- **dst** Destination string, **src** Source string (From the first character to copy) and **len** number that represents how many characters you want to copy into dst from source. 
	- **If len is <= 0**, then it copies until the end of the string. 
	- **If it is any other positive number**, then it will stop copying until it reaches len characters copied or until it reaches the end of the src string (whichever happens first).
	- Finally, this function also adds the **null character** to the end of the dst string
	- Example of copying the whole s1 string to the empty previously allocated join string and concatenating the whole s2 string into the end of the join string.
		```c
		gnl_strcpy(join, s1, 0);
		gnl_strcpy(join + ft_strlen(s1), s2, 0);
		```
		If you want to see this example in action, is taken from the **gnl_strjoin** function.
- Finally, this version doesn´t include those unnecessary comprobations that we use in the long_version and that we know that are never going to happen because we never use those function in the cases where there is an undefined behaviour.

<h6 align="center">See each version header file for meticously explained functions</h6>


### Supported Platforms

- **Linux**
- **macOS**

### Prerequisites

Before using Get Next Line, you need:

- **GCC**: The GNU Compiler Collection.

### Testing

If you want to check that each version passes the strict francinette tester,
make sure to divide the get_next_line.c into two files (get_next_line_utils.c and get_next_line.c). It doesn´t matter which functions you add to each file, it is only for the tester to compile correctly.

In the get_next_line_utils.c add 5 functions from the get_next_line.c and add the #include "get_next_line.h".

Make sure to install the francinette tester:
- [Francinette](https://github.com/xicodomingues/francinette)

After dividing the project in two files and installing the francinette, use the tester by doing the following in the terminal (make sure to be in each versions folder)

- ```bash
	short_version % pwd
	..../short_version/
- ```bash
	short_version % francinette -s
<br>

**Important Note:** ⚠️ If you get **KO Timeout** when using the francinette strict tester
with BUFFER_SIZE 10 in the 4th test of giant_line.txt and 5th test of giant_line_nl.txt, do not worry, the creator of the tester informed of this "error" on his github and it is caused by how its tester is made when checking the malloc protection of each call to malloc. He said that it is not optimized enough and that if you only get timeout on those two cases you should not worry (see his last [FAQ](https://github.com/xicodomingues/francinette?tab=readme-ov-file#faq) if you want to check it out).


### Main Example

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    // Open file for reading
    fd = open("file.txt", O_RDONLY);

    if (fd1 == -1 )
    {
        printf("Error opening files\n");
        return (1);
    }
    // Read and print first line from fd
    line = get_next_line(fd1);
    if (line)
    {
        printf("From fd: %s\n", line);
        free(line);
    }

    line = get_next_line(fd1);
    if (line)
    {
        printf("From fd: %s\n", line);
        free(line);
    }

    // Close the files
    close(fd1);
    close(fd2);

    return 0;
}
```
**Output of Main:**
```sh
From fd: This is the first line from file.txt
From fd: This is the second line from file.txt
```
