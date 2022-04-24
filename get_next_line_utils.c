/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuseiikeda <yuseiikeda@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:29:58 by yuseiikeda        #+#    #+#             */
/*   Updated: 2022/04/24 12:51:51 by yuseiikeda       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (total + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[1];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i]  = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)s)[i++] = 0;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*tmp;
	size_t	bytes;

	if (n == 0 || size == 0)
		return (ft_calloc(1, 1));
	tmp = malloc(n * size);
	if (!tmp)
		return (NULL);
	bytes = n * size;
	if (bytes / size != n)
		return (NULL);
	ft_bzero(tmp, n * size);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
