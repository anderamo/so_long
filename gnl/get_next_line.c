/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:49:29 by aamorin-          #+#    #+#             */
/*   Updated: 2021/07/24 14:08:05 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save(char *text)
{
	int		i;
	int		j;
	char	*str2;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str2 = malloc((i + 1) * ((ft_strlen(text) - i) + 1));
	i++;
	j = 0;
	while (text[i])
		str2[j++] = text[i++];
	str2[j] = '\0';
	free(text);
	return (str2);
}

int	ft_EOF(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file_line(char *str)
{
	int		c_position;
	char	*str2;

	if (!str || str[0] == '\0')
		return (NULL);
	c_position = 0;
	while (str[c_position] && str[c_position] != '\n')
		c_position++;
	c_position++;
	str2 = malloc((c_position + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	c_position = 0;
	while (str[c_position] && str[c_position] != '\n')
	{
		str2[c_position] = str[c_position];
		c_position++;
	}
	if (str[c_position] == '\n')
		str2[c_position++] = '\n';
	str2[c_position] = '\0';
	return (str2);
}

char	*free_and_null(char *buf)
{
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	int			size;
	static char	*text;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (size != 0 && ft_EOF(text) == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (free_and_null(buf));
		buf[size] = '\0';
		text = ft_strjoin(text, buf);
	}
	free(buf);
	line = read_file_line(text);
	text = ft_save(text);
	return (line);
}
