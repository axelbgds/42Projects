/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:53:32 by tde-los-          #+#    #+#             */
/*   Updated: 2023/03/01 13:48:42 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_check(const char c, va_list ap);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned int n, char c);
int	ft_pointer(unsigned long long nb, int start);

#endif
