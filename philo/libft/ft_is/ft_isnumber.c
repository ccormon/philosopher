/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:23:42 by ccormon           #+#    #+#             */
/*   Updated: 2024/05/09 16:27:32 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool	ft_isnumber(char *s)
{
	size_t	i;

	if (!s || !(*s))
		return (false);
	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (false);
	return (true);
}
