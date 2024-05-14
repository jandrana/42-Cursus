/*

Files expected: get_next_line.c get_next_line.h

*/

#include "get_next_line.h"

char	*free_str(char **p_str)
{
	free(*p_str);
	*p_str = NULL;
	return (*p_str);
}

int	ft_strlen(char *str)
{
	int	i = -1;

	while (str[++i]);
	return (i);
}

void	gnl_strcpy(char *dst, char *src, int len)
{
	while (*src && --len)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(char *str)
{
	char	*duplicate;

	duplicate = malloc(ft_strlen(str) + 1);
	if (!duplicate)
		return (NULL);
	gnl_strcpy(duplicate, str, 0);
	return (duplicate);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*substr;

	if (start >= ft_strlen(str))
		return (NULL);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	gnl_strcpy(substr, str + start, len + 1);
	return (substr);
}

int	gnl_strchr(char *str, int c)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == c)
			return (++i);
	}
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (free_str(&s1));
	gnl_strcpy(join, s1, 0);
	gnl_strcpy(join + ft_strlen(s1), s2, 0);
	return (free_str(&s1), join);
}

char	*get_result_buffer(char **buffer)
{
	char	*temp;
	char	*result;
	int		nl_pos;

	temp = ft_strdup(*buffer);
	free_str(buffer);
	if (!temp)
		return (NULL);
	nl_pos = gnl_strchr(temp, '\n');
	if (!nl_pos)
	{
		result = ft_strdup(temp);
		return (free_str(&temp), result);
	}
	result = ft_substr(temp, 0, nl_pos);
	if (!result)
		return (free_str(&temp));
	*buffer = ft_substr(temp, nl_pos, ft_strlen(temp) - nl_pos);
	if (!*buffer)
		free_str(buffer);
	return (free_str(&temp), result);
}

char	*add_buffer(char *buffer, int fd)
{
	char	*addbuf;
	int		b_read;

	addbuf = malloc(BUFFER_SIZE + 1);
	if (!addbuf)
		return (free_str(&buffer));
	b_read = 1;
	while (b_read > 0 && !gnl_strchr(buffer, '\n'))
	{
		b_read = read(fd, addbuf, BUFFER_SIZE);
		if (b_read < 0)
			return (free_str(&addbuf), free_str(&buffer));
		addbuf[b_read] = '\0';
		if (!buffer && b_read > 0)
			buffer = ft_strdup(addbuf);
		else if (b_read > 0)
			buffer = gnl_strjoin(buffer, addbuf);
	}
	return (free_str(&addbuf), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !gnl_strchr(buffer, '\n'))
		buffer = add_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	return (get_result_buffer(&buffer));
}
