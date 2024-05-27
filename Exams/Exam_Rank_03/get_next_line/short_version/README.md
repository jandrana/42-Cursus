<h1 align="center">Exam Rank 03 - Get Next Line Short Version</h1>

<p align="center"><img src="https://github.com/jandrana/get_next_line/blob/main/.github/gnlbanner.png" alt="Get Next Line banner"/></p>

## Project Structure

- [`get_next_line.c`](./get_next_line.c): Includes all the functions necessary for the implementation of the get_next_line.
- [`get_next_line.h`](./get_next_line.h): Header file for defining used libraries, function prototypes and constants like <code>BUFFER_SIZE</code>


## Function prototypes

<table align="center">
	<thead>
		<th>Prototype</th>
		<th>Description</th>
	</thead>
	<tbody>
		<tr>
			<td><code>char *free_str(char **str);</code></td>
			<td>Frees the pointer to the <code>str</code> string</td>
		</tr>
		<tr>
			<td><code>int ft_strlen(char *str);</code></td>
			<td>Returns the length of the <code>str</code> string</td>
		</tr>
		<tr>
			<td><code>void gnl_strcpy(char *dst, char *src, int len);</code></td>
			<td>Small variation of the original strcpy</td>
		</tr>
		<tr>
			<td><code>char *ft_strdup(char *str);</code></td>
			<td>Creates a duplicate of the <code>str</code> string</td>
		</tr>
		<tr>
			<td><code>char *ft_substr(char *str, int start, int len);</code></td>
			<td>Creates a copy of the <code>str</code> string of len length and starting from str[start]</td>
		</tr>
		<tr>
			<td><code>int gnl_strchr(char *str, int c);</code></td>
			<td>Small variation of the original strchr</td>
		</tr>
		<tr>
			<td><code>char *gnl_strjoin(char *s1, char *s2);</code></td>
			<td>Creates a new string resulting from the concatenation of s1 and s2</td>
		</tr>
		<tr>
			<td><code>char *get_result_buffer(char **buffer);</code></td>
			<td>Returns a string with the first line inside buffer and updates buffer</td>
		</tr>
		<tr>
			<td><code>char *add_buffer(char *buffer, int fd);</code></td>
			<td>Reads from the given file and adds it to the buffer</td>
		</tr>
		<tr>
			<td><code>char *get_next_line(int fd);</code></td>
			<td>Returns a string with the next line to return from the given file</td>
		</tr>
	</tbody><br>
</table>

## Function explanation

<h5>FREE_STR</h5>

```c
/**
 * @brief This function is intended to free the pointer of the
 * string str making sure that it has no leaks by freeing the pointer
 * to the string instead of the string itself
 * @param p_str Pointer to the string that is going to be freed
 * @return The function returns NULL since in most cases, when this
 * function is used, you also need to return NULL.
 * 
*/
char	*free_str(char **p_str)
{
	free(*p_str); // frees the pointer to the string
	*p_str = NULL; // asigns the pointer to the string to be NULL
	return (NULL); // returns NULL
}

char *usage_example(char *str)
{
	char *copy;

	copy = (char *)malloc(sizeof(strlen(str) + 1));
	copy = ft_strdup(str);
	if (!copy)
		return (free_str(&str)); // use the pointer to the string (&str)!
	// ....
}
```

<br><h5>FT_STRLEN</h5>

```c
/**
 * @brief This function calculates the length of the string passed
 * as argument. (Since this was for an exam, I did not take into account 
 * the norminette restrictions)
 * @param str string to iterate
 * @return The function returns the calculated length of the string.
 * 
*/
int	ft_strlen(char *str)
{
	int	i = -1;

	while (str[++i]); // iterate the string until it reaches its end
	return (i); // return the position where str ends
}

char *usage_example(char *str)
{
	int		str_length;

	str_length = ft_strlen(str); // Ex: str = "hello" -> str_length = 5;
	// ....
}
```

<br><h5>GNL_STRCPY</h5>

