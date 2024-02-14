/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:34 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 13:45:42 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	ssize_t	len;

	if (str == NULL)
		len = write(1, "(null)", 6);
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}
