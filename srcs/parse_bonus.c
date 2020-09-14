/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:27:08 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 22:23:24 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *p)
{
	while ((p->n = ft_strchr_index("-+ #0*", *p->format)) > -1 && ++p->format)
		p->f |= (1 << p->n);
	(p->f & FLAG_MINUS) ? p->f &= ~FLAG_ZERO : 0;
	(p->f & FLAG_PLUS) ? p->f &= ~FLAG_SPACE : 0;
	if (p->f & FLAG_WILDCARD)
	{
		p->f &= ~FLAG_WILDCARD;
		if ((p->n = (int)va_arg(p->args, int)) < 0)
		{
			p->f |= FLAG_MINUS;
			p->f &= ~FLAG_ZERO;
		}
		if (!(p->f & FLAG_PRECISION))
			p->min_length = p->n < 0 ? -p->n : p->n;
		else
		{
			p->precision = p->n < 0 ? 0 : p->n;
			p->f = p->n < 0 ? p->f & ~FLAG_PRECISION : p->f;
		}
	}
}

static void	parse_width_precision(t_printf *p)
{
	if (*p->format >= '0' && *p->format <= '9')
		p->min_length = ft_max(ft_atoi_parse(&p->format), 1);
	if (*p->format == '.')
	{
		++p->format;
		p->precision = ft_max(ft_atoi_parse(&p->format), 0);
		p->f |= FLAG_PRECISION;
		p->f &= ~FLAG_ZERO;
	}
	while (1)
	{
		if (*p->format == 'l')
			p->f |= (p->format[1] == 'l' && ++p->format) ? FLAG_LL : FLAG_L;
		else if (*p->format == 'h')
			p->f |= (p->format[1] == 'h' && ++p->format) ? FLAG_SS : FLAG_S;
		else
			break ;
		++p->format;
	}
}

static void	init_fp_arr(funcPointer fp_arr[])
{
	fp_arr['d'] = &print_nb;
	fp_arr['i'] = &print_nb;
	fp_arr['o'] = &print_nb_base;
	fp_arr['u'] = &print_nb_base;
	fp_arr['x'] = &print_nb_base;
	fp_arr['X'] = &print_nb_base;
	fp_arr['s'] = &print_str;
	fp_arr['c'] = &print_char;
	fp_arr['p'] = &print_pointer;
	fp_arr['%'] = &print_percent;
}

static void	parse_conversion_specifier(t_printf *p)
{
	funcPointer	f[256];

	if (ft_strchr_index("csdiouxXp%", p->c) == -1)
	{
		p->len = -1;
		return ;
	}
	init_fp_arr(f);
	if (p->c == 'X')
		p->f |= FLAG_UPCASE;
	p->base = base_to_num(p->c);
	f[p->c](p);
}

void		parse_options(t_printf *p)
{
	p->f = 0;
	p->min_length = 0;
	p->precision = 0;
	parse_flags(p);
	parse_width_precision(p);
	parse_flags(p);
	p->c = *p->format;
	parse_conversion_specifier(p);
}
