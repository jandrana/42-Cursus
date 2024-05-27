/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:53:56 by ana-cast          #+#    #+#             */
/*   Updated: 2024/05/14 20:27:29 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

# include <stdlib.h>
# include <unistd.h>

char	*free_str(char **p_str);
int		ft_strlen(char *str);
void	gnl_strcpy(char *dst, char *src, int len);
char	*ft_strdup(char *str);
char	*ft_substr(char *str, int start, int len);
int		gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_result_buffer(char **buffer);
char	*add_buffer(char *buffer, int fd);
char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */