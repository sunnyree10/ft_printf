/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:34:10 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 19:03:49 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