```c
/**
 * @brief **OPTIONAL FUNCTION** This function is a small variation of the 
 * original strcpy.
 * When the initial len is 0, it copies the whole string src into dst.
 * In any other case, it copies the string src into dst to a maximum of
 * len characters.
 * @param src string to copy into dst
 * @param dst string to update with src to a max of len chars 
 * @param len If initial len is 0 or < 0, the function will copy the whole string
 * src into dst. If initial len is > 0, the function will copy the whole string
 * src into dst to a maximum of len characters or to the end of the string.
 * @warning Before calling this function you need to make sure you allocated
 * just enogh memory for the dst string or you will have memory access problems.
 * @warning 
*/
void	gnl_strcpy(char *dst, char *src, int len)
{
	while (*src && --len) // while (the character that src is pointing to isn´t NULL) and (len = len - 1) is not 0
		*dst++ = *src++; // copy the character that src is pointing to, where dst is pointing
	*dst = '\0'; // add null character to the end of the string
}
```

<br><h5>FT_STRDUP</h5>

```c
/**
 * @brief This function is similar to the strcpy, but instead of receiving
 * dst as an argument, it creates the string duplicate and allocates enough
 * memory for it. Then calls gnl_strcpy with the arguments str (as src) and
 * duplicate (as dst). Since we want to copy the whole string str, we call
 * gnl_strcpy with 0 as len.
 * @param str string to copy into the newly created string (called duplicate)
 * @return The function returns the "duplicate" string after creating it,
 * allocating enough memory for it and copying str into it. If the allocation
 * fails (malloc), we protect the string returning NULL.
*/
char	*ft_strdup(char *str)
{
	char	*duplicate; // Creates a new string called duplicate

	duplicate = malloc(ft_strlen(str) + 1); // Allocates memory for duplicate to have a copy of str
	if (!duplicate) // If the malloc failed to allocate memory then, return NULL
		return (NULL);
	gnl_strcpy(duplicate, str, 0); // Make a complete copy of str in duplicate
	return (duplicate);
}
```

<br><h5>FT_SUBSTR</h5>

```c
/**
 * @brief This function is intended to create a substring from a given one.
 * @details After checking that both start and len are correct and, we now
 * know how much memory it is going to need the new substr. So we proceed to 
 * allocate just enogh memory for it and check that the allocation worked.
 * Finally we use the gnl_strcpy function with substr (as dest), str + start
 * (as src, so it starts to copy from the correct position) and len + 1 (as len,
 * to take into account the while --len of the gnl_strcpy).
 * Examples: ft_susbtr("Hello how are you", 6, 100) -> "how are you"
 * 			ft_susbtr("Hello how are you", 0, 4) -> "Hello"
 * 			ft_susbtr("Hello how are you", 100, 4) -> ""
 * @param str String to create the substring from
 * @param start Starting porint from which to start the substring
 * @param len Maximum length of the new substring
 * @retval substr <- Succesfully copied string
 * @retval ft_strdup("") <- First we check that the starting point is correct,
 * if it is not, we return an allocated empty string.
 * @retval NULL <- If the substr allocation fails
 * @warning Remember to check that the given len is correct and is not too big.
 * If it is too big we simply update len to reach the end of the str from start
 * by doing: len = ft_strlen(str) - start.
 * 
*/
char	*ft_substr(char *str, int start, int len)
{
	char	*substr; // Create a new string called substr

	if (start >= ft_strlen(str)) // If the starting possition is not possible
		return (NULL);
	substr = malloc(len + 1); // Allocate memory for creating the substring 
	if (!substr) // If the malloc failed to allocate memory then, return NULÑ
		return (NULL);
	gnl_strcpy(substr, str + start, len + 1); // Create a copy of str starting from the position start (str[start] with a maximum length of len + 1)
	return (substr);
}

char *usage_example(void)
{
	char	*sub;

	sub = ft_substr("Hello how are you?", 6, 100); // sub = "how are you?"
	free_str(&sub);
	sub = ft_substr("Hello how are you?", 0, 4); // sub = "Hell"
	free_str(&sub);
	sub = ft_substr("Hello how are you?", 100, 4); // sub = NULL
	free_str(&sub);
}
```

<br><h5>GNL_STRCHR</h5>

