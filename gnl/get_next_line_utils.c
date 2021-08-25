/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:00:05 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/26 10:39:25 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	src = (unsigned char *) source;
	dest = (unsigned char *) destination;
	while (num > i)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	if (destination == NULL && source == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)destination;
	src = (const unsigned char *)source;
	if (dest > src)
	{
		while (num--)
			dest[num] = src[num];
	}
	else if (dest < src)
		ft_memcpy(dest, src, num);
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dst;

	size = ft_strlen((char *)src) + 1;
	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	s1_size;
	size_t	s2_size;
	size_t	total_size;
	size_t	i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (0);
	s1_size = ft_strlen((char *)s1);
	s2_size = ft_strlen((char *)s2);
	total_size = s1_size + s2_size;
	array = malloc((total_size) + 1);
	if (!array)
		return (0);
	ft_memmove(array, s1, s1_size);
	ft_memmove(array + s1_size, s2, s2_size);
	array[total_size] = '\0';
	free((char *)s1);
	return (array);
}
