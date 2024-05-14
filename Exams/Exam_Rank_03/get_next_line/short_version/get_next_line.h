/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:53:56 by ana-cast          #+#    #+#             */
/*   Updated: 2024/05/14 16:39:43 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <stdlib.h>
# include <unistd.h>

/**
 * @brief This function is intended to free the pointer of the
 * string str making sure that it has no leaks by freeing the pointer
 * to the string instead of the string itself
 * @param str Pointer to the string that is going to be freed
 * @return The function returns NULL since in most cases, when this
 * function is used, you also need to return NULL.
 * 
*/
char	*free_str(char **p_str);

/**
 * @brief This function calculates the length of the string passed
 * as argument. (Since this was for an exam, I did not take into account 
 * the norminette restrictions)
 * @param str string to iterate
 * @return The function returns the calculated length of the string.
 * 
*/
int		ft_strlen(char *str);

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
void	gnl_strcpy(char *dst, char *src, int len);

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
char	*ft_strdup(char *str);

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
char	*ft_substr(char *str, int start, int len);

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
int		gnl_strchr(char *str, int c);

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
char	*gnl_strjoin(char *s1, char *s2);

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
char	*get_result_buffer(char **buffer);

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
char	*add_buffer(char *buffer, int fd);

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
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */