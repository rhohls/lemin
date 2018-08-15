/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:09:40 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/01 08:56:10 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

// static int	ft_strlen_del(char *str, char c)
// {
// 	int len;

// 	len = 0;
// 	while (str[len] != '\0' && str[len] != c)
// 	{
// 		len++;
// 	}
// 	if (len == 0)
// 		len++;
// 	return (len);
// }

// static int	ft_num_str(char *str, char c)
// {
// 	int numstr;
// 	int i;

// 	i = 0;
// 	numstr = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
// 			numstr++;
// 		i++;
// 	}
// 	return (numstr);
// }

// /*
// ** index[0] is for string
// ** index[1] is for array
// */

// char		**ft_strsplit(char const *str, char c)
// {
// 	char	**str_array;
// 	int		numstr;
// 	int		curr_strlen;
// 	int		index[2];

// 	index[0] = 0;
// 	index[1] = 0;
// 	if (!str)
// 		return (NULL);
// 	numstr = ft_num_str((char *)str, c);
// 	if (!(str_array = (char **)ft_memalloc(sizeof(char*) * (numstr + 1))))
// 		return (NULL);
// 	str_array[numstr + 1] = ((void *)0);
// 	while (str[index[0]] == c)
// 		index[0]++;
// 	while (numstr-- > 0)
// 	{
// 		curr_strlen = ft_strlen_del((char *)(&str[index[0]]), c);
// 		str_array[index[1]] = ft_strsub(str, index[0], curr_strlen);
// 		index[0] += curr_strlen;
// 		while (str[index[0]] == c)
// 			index[0]++;
// 		index[1]++;
// 	}
// 	return (str_array);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:05 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/21 08:19:06 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

static size_t	word_count(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	count = 0;
	tmp = s;
	while (*tmp != '\0')
	{
		while (*tmp == c && *tmp != '\0')
			tmp++;
		while (*tmp != c && *tmp != '\0')
			tmp++;
		if (*(tmp - 1) != c)
			count++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	char const	*tmp;
	size_t		count;

	tmp = s;
	count = 0;
	while (*tmp != c && *tmp != '\0')
	{
		tmp++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	char const	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	if ((ret = (char **)malloc(sizeof(char *) * word_count(s, c) + 1)) != NULL)
	{
		i = 0;
		while (i < word_count(s, c))
		{
			while (*tmp == c && *tmp != '\0')
				tmp++;
			ret[i] = (char *)malloc(sizeof(char) * word_len(tmp, c) + 1);
			j = 0;
			while (*tmp != c && *tmp != '\0')
				ret[i][j++] = *tmp++;
			ret[i++][j] = '\0';
		}
		ret[i] = NULL;
	}
	return (ret);
}