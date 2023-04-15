/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_man.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim3 <jkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:59:41 by heson             #+#    #+#             */
/*   Updated: 2023/03/15 17:39:20 by jkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	tmp_i;
	const char		*tmp2;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] && *needle)
	{
		if (haystack[i] == *needle)
		{
			tmp_i = i;
			tmp2 = needle;
			while (tmp_i < len && haystack[tmp_i]
				&& *tmp2 && haystack[tmp_i] == *tmp2)
			{
				tmp_i++;
				tmp2++;
			}
			if (!*tmp2)
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (0);
}