```c
/**
 * @brief This function looks for a certain value inside a string. 
 * @details If the value isn't found, it returns 0, if it finds it, it returns
 * its position + 1. Since we are only going to use it to find '\n', we dont 
 * need extra comprobations like the fact of looking for a '\0'. We return an 
 * extra position because we only use this function to check if is != 0 or to 
 * receive the position of '\n' in order to create a new substring from the 
 * beginning to the '\n' (included) or from the '\n' (not included) to the end.
 * In order to achieve this, we need that extra position so we can use the 
 * substr directly with the result of this function (see get_result_buffer())
 * @param s String to iterate
 * @param c Value to look for inside s (will always be '\n')
 * @retval 0 <- if s is empty/doesn't exist or if the value isn't found in s
 * @retval ++i <- Position where c is found in s + 1
 * @warning Remember that this function is simpler than the original strchr
 * since it returns a type int, it returns an extra position and it doesn't 
 * work in cases like c = '\0'.
*/
int	gnl_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str && str[++i]) // Checks that str exists and that you didn´t reach the end of it
	{
		if (str[i] == c) // if the character you are looking for is the same so are comparing
			return (++i); // return an extra position of where you found such character
	}
	return (0); // if str didn´t exist or the character wasn´t found, return 0
}

char *usage_example(void)
{
	int position;

	position = gnl_strchr("hola", '\n'); // position = 0
	position = gnl_strchr("\nhola", '\n'); // position = 1
	position = gnl_strchr(NULL, '\n'); // position = 0
	position = gnl_strchr("hol\na", '\n'); // position = 4
}
```

<br><h5>GNL_STRJOIN</h5>

```c
/**
 * @brief This function creates a new string resulting from the concatenation
 * of s1 and s2
 * @details First of all this function calculates how much memory the new string
 * is going to occupy. Then it allocates enough memory for it and checks that
 * the allocation worked as expected. Afterwards, it copies s1 into join (new
 * string). Then it concatenates the s2 into join (from where it left off).
 * Finally, it frees the s1 string and returns the resulting join.
 * @param s1 First string to add to the new string
 * @param s2 Second string to concatenate to the new string
 * @retval NULL <- When the allocation for the new string fails (first frees s1)
 * @retval join <- Returns the newly created string
 * @warning This function varies from the original one since it doesn´t check
 * that s1 exists (whoever calls it must make sure s1 exists first) and this
 * function is also resposible of freeing s1, since it assumes that the returned
 * string will be assigned to s1. Example: buffer = gnl_strjoin(buffer, addbuf);
 * 
*/
char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join; // Creates a new string called join

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1); // Allocates enough memory for having the concatenation of s1 and s2 in it
	if (!join) // Protects malloc
		return (free_str(&s1)); // Frees the s1 string if malloc failed and return NULL
	gnl_strcpy(join, s1, 0); // Copies the s1 string into join
	gnl_strcpy(join + ft_strlen(s1), s2, 0); // Copies the s2 string into join from the position it left off after copying s1
	return (free_str(&s1), join); // frees s1 and returns the new string
}

char *usage_example(void)
{
	char	*concat;

	concat = ft_strdup("hello"); // concat = "hello"
	concat = ft_strjoin(concat, " everyone") // concat = "hello everyone"
	concat = ft_strjoin(concat, "!") // concat = "hello everyone!"
}
```

<br><h5>GET_RESULT__BUFFER</h5>

