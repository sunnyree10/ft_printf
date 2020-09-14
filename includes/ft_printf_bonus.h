/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:41:44 by suntlee           #+#    #+#             */
/*   Updated: 2020/07/17 15:41:44 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>

# define FLAG_MINUS	(1 << 0)
# define FLAG_PLUS	(1 << 1)
# define FLAG_SPACE	(1 << 2)
# define FLAG_SHARP	(1 << 3)
# define FLAG_ZERO	(1 << 4)
# define FLAG_WILDCARD (1 << 5)
# define FLAG_UPCASE (1 << 6)
# define FLAG_PRECISION (1 << 7)
# define FLAG_POINTER (1 << 8)
# define FLAG_L (1 << 9)
# define FLAG_LL (1 << 10)
# define FLAG_S (1 << 11)
# define FLAG_SS (1 << 12)

typedef struct	s_printf
{
	int			len;

	uint8_t		base;
	short		f;
	int			min_length;
	int			precision;
	int			padding;
	int			printed;
	int			fd;
	va_list		args;
	char		*format;
	unsigned int	c;
	int			i;
	int			n;
}				t_printf;

typedef void (*funcPointer)(t_printf*);

void	print_nb(t_printf *p);
void	print_nb_base(t_printf *p);
void	print_char(t_printf *p);
void	print_str(t_printf *p);
void 	print_pointer(t_printf *p);
void	print_percent(t_printf *p);
void	print_wchar(t_printf *p, unsigned int n,
						unsigned int len, unsigned int bytes);
int		ft_printf(const char *format, ...);
void	padding(t_printf *p, int n);
void	parse_options(t_printf *p);
void	itoa_base_printf(uintmax_t n, int base, t_printf *p);
uint8_t	base_to_num(char c);

#endif