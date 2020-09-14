/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:41:44 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 23:03:48 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

# define FLAG_MINUS	0
# define FLAG_PLUS	1
# define FLAG_SPACE 2
# define FLAG_SHARP	4
# define FLAG_ZERO	8
# define FLAG_WILDCARD 16
# define FLAG_UPCASE 32
# define FLAG_PRECISION 64
# define FLAG_POINTER 128
# define FLAG_L 256
# define FLAG_LL 512
# define FLAG_S 1024
# define FLAG_SS 2048

typedef struct		s_printf
{
	int				len;
	uint8_t			base;
	short			f;
	int				min_length;
	int				precision;
	int				padding;
	int				printed;
	int				fd;
	va_list			args;
	char			*format;
	unsigned int	c;
	int				i;
	int				n;
}					t_printf;

typedef void		(*t_func_pointer)(t_printf*);

void				print_nb(t_printf *p);
void				print_nb_base(t_printf *p);
void				print_char(t_printf *p);
void				print_str(t_printf *p);
void				print_pointer(t_printf *p);
void				print_percent(t_printf *p);
void				print_wchar(t_printf *p, unsigned int n,
						unsigned int len, unsigned int bytes);
int					ft_printf(const char *format, ...);
void				padding(t_printf *p, int n);
void				parse_options(t_printf *p);
void				itoa_base_printf(uintmax_t n, int base, t_printf *p);
uint8_t				base_to_num(char c);

#endif
