/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:56:24 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 22:29:01 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_wstrlen(wchar_t *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlen((wint_t)(*s));
		++s;
	}
	return (len);
}
