/*

Files expected: get_next_line.c get_next_line.h

*/

#include "get_next_line.h"

char	*free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (s[++i])
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	i;

	s_len = (unsigned int)ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

int	gnl_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (++i);
	}
	return (0);
}

char	*gnl_strjoin(const char *s1, char *s2)
{
	char	*join;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	i = s1_len + s2_len;
	join = (char *)malloc(sizeof(char) * i + 1);
	if (!join)
		return (free_str((char **)(&s1)));
	i = -1;
	while (++i < s1_len)
		join[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		join[i + s1_len] = s2[i];
	join[i + s1_len] = '\0';
	free_str((char **)(&s1));
	return (join);
}

char	*get_result_buffer(char **buffer)
{
	char	*result;
	char	*temp;
	int		nl_pos;

	temp = ft_strdup(*buffer);
	free_str(buffer);
	if (!temp)
		return (NULL);
	if (!gnl_strchr(temp, '\n'))
	{
		result = ft_strdup(temp);
		free_str(&temp);
		return (result);
	}
	nl_pos = gnl_strchr(temp, '\n');
	result = ft_substr(temp, 0, nl_pos);
	if (!result)
		return (free_str(&temp));
	*buffer = ft_substr(temp, nl_pos, ft_strlen(temp) - nl_pos);
	free_str(&temp);
	if (!*buffer || !*buffer[0])
		free_str(buffer);
	return (result);
}

char	*add_buffer(char *buffer, int fd)
{
	char	*addbuf;
	int		b_read;

	addbuf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
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
	free_str(&addbuf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer || !gnl_strchr(buffer, '\n'))
		buffer = add_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	return (get_result_buffer(&buffer));
}
