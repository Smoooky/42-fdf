#include "../includes/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	i = 0;
	j = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 == NULL || s2 == NULL || ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	ch = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == ch)
	{
		return ((char *) &s[i]);
	}
	else
	{
		return (NULL);
	}
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	len;

	p = NULL;
	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p != NULL)
	{
		while (i != len)
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = s1[i];
		return (p);
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	register const char	*s = NULL;

	s = str;
	while (*s)
		++s;
	return (s - str);
}