```c
/**
 * @brief This function is intended to get the resulting line that the
 * get_next_line function must finally return and also update the buffer
 * by deleting the resulting line from it.
 * @details First of all, the function creates a duplicate of *buffer, stores it 
 * in temp and frees buffer, that way we can calmly get the resulting line and
 * update buffer without leak preoccupations. We check that the duplicate was
 * created succesfully (or return NULL).
 * Now we assign the result of searching for a new line in the original buffer
 * (actual temp) in nl_pos (nl_pos = gnl_strchr(temp, '\n'))
 * Now, we check if there nl_pos is 0, which means that temp didn't contain any
 * new line. If it is 0, the resulting line will be the duplicate of the whole 
 * buffer (temp), so the new buffer will be empty (free temp) and finally we 
 * return the result (which is the resulting line). 
 * If there was a new line stored in the buffer (temp) (nl_pos != 0), we create
 * a substring of the old buffer (temp), from the beggining (0),
 * to the included nl_pos. After creating the substr we check that it was
 * created succesfully (otherwise we free temp and return NULL). 
 * We now update the new buffer to the correct one (deleting the resulting line
 * from the old buffer (temp)). To do that, we create a new substr of the old 
 * buffer (temp), from the '\n' (not included) (nl_pos) to the end of the old
 * buffer (ft_strlen(temp) - nl_pos). 
 * Now we can free temp since we have already updated the new buffer and then 
 * we check if the new buffer was created succesfully or not, if not, we free 
 * the new buffer.
 * Finally, we return the resulting line.
 * @param buffer Pointer to the static buffer variable
 * @retval NULL <- When any of the allocations for the string fails (making sure
 * to free any necessary variables first)
 * @retval result Resulting line that the get_next_line function must finally
 * return, calculated from the buffer passed as argument. 
 * @warning Each time that the variable buffer is used, remember that it is the
 * pointer to the string (char **buffer), this is because we need the original
 * buffer variable (from the get_next_line function), to be updated without 
 * assigning its value in the main function get_next_line.
*/
char	*get_result_buffer(char **buffer)
{
	char	*temp; // Creates a new string called temp (for temporary)
	char	*result; // Creates a new string which will be the line to return
	int		nl_pos; // Creates a new int which will be the position of the next '\n'

	temp = ft_strdup(*buffer); // Creates a duplicate of the buffer pointer
	free_str(buffer); // Frees the string that buffer is pointing to
	if (!temp) // Checks that temp was created succesfully
		return (NULL);
	nl_pos = gnl_strchr(temp, '\n'); // Assigns it the next position of '\n' in temp
	if (!nl_pos) // If no new line was found in temp
	{
		result = ft_strdup(temp); // The resulting line will be the lefts of temp
		return (free_str(&temp), result); // Free temp and return the resulting line
	}
	result = ft_substr(temp, 0, nl_pos); // Create a substring from the beginning of the buffer (temp) to the position where the new line is at (included)
	if (!result) // If the substring failed
		return (free_str(&temp)); // Free temp and return NULL
	*buffer = ft_substr(temp, nl_pos, ft_strlen(temp) - nl_pos); // Updates the new buffer pointer to be the old one (temp) exctracting the resulting line in result
	if (!*buffer) // If the buffer substr wasn´t made succesfully, free buffer
		free_str(buffer);
	return (free_str(&temp), result); // Free the temporary string and return the new line (result)
}

```

<br><h5>ADD_BUFFER</h5>

```c
/**
 * @brief This function is made to read from the indicated fd and adding to the
 * buffer the read information by concatenating to the buffer itself.
 * @details First of all the function creates a new string called addbuf and
 * allocates BUFFER_SIZE + 1 memory to it. If the allocation fails, it frees the
 * original buffer and returns NULL. 
 * Then it assigns b_read to 1, which will represent the num of bytes read when 
 * using the read function. It starts from 1 in order to enter the while loop. 
 * The function will now run in loop until there is no more information to read 
 * in the fd (b_read = 0), the read fails (b_read == -1) or a '\n' is finally 
 * found inside buffer (gnl_strchr(buffer, '\n') != 0).
 * Inside the while loop we are going to start reading the indicated file
 * descriptor (reading BUFFER_SIZE characters in each call) and adding the read
 * information to addbuf (read(fd, addbuf, BUFFER_SIZE)). The function read
 * returns the number of characters read, which is why we are going to assing
 * its result to b_read. If it returns -1, it means there was an error during
 * the read call, which is why in such case we free both strings and return NULL
 * If the read called worked successfully, we add the '\0' character to the end
 * of addbuf in order to indicate the end of such string.
 * Now we can finally check that if something was read (b_read > 0) and the 
 * original buffer was empty (didnt exist: !buffer), then the new buffer will
 * be a duplicate of addbuf. If otherwise, there was something read (b_read > 0)
 * but buffer previously existed, then we concatenate addbuf to buffer by 
 * assigning doing: buffer = gnl_strjoin(buffer, addbuf).
 * This while loop will continuously repeat until one of its conditions isn't met
 * After the while loop, it finally frees addbuf and returns buffer.
 * @param buffer Buffer that needs to be updated during this function
 * @param fd File descriptor from which the function must read in order
 * to update the buffer
 * @retval NULL <- When the allocation of addbuf fails
 * @retval buffer <- Updated buffer
 * @warning Make sure to free buffer if the allocation of addbuf fails or
 * if the read function fails. Also make sure to free addbuf before returning
 * any value if you have succesfully allocated memory for it before.
 *  
*/
char	*add_buffer(char *buffer, int fd)
{
	char	*addbuf; // Creates a new string called addbuf (new buffer to concatenate to buffer)
	int		b_read; // number of bytes read when using the read function

	addbuf = malloc(BUFFER_SIZE + 1); // Allocate memory for the addbuf string with size BUFFER_SIZE + 1, because we are going to read BUFFER_SIZE characters each time we call the read function (+ 1 for the NULL character after each read)
	if (!addbuf) // Protect the malloc
		return (free_str(&buffer)); // If malloc failed, free old buffer and return NULL
	b_read = 1; // Assign b_read to 1 so it enters the while the first time
	while (b_read > 0 && !gnl_strchr(buffer, '\n')) // While the bytes read from the file is positive (means you didn´t finished reading the file) and while there is no new line found inside buffer then...
	{
		b_read = read(fd, addbuf, BUFFER_SIZE); // assign b_read to be the number of bytes read when calling the read function. We are telling the read function to read from the given file descriptor (fd), that the read information must be saved into the addbuf string and that it should read a maximum of BUFFER_SIZE characters
		if (b_read < 0) // if b_read is negative is because the read function failed
			return (free_str(&addbuf), free_str(&buffer)); // in this case, we need to free both strings (buffer and addbuf) and return NULL
		addbuf[b_read] = '\0'; // Indicate that the end of the string addbuf is at addbuf[b_read]
		if (!buffer && b_read > 0) // If buffer didn´t contain any information previously and there was at least one byte that was read when calling the read function, then:
			buffer = ft_strdup(addbuf); // The buffer will be a duplicate of the addbuf. Since buffer was empty/didn't exist, we dont need to concatenate anything, simply make a duplicate of what we want to add to the buffer
		else if (b_read > 0) // If otherwise buffer wasn´t empty but we still read something from the given file then:
			buffer = gnl_strjoin(buffer, addbuf); // concatenate the addbuf string that has the newly read characters, into the buffer
	}
	return (free_str(&addbuf), buffer); // free the addbuf string and return the new buffer
}

```

<br><h5>GET_NEXT_LINE</h5>

```c
/**
 * @brief This function reads from BUFFER_SIZE in BUFFER_SIZE characters a given
 * file descriptor (fd) and returns the next line from such file (a line
 * is considered to be finished by a '\n' or the end of the file). The function
 * will keeps on from the last time it was called, so if the function was called
 * 2 times before, it will now return the third line from the given file.
 * If the end of the file is reached it returns NULL. 
 * @details This functions first checks that the given fd is correct (fd > 0) and
 * that the BUFFER_SIZE is correct too (BUFFER_SIZE > 0), if one of them isn't,
 * it returns NULL. 
 * If the buffer is empty/doesn't exist (usually happens on the first call of the
 * function or when the whole fd was already read and returned) or if the buffer
 * doens't contain a new line (!gnl_strchr(buffer, '\n')), then we try to update
 * the buffer by reading and adding more information to it by using using the
 * add_buffer function. If there was an error during the add_buffer function
 * and buffer keeps being empty (doesn't exist (!buffer)), then we return NULL (
 * this happens for example if we had already reach the end of the file, and we 
 * don´t have any other information to add to buffer). If otherwise, the buffer
 * does exist, then we return the next line and update the new buffer by calling
 * return (get_result_buffer(&buffer)). This return will also update the buffer,
 * because we are passing the pointer of buffer to the get_result_buffer function
 * @retval NULL <- fd/BUFFER_SIZE incorrect or if buffer keeps not existing after
 * trying to add information to it
 * @retval get_result_buffer(&buffer) Returns the next line of buffer and
 * deletes it from buffer (see get_result_buffer function).
*/
char	*get_next_line(int fd)
{
	static char	*buffer; // Create the static variable that will containe all the read lines/characters from the given file but that still hasn´t been returned as next lines

	if (fd < 0 || BUFFER_SIZE <= 0) // Check that the fd and BUFFER_SIZE are correct
		return (NULL);
	if (!buffer || !gnl_strchr(buffer, '\n')) // If buffer is empty/doesn't exist or if there is no new line to be found inside buffer, then...
		buffer = add_buffer(buffer, fd); // Update the buffer
	if (!buffer) // If after trying to update the buffer, we still don´t manage to have anything inside buffer, then return NULL
		return (NULL);
	return (get_result_buffer(&buffer)); // Return the next line of buffer and update the buffer by deleting from it the line to be returned
}

```

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
